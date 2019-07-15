#include "ClickHandler.h"

#include "Grid.h"
#include "dataStructures/SequenceInfo.h"

ClickHandler::ClickHandler()
{
}

void ClickHandler::StoneClicked(Stone& clickedStone, Grid& grid)
{
	if (stoneIsSelected)
	{
		if (grid.AreStonesAdjacent(firstClickedStone, clickedStone))
		{
			grid.SwapStonesAndCheckForSequences(firstClickedStone, clickedStone);
		}
		ResetFirstClickedStone();
	}
	else
	{
		firstClickedStone = clickedStone;
		stoneIsSelected = true;
	}
}

void ClickHandler::ClickedOutsideTheGrid()
{
	ResetFirstClickedStone();
}

bool ClickHandler::WasSecondClickAdjacentToFirst(Stone& secondClickedStone)
{
	return firstClickedStone.IsAdjacentTo(secondClickedStone);
}

ClickHandler::~ClickHandler()
{
}

void ClickHandler::ResetFirstClickedStone()
{
	stoneIsSelected = false;
}



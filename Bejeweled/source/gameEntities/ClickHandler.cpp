#include "ClickHandler.h"

#include "Grid.h"
#include "dataStructures/SequenceInfo.h"

ClickHandler::ClickHandler()
{
}

void ClickHandler::StoneClicked(Stone& clickedStone, Grid& grid)
{
	printf("type of clicked stone: %d.\n", clickedStone.GetStoneType());
	if (stoneIsSelected)
	{
		if (grid.AreStonesAdjacent(firstClickedStone, clickedStone))
		{
			printf("clicked ADJACENT of type %d.\n", clickedStone.GetStoneType());
			grid.SwapStonesAndCheckForSequences(firstClickedStone, clickedStone);
		}
		else
		{
			printf("clicked NON ADJACENT of type %d.\n", clickedStone.GetStoneType());
		}
		ResetFirstClickedStone();
	}
	else
	{
		firstClickedStone = clickedStone;
		printf("clicked NEW STONE of type %d.\n", firstClickedStone.GetStoneType());
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
	printf("first click reset.\n");
	stoneIsSelected = false;
}



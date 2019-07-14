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
		if (WasSecondClickAdjacentToFirst(clickedStone))
		{
			printf("clicked ADJACENT of type %d.\n", clickedStone.GetStoneType());
			SequenceInfo possibleSequence = grid.StoneSwapSuccesful(firstClickedStone, clickedStone);
			if (possibleSequence.IsSequence())
			{
				// grid.ConfirmSwap(firstClickedStone, clickedStone);
				grid.UpdateStonesInGrid(possibleSequence);
				// grid.GenerateNewStones();
			}
			//clickedStone.UpdateSpritePosition(SwapDirection::up);
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



#include "ClickHandler.h"

#include "Stone.h"

ClickHandler::ClickHandler()
{
}

void ClickHandler::StoneClicked(Stone& clickedStone)
{
	printf("type of clicked stone: %d.\n", clickedStone.GetStoneType());
	if (firstClickedStone != nullptr)
	{
		if (WasSecondClickAdjacentToFirst(clickedStone))
		{

		}
	}
	else
	{
		firstClickedStone = &clickedStone;
		printf("clicked non adjacent of type %d.\n", firstClickedStone->GetStoneType());
	}
}

void ClickHandler::ClickedOutsideTheGrid()
{
	ResetFirstClickedStone();
}

bool ClickHandler::WasSecondClickAdjacentToFirst(Stone& secondClickedStone)
{
	return firstClickedStone->IsAdjacentTo(secondClickedStone);
}

ClickHandler::~ClickHandler()
{
	delete firstClickedStone;
}

void ClickHandler::ResetFirstClickedStone()
{
	printf("first click reset.\n");
	firstClickedStone = nullptr;
}



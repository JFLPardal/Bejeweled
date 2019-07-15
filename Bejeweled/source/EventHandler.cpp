
#include "preCompiledHeader.h"

#include "EventHandler.h"
#include "Game.h"
#include "gameEntities/Grid.h"
#include "gameEntities/ClickHandler.h"
#include "UtilityFunctions.h"

EventHandler::EventHandler()
{
}

void EventHandler::CheckForEvents(Grid& grid, ClickHandler& clickHandler)
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		Game::QuitGame();
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (UtilityFunctions::IsInsideOf(event.motion, grid.GetGridRect()))
		{
			Stone clickedStone = grid.GridClicked(event);
			clickHandler.StoneClicked(clickedStone, grid);
		}
		else
		{
			clickHandler.ClickedOutsideTheGrid();
		}
		break;
	default:
		break;
	}
}

#include "preCompiledHeader.h"

#include "EventHandler.h"
#include "gameEntities/Grid.h"
#include "gameEntities/ClickHandler.h"
#include "UtilityFunctions.h"

enum EventQueueState { Empty = 0, EventsPending = 1 };

EventHandler::EventHandler()
{
}

// this function checks for pending events once per frame
void EventHandler::CheckForEvents(Grid& grid, ClickHandler& clickHandler)
{
	SDL_Event event; 
	SDL_PollEvent(&event);
	/*while (SDL_PollEvent(&event) != 0)//EventQueueState::EventsPending)
	{*/
		switch (event.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			std::cout << "event" << std::endl;
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
		}/*
		if (eventType == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
		{
			std::cout << "event" << std::endl;
			if (UtilityFunctions::IsInsideOf(event.motion, grid.GetGridRect()))
			{
				Stone clickedStone = grid.GridClicked(event);
				clickHandler.StoneClicked(clickedStone);
			}
			else
			{
				clickHandler.ClickedOutsideTheGrid();
			}
		}
		if (eventType == SDL_EventType::SDL_MOUSEMOTION)
		{
			if (event.motion.x > 512)
			{
			}
		}*/
	//}
}
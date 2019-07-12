
#include "preCompiledHeader.h"

#include "EventHandler.h"
#include "gameEntities/Grid.h"
#include "UtilityFunctions.h"

enum EventQueueState { Empty = 0, EventsPending = 1 };

EventHandler::EventHandler()
{
}

// this function checks for pending events once per frame
void EventHandler::CheckForEvents(Grid& grid)
{
	SDL_Event event;
	while (SDL_PollEvent(&event) == EventQueueState::EventsPending)
	{
		Uint32 eventType = event.type;

		if (eventType == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
		{
			std::cout << "mouse" << std::endl;
			if (UtilityFunctions::IsInsideOf(event.motion, grid.GetGridRect()))
			{
				grid.GridClicked(event);
			}
			else
			{
				std::cout << "esta fora!" << std::endl;
			}
		}
		if (eventType == SDL_EventType::SDL_MOUSEMOTION)
		{
			if (event.motion.x > 512)
			{
			}
		}
	}
}
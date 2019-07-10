#include "EventHandler.h"
#include "preCompiledHeader.h"

enum EventQueueState { Empty = 0, EventsPending = 1 };

EventHandler::EventHandler()
{
}

// this function checks for pending events once per frame
void EventHandler::CheckForEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event) == EventQueueState::EventsPending)
	{
		Uint32 eventType = event.type;

		if (eventType == SDL_EventType::SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
		{
			std::cout << "click" << std::endl;
			// EventDispatch<OnMouseClick>.Handle(&event);
			// or
			// OnMouseClickEvent mc(&event);
			// mc.Handle();
		}
		if (eventType == SDL_EventType::SDL_MOUSEMOTION)
		{
			if (event.motion.x > 512)
			{
				//std::cout << "halfway there";
			}
		}
	}
}
#pragma once

class Grid;
class ClickHandler;

class EventHandler
{
public:
	EventHandler();

	void CheckForEvents(Grid& grid, ClickHandler& clickHandler);
};
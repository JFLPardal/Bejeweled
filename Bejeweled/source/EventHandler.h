#pragma once

class Grid;

class EventHandler
{
public:
	EventHandler();

	void CheckForEvents(Grid& grid);
};
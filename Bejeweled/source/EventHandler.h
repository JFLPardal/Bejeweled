#pragma once

class Grid;

class EventHandler
{
public:
	EventHandler();

	void CheckForEvents(const Grid& grid);
};
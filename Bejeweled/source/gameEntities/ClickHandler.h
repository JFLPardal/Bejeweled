#pragma once

#include "Stone.h"

class Grid;

class ClickHandler
{
public:
	ClickHandler();
	~ClickHandler();

	void StoneClicked(Stone& clickedStone, Grid& grid);
	void ClickedOutsideTheGrid();
private:
	Stone firstClickedStone;
	bool stoneIsSelected = false;

	bool WasSecondClickAdjacentToFirst(Stone& secondClickedStone);
	inline void ResetFirstClickedStone();
};


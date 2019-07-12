#pragma once

class Stone;

class ClickHandler
{
public:
	ClickHandler();
	~ClickHandler();

	void StoneClicked(Stone& clickedStone);
	void ClickedOutsideTheGrid();
private:
	Stone* firstClickedStone;

	bool WasSecondClickAdjacentToFirst(Stone& secondClickedStone);
	inline void ResetFirstClickedStone();
};


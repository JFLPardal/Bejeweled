#pragma once

#include "preCompiledHeader.h"

#include "Stone.h"

const int GRID_WIDTH = 8;
const int GRID_HEIGHT = GRID_WIDTH;

class Grid
{
public:
	Grid();

	void Init();

	Stone GetStoneInPosition(const Vector2& stonePosition) const;

	friend std::ostream& operator<<(std::ostream& os, Grid& grid);

	Stone& operator[](const Vector2& position);
private:
	std::array<Stone, GRID_HEIGHT * GRID_WIDTH> grid;
};
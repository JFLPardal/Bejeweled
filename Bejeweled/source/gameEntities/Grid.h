#pragma once

#include "preCompiledHeader.h"

#include "Stone.h"

extern const int STONE_WIDTH;
extern const int STONE_HEIGHT;

// grid dimensions
static const int GRID_WIDTH = 8;
static const int GRID_HEIGHT = GRID_WIDTH;
// padding between stones, pixels to the right and bottom of each stone that should not be occupied by other stones
static const int GRID_HORIZONTAL_PADDING = 2;
static const int GRID_VERTICAL_PADDING = 2;
// size in pixels occupied by each stone
static const int TOTAL_STONE_WIDTH = STONE_WIDTH + GRID_VERTICAL_PADDING;
static const int TOTAL_STONE_HEIGHT = STONE_HEIGHT + GRID_HORIZONTAL_PADDING;

class Grid
{
public:
	Grid();
	
	void Draw();

	Stone GetStoneInPosition(const Vector2& stonePosition) const;

	friend std::ostream& operator<<(std::ostream& os, Grid& grid);

	Stone& operator[](const Vector2& position);
private:
	std::array<Stone, GRID_HEIGHT * GRID_WIDTH> grid;
	Vector2 gridStartingPosition;

	void Init();
	void inline CalculateGridStartingPosition();
	Vector2 CalculateStonePosition(int x, int y);
};
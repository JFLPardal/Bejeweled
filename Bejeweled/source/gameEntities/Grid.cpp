#include "Grid.h"

Grid::Grid()
{
	Init();
}

void Grid::Init()
{
	Vector2 positionToSet(0);
	Stone stone = grid[0];

	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
 			positionToSet.SetValues(x, y);
			stone.SetNewPosition(positionToSet);
			grid[y * GRID_WIDTH + x] = stone;
		}
	}
}

Stone Grid::GetStoneInPosition(const Vector2& stonePosition) const
{
	Stone stone = grid[stonePosition.Y() * GRID_WIDTH + stonePosition.X()];
	return stone;
}

Stone& Grid::operator[](const Vector2& position)
{
	int indexToAccess = position.Y() * GRID_WIDTH + position.X();
	if (indexToAccess < grid.size())
	{
		return grid[indexToAccess];
	}
	else
	{
		std::cout << "array position out of bounds";
	}
}

std::ostream& operator<<(std::ostream& oStream, Grid& grid)
{
	std::string gridAsString = "";

	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		gridAsString.append("\n"); 
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			gridAsString.append(grid[Vector2(x, y)].GetPosition().ToString());
		}
	}
	oStream << gridAsString;
	return oStream;
}

#include "Grid.h"

#include "Game.h"
#include "UtilityFunctions.h"
#include "GridConstants.h"

#include <algorithm>
Grid::Grid()
	:Clickable(GC::INITIAL_X, GC::INITIAL_Y, GC::GRID_WIDTH_IN_PIXELS, GC::GRID_HEIGHT_IN_PIXELS)
{
	srand(time(NULL));
	Init();
}

void Grid::Init()
{
	for (int y = 0; y < GC::GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GC::GRID_WIDTH; x++)
		{
			grid[y * GC::GRID_WIDTH + x] = Stone(CalculateStonePosition(x, y), GetRandomStoneType());
		}
	}
	// TEST ZONE
	/*
	std::sort(grid.begin(), grid.end(), [](const Stone& a, const Stone&b) {return a.GetStoneType() > b.GetStoneType(); });
	for (auto& stone : grid)
	{
		std::cout << stone.GetStoneType();
	}*/
}

void Grid::Draw()
{
	for (auto& stone : grid)
	{
		stone.Draw();
	}
}

Stone Grid::GridClicked(SDL_Event& gridPositionClicked) 
{
	Stone clickedStone = FindStoneInClickPosition(gridPositionClicked.motion);
	std::cout << clickedStone.GetStoneType();
	return clickedStone;
}

SDL_Rect Grid::GetGridRect() const
{
	return rect;
}

Stone Grid::GetStoneInPosition(const Vector2& stonePosition) const
{
	Stone stone = grid[stonePosition.Y() * GC::GRID_WIDTH + stonePosition.X()];
	return stone;
}

Stone& Grid::operator[](const Vector2& position)
{
	int indexToAccess = position.Y() * GC::GRID_WIDTH + position.X();
	if (indexToAccess < grid.size())
	{
		return grid[indexToAccess];
	}
	else
	{
		std::cout << "array position out of bounds";
	}
}

Vector2 Grid::CalculateStonePosition(int x, int y)
{
	return Vector2(x * GC::TOTAL_STONE_WIDTH + rect.x,
				   y * GC::TOTAL_STONE_HEIGHT +rect.y);
}

inline StoneType Grid::GetRandomStoneType()
{
	int randomIndex = rand() % STONE_TYPE_COUNT;
	return (StoneType) randomIndex;
}

Stone& Grid::FindStoneInClickPosition(SDL_MouseMotionEvent positionOfClick) 
{
	for (auto& stone : grid)
	{
		if (UtilityFunctions::IsInsideOf(positionOfClick, stone.GetClickableRect()))
		{
			return stone;
		}
	}
}

std::ostream& operator<<(std::ostream& oStream, Grid& grid)
{
	std::string gridAsString = "";

	for (int y = 0; y < GC::GRID_HEIGHT; y++)
	{
		gridAsString.append("\n"); 
		for (int x = 0; x < GC::GRID_WIDTH; x++)
		{
			gridAsString.append(grid[Vector2(x, y)].GetPosition().ToString());
		}
	}
	oStream << gridAsString;
	return oStream;
}

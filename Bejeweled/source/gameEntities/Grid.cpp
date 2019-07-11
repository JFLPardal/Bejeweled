#include "Grid.h"

#include "Game.h"

Grid::Grid()
{
	srand(time(NULL));
	CalculateGridStartingPosition();
	Init();
}

void Grid::Init()
{
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			grid[y * GRID_WIDTH + x] = Stone(CalculateStonePosition(x, y), GetRandomStoneType());
		}
	}
}

void Grid::Draw()
{
	for (auto& stone : grid)
	{
		stone.Draw();
	}
}

void Grid::GridClicked(SDL_Event& gridPositionClicked) const
{
	std::cout << "CRICK!";
}

SDL_Rect Grid::GetGridRect() const
{
	SDL_Rect gridRect;

	gridRect.x = gridStartingPosition.X();
	gridRect.y = gridStartingPosition.Y();
	gridRect.w = GRID_WIDTH_IN_PIXELS;
	gridRect.h = GRID_HEIGHT_IN_PIXELS;

	return gridRect;
}

inline void Grid::CalculateGridStartingPosition()
{
	int initialX = (int) WINDOW_WIDTH / 2 - (int) GRID_WIDTH_IN_PIXELS / 2;
	int initialY = (int) WINDOW_HEIGHT / 2 - (int) GRID_HEIGHT_IN_PIXELS / 2;

	gridStartingPosition = Vector2(initialX, initialY);
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

Vector2 Grid::CalculateStonePosition(int x, int y)
{
	return Vector2(x * TOTAL_STONE_WIDTH + gridStartingPosition.X(),
				   y * TOTAL_STONE_HEIGHT + gridStartingPosition.Y());
}

inline StoneType Grid::GetRandomStoneType()
{
	int randomIndex = rand() % STONE_TYPE_COUNT;
	return (StoneType) randomIndex;
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

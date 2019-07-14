#include "Grid.h"

//#include <algorithm>

#include "Game.h"
#include "GridConstants.h"
#include "dataStructures/SequenceInfo.h"
#include "UtilityFunctions.h"

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
			grid[y * GC::GRID_WIDTH + x] = Stone(Vector2(x, y), CalculateStonePosition(x, y), GetRandomStoneType());
		}
	}
	// TEST ZONE
	// sort grid by index
	std::sort(grid.begin(), grid.end(), [](const Stone& a, const Stone&b) 
										{
											Vector2 aIndex = a.GetIndexInGrid();
											Vector2 bIndex = b.GetIndexInGrid();
											return aIndex.Y() * GC::GRID_WIDTH + aIndex.X() < bIndex.Y() * GC::GRID_WIDTH + bIndex.X();
										});
	for (auto& stone : grid)
	{
		std::cout << stone.GetIndexInGrid().ToString();
	}
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

SequenceInfo Grid::StoneSwapSuccesful(const Stone& firstStone, const Stone& secondStone)
{
	printf("Tried to swap type %d (%d,%d) with type %d (%d,%d).\n", firstStone.GetStoneType(), firstStone.GetIndexInGrid().X(), firstStone.GetIndexInGrid().Y(),
		secondStone.GetStoneType(), secondStone.GetIndexInGrid().X(), secondStone.GetIndexInGrid().Y());
	
	// change the 2 stones index in grid

	//check if column or row is made with this swap
	return SequenceInfo(firstStone, secondStone);
}

void Grid::UpdateStonesInGrid(SequenceInfo stonesToDelete)
{
	for (auto& stone : stonesToDelete.GetStonesToDelete())
	{
		if (stonesToDelete.SequenceIsColumn())
		{
			UpdateColumnAboveSequence(stone, stonesToDelete);
		}
		else
		{
			UpdateRowsAboveSequence(stone);
		}
	}
}

void Grid::UpdateRowsAboveSequence(Stone& stone)
{
	printf("Updated rows.\n");
	Vector2 stoneGridIndex = stone.GetIndexInGrid();

	for (int y = stoneGridIndex.Y(); y > 0; y--)
	{
		int gridIndexForCurrentStone = y * GRID_CONSTANTS::GRID_WIDTH + stoneGridIndex.X();
		int gridIndexForStoneAbove = (y - 1) * GRID_CONSTANTS::GRID_WIDTH + stoneGridIndex.X();
		StoneType typeOfStoneAbove = grid[gridIndexForStoneAbove].GetStoneType();

		grid[gridIndexForCurrentStone].UpdateStoneType(typeOfStoneAbove);
	}
	grid[stoneGridIndex.X()].UpdateStoneType(GetRandomStoneType());
}

void Grid::UpdateColumnAboveSequence(Stone& stone, SequenceInfo sequence)
{
	printf("Updated columns.\n");
	Vector2 stoneGridIndex = stone.GetIndexInGrid();
	int sequenceNumberOfStones = sequence.GetStonesToDelete().size();
	int bottomCoordinate = sequence.GetBottomCoordenate();

	for (int y = bottomCoordinate; y >= sequenceNumberOfStones; y--) // lower rest of the column
	{
		int gridIndexForCurrentStone = y * GRID_CONSTANTS::GRID_WIDTH + stoneGridIndex.X();
		int gridIndexForFirstNonSequence = (y - sequenceNumberOfStones) * GRID_CONSTANTS::GRID_WIDTH + stoneGridIndex.X();
		StoneType typeOfFirstNonSequenceStone = grid[gridIndexForFirstNonSequence].GetStoneType();

		grid[gridIndexForCurrentStone].UpdateStoneType(typeOfFirstNonSequenceStone);
	}
	for (int y = sequenceNumberOfStones-1; y >= 0; y--) // generates stones in the 'holes' left at the top
	{
		int gridIndexForCurrentStone = y * GRID_CONSTANTS::GRID_WIDTH + stoneGridIndex.X();
		
		grid[gridIndexForCurrentStone].UpdateStoneType(GetRandomStoneType());
	}

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

#include "Grid.h"

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

	for (int x = 0; x < GC::GRID_WIDTH; x++) // delete this for and update next for to y = 0
	{
		if (x == 2 || x == 4)
			grid[CalculateIndex(x, 1)] = Stone(Vector2(x, 1), CalculateStonePosition(x, 1), StoneType::skull);
		else
			grid[CalculateIndex(x, 0)] = Stone(Vector2(x, 0), CalculateStonePosition(x, 0), GetRandomStoneType());
	}
	grid[CalculateIndex(3, 0)] = Stone(Vector2(3, 0), CalculateStonePosition(3, 0), StoneType::skull);
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

void Grid::UpdateStonesInGrid(SequenceInfo stonesToDelete)
{
	if (stonesToDelete.SequenceIsColumn())
	{
		UpdateColumnAboveSequence(stonesToDelete.GetStonesToDelete()[0], stonesToDelete);
	}
	else 
	{
		for (auto& stoneGridIndex : stonesToDelete.GetStonesToDelete())
		{
			UpdateRowsAboveSequence(stoneGridIndex);
		}
	}
}

void Grid::SwapStonesAndCheckForSequences(Stone& firstStone, Stone& secondStone)
{
	Vector2 firstStoneIndex = firstStone.GetIndexInGrid();
	Vector2 secondStoneIndex = secondStone.GetIndexInGrid();

	SwapAdjacentStoneTypes(firstStoneIndex, secondStoneIndex);
	// add draw both stones
	grid[0];	// delete
	SequenceInfo possibleSequenceForOneStone = CheckIfSwapMadeSequence(secondStoneIndex);
	SequenceInfo possibleSequenceForOtherStone = CheckIfSwapMadeSequence(firstStoneIndex);

	if (possibleSequenceForOneStone.IsSequence())
	{
		// check if any of the stones clicked has a sequence in its neighborhood
		printf("Sequence was made.\n");
		UpdateStonesInGrid(possibleSequenceForOneStone);
	}
	if (possibleSequenceForOtherStone.IsSequence())
	{
		printf("Sequence was made.\n");
		UpdateStonesInGrid(possibleSequenceForOtherStone);
	}
	else if(!possibleSequenceForOneStone.IsSequence()) // if neither swapped stone produced a sequence
	{
		SwapAdjacentStoneTypes(firstStone.GetIndexInGrid(), secondStone.GetIndexInGrid());
		printf("swapped stones back.\n");
	}
}


void Grid::SwapAdjacentStoneTypes(const Vector2& firstStone, const Vector2& secondStone)
{
	int firstStoneIndex = firstStone.Y() * GRID_CONSTANTS::GRID_WIDTH + firstStone.X();
	int secondStoneIndex = secondStone.Y() * GRID_CONSTANTS::GRID_WIDTH + secondStone.X();
	StoneType firstStoneType = grid[firstStoneIndex].GetStoneType();

	grid[firstStoneIndex].UpdateStoneType(grid[secondStoneIndex].GetStoneType());
	grid[secondStoneIndex].UpdateStoneType(firstStoneType);
}

SequenceInfo Grid::CheckIfSwapMadeSequence(Vector2& gridIndexToInspect)
{
	StoneType inspectingStoneType = grid[gridIndexToInspect.Y() * GRID_CONSTANTS::GRID_WIDTH + gridIndexToInspect.X()].GetStoneType();
	Vector2 sequenceEndIndex;
	bool isSequence = false;
	for (int i = 0; i < NUMBER_OF_DIRECTIONS; i++)
	{
		Vector2 directionToCheck = Vector2::GetVectorFromDirection((SwapDirection)i);
		if (directionToCheck.Y() == 0) // will check adjacency for the sides
		{
			if(gridIndexToInspect.X() != 0 && gridIndexToInspect.X() != GRID_CONSTANTS::GRID_WIDTH-1)
				{
				int sequenceElements = 1;
				for (int i = gridIndexToInspect.X(); i < GRID_CONSTANTS::GRID_WIDTH; i++)
				{
					int indexToCheck = gridIndexToInspect.Y() * GRID_CONSTANTS::GRID_WIDTH + gridIndexToInspect.X() + directionToCheck.X() * sequenceElements;
					if (grid[indexToCheck].GetStoneType() == inspectingStoneType)
					{
						sequenceElements++;
						printf("Stone of equal type.\n");
					}
					else
					{
						if (sequenceElements == 2) // check the opposite direction to try to find the 3rd and 4th
						{
							int attemptToFindAdjacent = 1;
							int previouslyTestedX = gridIndexToInspect.X() + directionToCheck.X();
							int testingFor1stOpposite = gridIndexToInspect.X() + directionToCheck.X() * (-attemptToFindAdjacent);
							int previouslyTestedY = gridIndexToInspect.Y();

							if (testingFor1stOpposite >= 0 && testingFor1stOpposite < GRID_CONSTANTS::GRID_WIDTH && grid[CalculateIndex(testingFor1stOpposite, previouslyTestedY)].GetStoneType() == inspectingStoneType)
							{
								attemptToFindAdjacent++;
								int testingFor2ndOpposite = gridIndexToInspect.X() + directionToCheck.X() * (-attemptToFindAdjacent);
								if (testingFor2ndOpposite >= 0 && testingFor2ndOpposite < GRID_CONSTANTS::GRID_WIDTH &&  grid[CalculateIndex(testingFor2ndOpposite, previouslyTestedY)].GetStoneType() == inspectingStoneType)
								{
									Vector2 indexPreviouslyTested = grid[CalculateIndex(previouslyTestedX, previouslyTestedY)].GetIndexInGrid();
									Vector2 indexOpposedToTested = grid[CalculateIndex(testingFor2ndOpposite, previouslyTestedY)].GetIndexInGrid();
									//sequenceElements++; // redundant if return is before 'if (sequenceElements >= 3)'
									isSequence = true;
									printf("triangle of 4!\n");
									return SequenceInfo(indexPreviouslyTested, indexOpposedToTested, isSequence);
								}
									Vector2 indexPreviouslyTested = grid[CalculateIndex(previouslyTestedX, previouslyTestedY)].GetIndexInGrid();
								Vector2 indexOpposedToTested = grid[CalculateIndex(testingFor1stOpposite, previouslyTestedY)].GetIndexInGrid();
								//sequenceElements++; // redundant if return is before 'if (sequenceElements >= 3)'
								isSequence = true;
								printf("triangle of 3!\n");
								return SequenceInfo(indexPreviouslyTested, indexOpposedToTested, isSequence);
							}
						}
						if (sequenceElements >= 3)
						{
							sequenceEndIndex = grid[gridIndexToInspect.Y() * GRID_CONSTANTS::GRID_WIDTH + gridIndexToInspect.X() + directionToCheck.X() * (sequenceElements - 1)].GetIndexInGrid();
						}
						break;
					}
				}
				if (sequenceElements >= 3)
				{
					printf("Sequence made.\n");
					isSequence = true;
				}
			}
			else if (gridIndexToInspect.X() == 0 && 
				     directionToCheck == Vector2::GetVectorFromDirection(SwapDirection::left))
			{
				break;
			}else if(gridIndexToInspect.X() == GRID_CONSTANTS::GRID_WIDTH-1 && 
					 directionToCheck == Vector2::GetVectorFromDirection(SwapDirection::right))
			{
				break;
			}
		}/*
		else
		{
			int sequenceElements = 1;
			for (int x = gridIndexToInspect.GetIndexInGrid().X(); x < GRID_CONSTANTS::GRID_WIDTH; i++)
			{
				if (grid[(gridIndexToInspect.GetIndexInGrid().Y() + directionToCheck.Y() * sequenceElements) + //directionToCheck.X() gridIndexToInspect.GetIndexInGrid().Y])
			}
		}*/
	}
	return SequenceInfo(gridIndexToInspect, sequenceEndIndex, isSequence);
}


void Grid::UpdateRowsAboveSequence(Vector2& stoneGridIndex)
{
	printf("Updated rows.\n");

	for (int y = stoneGridIndex.Y(); y > 0; y--)
	{
		int gridIndexForCurrentStone = CalculateIndex(stoneGridIndex.X(), y);
		int gridIndexForStoneAbove = CalculateIndex(stoneGridIndex.X(), (y-1)); 
		StoneType typeOfStoneAbove = grid[gridIndexForStoneAbove].GetStoneType();

		grid[gridIndexForCurrentStone].UpdateStoneType(typeOfStoneAbove);
	}
	grid[stoneGridIndex.X()].UpdateStoneType(GetRandomStoneType());
}

void Grid::UpdateColumnAboveSequence(Vector2& stoneGridIndex, SequenceInfo sequence)
{
	printf("Updated columns.\n");
	int sequenceNumberOfStones = sequence.GetStonesToDelete().size();
	int bottomCoordinate = sequence.GetBottomCoordenate();

	for (int y = bottomCoordinate; y >= sequenceNumberOfStones; y--) // lower rest of the column
	{
		int gridIndexForCurrentStone = y * GRID_CONSTANTS::GRID_WIDTH + stoneGridIndex.X();
		int gridIndexForFirstNonSequence = (y - sequenceNumberOfStones) * GRID_CONSTANTS::GRID_WIDTH + stoneGridIndex.X();
		StoneType typeOfFirstNonSequenceStone = grid[gridIndexForFirstNonSequence].GetStoneType();

		grid[gridIndexForCurrentStone].UpdateStoneType(typeOfFirstNonSequenceStone);
	}
	for (int y = sequenceNumberOfStones - 1; y >= 0; y--) // generates stones in the 'holes' left at the top
	{
		int gridIndexForCurrentStone = y * GRID_CONSTANTS::GRID_WIDTH + stoneGridIndex.X();

		grid[gridIndexForCurrentStone].UpdateStoneType(GetRandomStoneType());
	}
}

bool Grid::AreStonesAdjacent(const Stone& firstStone, const Stone& secondStone)
{
	return firstStone.GetIndexInGrid().IsAdjacentTo(secondStone.GetIndexInGrid());
}

bool Grid::AreStonesAdjacent(const Vector2& firstStone, const Vector2& secondStone)
{
	return firstStone.IsAdjacentTo(secondStone);
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

inline int Grid::CalculateIndex(int x, int y)
{
	return y * GRID_CONSTANTS::GRID_WIDTH + x;
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

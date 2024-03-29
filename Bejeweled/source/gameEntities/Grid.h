#pragma once

#include "preCompiledHeader.h"

#include "GridConstants.h"
#include "Clickable.h"
#include "Stone.h"

const int GRID_DIMENSION = 64; // can't get 'GridConstants.h' constants to use in array decl...

class SequenceInfo;

class Grid : public Clickable
{
public:
	Grid();
	
	void Draw();
	
	SDL_Rect GetGridRect() const;
	Stone GetStoneInPosition(const Vector2& stonePosition) const;

	Stone GridClicked(SDL_Event& event);
	void UpdateStonesInGrid(SequenceInfo stonesToDelete);

	void SwapStonesAndCheckForSequences(Stone& firstStone, Stone& secondStone);
	void DrawSwappedStones(const Vector2 &firstStoneIndex, const Vector2 &secondStoneIndex);
	void CheckGridForSequences();
	void CheckForSequencesAfterSwapping(Vector2& firstStoneIndex, Vector2& secondStoneIndex);
	void CheckForSequencesOnIndividualIndex(Vector2& firstStoneIndex);
	bool AreStonesAdjacent(const Stone& firstStone, const Stone& secondStone);
	bool AreStonesAdjacent(const Vector2& firstStone, const Vector2& secondStone);

	friend std::ostream& operator<<(std::ostream& os, Grid& grid);
	Stone& operator[](const Vector2& position);
private:
	std::array<Stone, GRID_DIMENSION> grid;

	void Init();

	Vector2 inline CalculateStonePosition(int x, int y);
	int inline CalculateIndex(int x, int y);
	int inline CalculateIndex(Vector2 vector);
	StoneType inline GetRandomStoneType();

	Stone& FindStoneInClickPosition(SDL_MouseMotionEvent positionOfClick);

	void UpdateRowsAboveSequence(Vector2& stoneGridIndex);
	void UpdateColumnAboveSequence(Vector2& stoneGridIndex, SequenceInfo sequence);

	void SwapAdjacentStoneTypes(const Vector2& firstStone, const Vector2& secondStone);
	SequenceInfo CheckIfSwapMadeSequence(Vector2& firstStone);
};
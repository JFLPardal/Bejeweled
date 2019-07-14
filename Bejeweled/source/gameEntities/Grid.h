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
	SequenceInfo StoneSwapSuccesful(const Stone& firstStone, const Stone& secondStone); 
	void UpdateStonesInGrid(SequenceInfo stonesToDelete);


	friend std::ostream& operator<<(std::ostream& os, Grid& grid);
	Stone& operator[](const Vector2& position);
private:
	std::array<Stone, GRID_DIMENSION> grid;
	//std::array<Stone, GRID_CONSTANTS::GRID_WIDTH * GRID_CONSTANTS::GRID_WIDTH> grid;

	void Init();

	Vector2 inline CalculateStonePosition(int x, int y);
	StoneType inline GetRandomStoneType();

	Stone& FindStoneInClickPosition(SDL_MouseMotionEvent positionOfClick);
	void DeleteStoneFromGrid(Stone& stoneToDelete);
	void UpdateRowsAboveSequence(Stone & stone);
};
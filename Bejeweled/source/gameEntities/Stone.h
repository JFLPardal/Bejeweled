#pragma once

#include "preCompiledHeader.h"

#include "dataStructures/Vector2.h"
#include "Clickable.h"

enum StoneType { diamond = 0, flame, moon, skull, star };
const static int STONE_TYPE_COUNT = 5; // update this number if adding/removing to 'StoneType' 

class Stone : public Clickable
{
public:
	Stone();
	Stone(Vector2 indexInGrid, Vector2 pos, StoneType stoneType);

	Vector2 GetSpritePosition()const;
	Vector2 GetIndexInGrid() const;
	StoneType GetStoneType() const;
	void UpdateStoneType(StoneType newType);
	void SetNewPosition(Vector2 newPosition);
	void UpdateSpritePosition(SwapDirection differenceFromOriginalPosition, int timesToUpdate = 1);

	bool IsAdjacentTo(const Stone& stoneToCheck);
	void Draw();

	static const char* StoneTypeToString(StoneType stoneType);
	~Stone();
private:
	StoneType stoneType;
	Vector2 indexInGrid;
};

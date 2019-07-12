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
	Stone(Vector2 pos, StoneType stoneType);

	Vector2 GetPosition()const;
	StoneType GetStoneType() const;
	void SetNewPosition(Vector2 newPosition);
	void UpdatePosition(Vector2 differenceFromOriginalPosition);

	bool IsAdjacentTo(const Stone& stoneToCheck);
	void Draw();

	~Stone();
private:
	StoneType stoneType;
};

#pragma once

#include "preCompiledHeader.h"

#include "dataStructures/Vector2.h"
#include "Clickable.h"

enum StoneType { diamond = 0, flame, moon, skull, star };
// update this number if adding/removing to 'StoneType' 
const static int STONE_TYPE_COUNT = 5;

class Stone : public Clickable
{
public:
	Stone();
	Stone(Vector2 pos, StoneType stoneType);

	Vector2 GetPosition()const;
	StoneType GetStoneType() const;
	void SetNewPosition(Vector2 newPosition);
	void UpdatePosition(Vector2 differenceFromOriginalPosition);

	void Draw();

	~Stone();
private:
	Vector2 position;
	StoneType stoneType;
};

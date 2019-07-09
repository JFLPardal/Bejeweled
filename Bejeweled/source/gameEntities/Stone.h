#pragma once

#include "dataStructures/Vector2.h"

class Stone
{
public:
	Stone();
	Stone(Vector2 pos);

	Vector2 GetPosition() const;
	void SetNewPosition(Vector2 newPosition);
	void UpdatePosition(Vector2 differenceFromOriginalPosition);
private:
	Vector2 position;
};

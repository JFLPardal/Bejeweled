#include "Stone.h"

#include "TextureManager.h"

Stone::Stone()
	:position(Vector2())
{
}

Stone::Stone(Vector2 pos)
	:position(pos)
{
}

Stone::Stone(Vector2 pos, StoneType stoneType)
	:position(pos), stoneType(stoneType)
{
}

Vector2 Stone::GetPosition() const
{
	return position;
}

StoneType Stone::GetStoneType() const
{
	return stoneType;
}

void Stone::SetNewPosition(Vector2 newPosition)
{
	position = newPosition;
}

void Stone::UpdatePosition(Vector2 differenceFromOriginalPosition)
{
	position += differenceFromOriginalPosition;
}

void Stone::Draw()
{
	TextureManager::Draw(this);
}

Stone::~Stone()
{
}

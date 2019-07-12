#include "Stone.h"

#include "GridConstants.h"
#include "TextureManager.h"

Stone::Stone()
	:position(Vector2()), Clickable(position.X(), position.Y(), GC::TOTAL_STONE_WIDTH, GC::TOTAL_STONE_HEIGHT)
{
}

Stone::Stone(Vector2 pos, StoneType stoneType)
	:position(pos), stoneType(stoneType), Clickable(pos.X(), pos.Y(), GC::TOTAL_STONE_WIDTH, GC::TOTAL_STONE_HEIGHT)
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

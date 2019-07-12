#include "Stone.h"

#include "GridConstants.h"
#include "TextureManager.h"

Stone::Stone()
	:Clickable(-1, -1, GC::TOTAL_STONE_WIDTH, GC::TOTAL_STONE_HEIGHT)
{
}

Stone::Stone(Vector2 pos, StoneType stoneType)
	:stoneType(stoneType), Clickable(pos.X(), pos.Y(), GC::TOTAL_STONE_WIDTH, GC::TOTAL_STONE_HEIGHT)
{
}

Vector2 Stone::GetPosition() const
{
	return Vector2(rect.x, rect.y);
}

StoneType Stone::GetStoneType() const
{
	return stoneType;
}

void Stone::SetNewPosition(Vector2 newPosition)
{
	rect.x = newPosition.X();
	rect.y = newPosition.Y();
}

void Stone::UpdatePosition(Vector2 differenceFromOriginalPosition)
{
	rect.x += differenceFromOriginalPosition.X();
	rect.y += differenceFromOriginalPosition.Y();
}

bool Stone::IsAdjacentTo(const Stone & stoneToCheck)
{
	return GetPosition().IsAdjacentTo(stoneToCheck.GetPosition());
}

void Stone::Draw()
{
	TextureManager::Draw(this);
}

Stone::~Stone()
{
}

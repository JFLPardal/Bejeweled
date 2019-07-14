#include "Stone.h"

#include "GridConstants.h"
#include "TextureManager.h"

Stone::Stone()
	:Clickable(-1, -1, GC::TOTAL_STONE_WIDTH, GC::TOTAL_STONE_HEIGHT)
{
}

Stone::Stone(Vector2 indexInGrid, Vector2 pos, StoneType stoneType)
	:indexInGrid(indexInGrid), stoneType(stoneType), Clickable(pos.X(), pos.Y(), GC::TOTAL_STONE_WIDTH, GC::TOTAL_STONE_HEIGHT)
{
}

Vector2 Stone::GetPosition() const
{
	return Vector2(rect.x, rect.y);
}

Vector2 Stone::GetIndexInGrid() const
{
	return indexInGrid;
}

StoneType Stone::GetStoneType() const
{
	return stoneType;
}
void Stone::UpdateStoneType(StoneType newType)
{
	stoneType = newType;
}
/*
void Stone::SetNewPosition(Vector2 newPosition)
{
	rect.x = newPosition.X();
	rect.y = newPosition.Y();
}*/

void Stone::UpdateSpritePosition(SwapDirection differenceFromOriginalPosition, int timesToUpdate)
{
	Vector2 updateVector = Vector2::GetVectorFromDirection(differenceFromOriginalPosition);
	rect.x += updateVector.X() * GRID_CONSTANTS::TOTAL_STONE_WIDTH* timesToUpdate;
	rect.y += updateVector.Y() * GRID_CONSTANTS::TOTAL_STONE_HEIGHT *timesToUpdate;
}

bool Stone::IsAdjacentTo(const Stone & stoneToCheck)
{
	return this->indexInGrid.IsAdjacentTo(stoneToCheck.GetIndexInGrid());
}

void Stone::Draw()
{
	TextureManager::Draw(this);
}

Stone::~Stone()
{
}

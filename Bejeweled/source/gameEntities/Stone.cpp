#include "Stone.h"

Stone::Stone()
	:position(Vector2())
{
}

Stone::Stone(Vector2 pos)
	:position(pos)
{
}

Vector2 Stone::GetPosition() const
{
	return position;
}

void Stone::SetNewPosition(Vector2 newPosition)
{
	position = newPosition;
}

void Stone::UpdatePosition(Vector2 differenceFromOriginalPosition)
{
	position += differenceFromOriginalPosition;
}

Stone::~Stone()
{
	SDL_DestroyTexture(pSprite);
}

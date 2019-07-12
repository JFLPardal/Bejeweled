#include "Clickable.h"

Clickable::Clickable(int x, int y, int w, int h)
{
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}

SDL_Rect Clickable::GetClickableRect()
{
	return rect;
}

Clickable::~Clickable()
{
}
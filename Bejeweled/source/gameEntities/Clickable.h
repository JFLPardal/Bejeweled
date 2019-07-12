#pragma once

#include "preCompiledHeader.h"

class Clickable
{
public:
	SDL_Rect GetClickableRect();
protected:
	Clickable(int x, int y, int w, int h);
	~Clickable();

	SDL_Rect rect;
};


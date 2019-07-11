#pragma once

#include "preCompiledHeader.h"

class Vector2;

struct UtilityFunctions
{
	static bool IsInsideOf(const Vector2& positionToCheck, const SDL_Rect& objectToCompare);
	static bool IsInsideOf(const SDL_MouseMotionEvent& positionToCheck, const SDL_Rect& objectToCompare);
};

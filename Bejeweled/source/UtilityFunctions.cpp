#include "UtilityFunctions.h"

#include "dataStructures/Vector2.h"

bool UtilityFunctions::IsInsideOf(const Vector2& positionToCheck, const SDL_Rect& objectToCompare)
{
	int positionX = positionToCheck.X();
	int positionY = positionToCheck.Y();
	int objectToCompareX = objectToCompare.x;
	int objectToCompareY = objectToCompare.y;

	if(positionX >= objectToCompareX && positionX <= (objectToCompareX + objectToCompare.w))
	{
		if (positionY >= objectToCompareY && positionY <= (objectToCompareY + objectToCompare.h))
		{
			return true;
		}
	}
	return false;
}

bool UtilityFunctions::IsInsideOf(const SDL_MouseMotionEvent& positionToCheck, const SDL_Rect& objectToCompare)
{
	int positionX = positionToCheck.x;
	int positionY = positionToCheck.y;
	int objectToCompareX = objectToCompare.x;
	int objectToCompareY = objectToCompare.y;

	if (positionX >= objectToCompareX && positionX <= (objectToCompareX + objectToCompare.w))
	{
		if (positionY >= objectToCompareY && positionY <= (objectToCompareY + objectToCompare.h))
		{
			return true;
		}
	}
	return false;
}

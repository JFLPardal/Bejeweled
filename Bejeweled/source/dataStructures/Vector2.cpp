#include "Vector2.h"

Vector2::Vector2()
	:x(0), y(0)
{
}

Vector2::Vector2(int value)
	:x(value), y(value)
{
}

Vector2::Vector2(int newX, int newY)
	:x(newX), y(newY)
{
}

int Vector2::X() const
{
	return x;
}

int Vector2::Y() const
{
	return y;
}

void Vector2::SetValues(int newX, int newY)
{
	x = newX;
	y = newY;
}

void Vector2::SetX(int newX)
{
	SetValues(newX, y);
}

void Vector2::SetY(int newY)
{
	SetValues(x, newY);
}

std::ostream& operator<<(std::ostream& oStream, Vector2& vector)
{
	oStream << "(" << vector.X() << "," << vector.Y() << ")";
	return oStream;
}

bool operator==(const Vector2& vector1, const Vector2& vector2)
{
	return (vector1.x == vector2.x && vector1.y == vector2.y);
}

Vector2& operator+=(Vector2& vectorToUpdate, const Vector2& vectorIncrement)
{
	vectorToUpdate.Add(vectorIncrement);
	return vectorToUpdate;
}

std::string Vector2::ToString()
{
	std::string vectorAsString = "";
	vectorAsString = '(' + std::to_string(x) + ',' + std::to_string(y) + ')';
	return vectorAsString;
}

Vector2& Vector2::Add(const Vector2& vectorToAdd)
{
	x += vectorToAdd.X();
	y += vectorToAdd.Y();
	return *this;
}

bool Vector2::IsAdjacentTo(const Vector2& vectorToCheck) const
{
	if (x == vectorToCheck.x)
	{
		if (y == vectorToCheck.y + 1 || y == vectorToCheck.y - 1)
		{
			return true;
		}
	}
	else if (y == vectorToCheck.y)
	{
		if (x == vectorToCheck.x + 1 || x == vectorToCheck.x - 1)
		{
			return true;
		}
	}
	return false;
}

Vector2 Vector2::GetVectorFromDirection(SwapDirection direction)
{
	switch (direction)
	{
	case up:
		return Vector2(0, -1); // origin is top left corner!
		break;
	case right:
		return Vector2(1, 0);
		break;
	case down:
		return Vector2(0, 1);
		break;
	case left:
		return Vector2(-1, 0);
		break;
	}
}

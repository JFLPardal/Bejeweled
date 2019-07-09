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

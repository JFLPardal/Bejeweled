#pragma once

#include "preCompiledHeader.h"

// don't change initialization or Gird.CheckNeighborhood will break;
enum SwapDirection
{
	up = 0, right, down, left
};
const static int NUMBER_OF_DIRECTIONS = 4; // update this number if adding/removing to 'StoneType' 

class Vector2
{
public:
	Vector2();
	Vector2(int value);
	Vector2(int newX, int newY);

	int X() const;
	int Y() const;

	void SetValues(int newX, int newY);
	void SetX(int newX);
	void SetY(int newY);

	Vector2& Add(const Vector2& vectorToAdd);
	bool IsAdjacentTo(const Vector2& vectorToCheck) const;
	static Vector2 GetVectorFromDirection(SwapDirection direction);

	friend std::ostream& operator<<(std::ostream& oStream, const Vector2& vector);
	friend bool operator==(const Vector2& vector1, const Vector2& vector2);
	friend Vector2& operator+=(Vector2& vectorToUpdate, const Vector2& vectorIncrement);
	std::string ToString();
private:
	int x, y;
};


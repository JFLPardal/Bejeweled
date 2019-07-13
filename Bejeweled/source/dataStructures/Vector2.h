#pragma once

#include "preCompiledHeader.h"

enum SwapDirection { left, up, right, down };

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
	bool IsAdjacentTo(const Vector2& vectorToCheck);

	friend std::ostream& operator<<(std::ostream& oStream, const Vector2& vector);
	friend Vector2& operator+=(Vector2& vectorToUpdate, const Vector2& vectorIncrement);

	std::string ToString();
private:
	int x, y;
};


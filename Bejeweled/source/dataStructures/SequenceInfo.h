#pragma once
#include "preCompiledHeader.h"

#include "Vector2.h"

class Stone;

class SequenceInfo
{
public:
	SequenceInfo();
	SequenceInfo(const Vector2& firstStone, const Vector2& lastStone, bool isSequence);
	~SequenceInfo();

	bool IsSequence() { return isSequence; }
	bool SequenceIsColumn() { return sequenceIsColumn; }
	int GetBottomCoordenate();
	std::vector<Vector2> GetStonesToDelete() { return sequenceIndexes; }
private:
	bool isSequence;
	bool sequenceIsColumn;
	std::vector<Vector2> sequenceIndexes;
};
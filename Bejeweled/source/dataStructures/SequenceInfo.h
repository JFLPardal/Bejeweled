#pragma once
#include "preCompiledHeader.h"

#include "Vector2.h"

class Stone;

class SequenceInfo
{
public:
	SequenceInfo();
	SequenceInfo(const Stone& firstStone, const Stone& lastStone);
	~SequenceInfo();

	bool IsSequence() { return isSequence; }
	bool SequenceIsColumn() { return deleteColumn; }
	int GetBottomCoordenate();
	std::vector<Vector2> GetStonesToDelete() { return sequenceIndexes; }
private:
	bool isSequence;
	bool deleteColumn;
	std::vector<Vector2> sequenceIndexes;
};
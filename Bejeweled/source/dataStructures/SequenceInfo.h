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
	std::vector<Stone> GetStonesToDelete() { return stonesToDelete; }
private:
	bool isSequence;
	bool deleteColumn;
	std::vector<Stone> stonesToDelete;
};
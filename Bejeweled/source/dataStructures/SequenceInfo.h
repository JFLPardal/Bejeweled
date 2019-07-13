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
	std::vector<Stone> GetStonesToDelete() { return stonesToDelete; }

private:
	bool isSequence;
	std::vector<Stone> stonesToDelete;
};
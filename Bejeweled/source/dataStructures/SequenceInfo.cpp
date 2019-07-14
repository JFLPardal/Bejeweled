#include "SequenceInfo.h"

#include "gameEntities/Stone.h"

SequenceInfo::SequenceInfo()
	:isSequence(true), sequenceIndexes(std::vector<Vector2>())
{
}

SequenceInfo::SequenceInfo(const Stone& firstStone, const Stone& lastStone)
	:isSequence(true), sequenceIndexes(std::vector<Vector2>())
{
	if (firstStone.GetIndexInGrid().X() == lastStone.GetIndexInGrid().X())// sequenceIndexes will contain part of a column
	{
		deleteColumn = true;
		printf("sequence is column.\n");
		int sequenceX = lastStone.GetIndexInGrid().X();
		if (firstStone.GetIndexInGrid().Y() < lastStone.GetIndexInGrid().Y())
		{
			for (int y = firstStone.GetIndexInGrid().Y(); y <= lastStone.GetIndexInGrid().Y(); y++) 
			{
				sequenceIndexes.emplace_back(Vector2(sequenceX, y));
				printf("Added (%d,%d) to sequenceIndexes.\n", sequenceX, y);
			}
		}
		else
		{
			for (int y = lastStone.GetIndexInGrid().Y(); y <= firstStone.GetIndexInGrid().Y(); y++) // if the programmer passed the lastStone as the firstStone
			{
				sequenceIndexes.emplace_back(Vector2(sequenceX, y));
				printf("Added (%d,%d) to sequenceIndexes with alt fucntion.\n", sequenceX, y);
			}
		}
	}
	else
	{
		deleteColumn = false;
		printf("sequence is row.\n");
		int lastStoneInSequenceX = lastStone.GetIndexInGrid().X();
		int sequenceY = lastStone.GetIndexInGrid().Y();
		for (int x = firstStone.GetIndexInGrid().X(); x <= lastStone.GetIndexInGrid().X(); x++)
		{
			sequenceIndexes.emplace_back(Vector2(x, sequenceY));
			printf("Added (%d,%d) to sequenceIndexes.\n", x, sequenceY);
		}
	}
}

// UPDATE THIS, NOT WORKING PROPERLY
int SequenceInfo::GetBottomCoordenate()
{
	int highestY = 0; // I don't like this name, it's the highest Y in this coordenate system but it is the lowest position visually, for math consistency this is the name I will go with
	for (auto& vector : sequenceIndexes)
	{
		int indexY = vector.Y();
		if (indexY > highestY)
			highestY = indexY;
	}
	return highestY;
}

SequenceInfo::~SequenceInfo()
{
}


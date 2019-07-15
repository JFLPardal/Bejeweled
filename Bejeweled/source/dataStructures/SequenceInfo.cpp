#include "SequenceInfo.h"

#include "gameEntities/Stone.h"

SequenceInfo::SequenceInfo()
	:isSequence(true), sequenceIndexes(std::vector<Vector2>())
{
}

SequenceInfo::SequenceInfo(const Vector2& firstStone, const Vector2& lastStone, bool isSequence, StoneType inspectingStoneType)
	:isSequence(isSequence), sequenceIndexes(std::vector<Vector2>())
{
	if(isSequence)
	{
		if (firstStone.X() == lastStone.X()) // sequenceIndexes will contain part of a column
		{
			sequenceIsColumn = true;
			//printf("column.\n");
			int sequenceX = lastStone.X();
			if (firstStone.Y() < lastStone.Y()) // clicked sequence was from top to bottom
			{
				for (int y = firstStone.Y(); y <= lastStone.Y(); y++) 
				{
					sequenceIndexes.emplace_back(Vector2(sequenceX, y));
				}
			}
			else // clicked sequence was from bottom to top
			{
				for (int y = lastStone.Y(); y <= firstStone.Y(); y++)
				{
					sequenceIndexes.emplace_back(Vector2(sequenceX, y));
				}
			}
		}
		else
		{
			sequenceIsColumn = false;
			//printf("row.\n");
			int lastStoneInSequenceX = lastStone.X();
			int sequenceY = lastStone.Y();
			if (firstStone.X() < lastStone.X()) // clicked sequence was from left to right
			{
				int lastStoneX = lastStone.X();
				for (int x = firstStone.X(); x <= lastStoneX; x++)
				{
					sequenceIndexes.emplace_back(Vector2(x, sequenceY));
				}
			}
			else // clicked sequence was from right to left
			{
				int firstStoneX = firstStone.X();
				for (int x = lastStone.X(); x <= firstStoneX; x++)
				{
					sequenceIndexes.emplace_back(Vector2(x, sequenceY));
				}
			}
		}
		printf("Sequence of %d %s stones made.\n ", sequenceIndexes.size(), Stone::StoneTypeToString(inspectingStoneType));
	}
}

int SequenceInfo::GetBottomCoordenate()
{
	int highestY = 0; // I don't like this name, it's the highest Y in this coordenate system but it is the lowest position visually, for logic's consistency this is the name I will go with
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


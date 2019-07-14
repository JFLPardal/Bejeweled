#include "SequenceInfo.h"

#include "gameEntities/Stone.h"

SequenceInfo::SequenceInfo()
	:isSequence(true), stonesToDelete(std::vector<Stone>())
{
	stonesToDelete.emplace_back(Stone(Vector2(0,0), Vector2(0, 0), StoneType::diamond));

}

SequenceInfo::SequenceInfo(const Stone& firstStone, const Stone& lastStone)
	:isSequence(true), stonesToDelete(std::vector<Stone>())
{
	stonesToDelete.emplace_back(firstStone);
	if (firstStone.GetIndexInGrid().X() == lastStone.GetIndexInGrid().X())// stonesToDelete will contain part of a column
	{
		deleteColumn = true;
		printf("sequence is column.\n");
		if (firstStone.GetIndexInGrid().Y() < lastStone.GetIndexInGrid().Y())
		{
			for (int y = firstStone.GetIndexInGrid().Y(); y < firstStone.GetIndexInGrid().Y(); y++)
			{
				//
			}
		}
	}
	else
	{
		deleteColumn = false;
		printf("sequence is row.\n");
	}


}

SequenceInfo::~SequenceInfo()
{
}

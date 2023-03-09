#include "../mainHeader.h"
enum DifficultyType
{
	Easy = 0,
	Normal = 1,
	Hard = 2,
	Immortal = 3
};

class DailyTask : public Task
{
	int money;
	int exp;
	DifficultyType difficulty;
};

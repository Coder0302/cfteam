#include "../mainHeader.h"
class Task
{
public:
	Task(string n, string d, bool ic = false)
	{
		name = n;
		description = d;
		isComplete = ic;
	}

	string name;
	string description;
	bool isComplete;
};

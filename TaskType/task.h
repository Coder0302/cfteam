#include "../mainHeader.h"
class Task
{
public:
	Task(string n, string d)
	{
		name = n;
		description = d;
		isComplete = false;
	}

	string name;
	string description;
	bool isComplete;
};

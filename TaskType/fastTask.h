#include "../mainHeader.h"
class FastTask : public Task
{
public:
	FastTask(string n, string d, bool ic = false, int m = 0, int e = 0) : Task(n, d, ic)
	{
		money = m;
		exp = e;
	}
	
	int money;
	int exp;
};

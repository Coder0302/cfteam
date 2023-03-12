#include "../mainHeader.h"

class TasksManager
{
public:
	void addFastTask(string n, string d)
	{
		USER.fastTasks.push_back(FastTask(n, d));
	}
	
	void removeFastTask(int numTask)
	{
		USER.fastTasks.erase(USER.fastTasks.cbegin() + numTask);
	}
	
	void completeFastTask(int numTask)
	{
		USER.fastTasks[numTask].isComplete = true;
	}
	
	string getListAllFastTasks()
	{
		string list = "\n";
		for (int i = 0; i < USER.fastTasks.size(); i++)
		{
			string f = "[-]";
			if (USER.fastTasks[i].isComplete)
				f = "[+]";
			list += to_string(i+1) + ") " + f + "\nНазвание: " + USER.fastTasks[i].name + "\nОписание: " + USER.fastTasks[i].description + "\n";
		}
		return list;
	}
	
}taskManager;

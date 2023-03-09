#include "../mainHeader.h"

class TasksManager
{
private:
	vector<FastTask> fastTasks;
	vector<DailyTask> dailyTasks;
public:
	void addFastTask(string n, string d)
	{
		fastTasks.push_back(FastTask(n, d));
	}
	
	void removeFastTask(int numTask)
	{
		fastTasks.erase(fastTasks.cbegin() + numTask);
	}
	
	void completeFastTask(int numTask)
	{
		fastTasks[numTask].isComplete = true;
	}
	
	string getListAllFastTasks()
	{
		cout << "\n";
		string list = "";
		for (int i = 0; i < fastTasks.size(); i++)
		{
			list += (fastTasks[i].isComplete?"[+]":"[-]") + to_string(i) + ") " + fastTasks[i].name + "\n" + fastTasks[i].description + "\n";
		}
		return list;
	}
	
}taskManager;

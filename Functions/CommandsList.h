#include "../mainHeader.h"

struct BaseCommand
{
	BaseCommand(vector<string> _cmds, string _description, string(*_func)(string))
	{
		cmds = _cmds;
		description = _description;
		func = _func;
	}
	vector<string> cmds;
	string description;
	string(*func)(string);
};

vector<BaseCommand> cmdList;
	
	
	
string help(string s)
{
	string list = "";
	for (int i = 0; i < cmdList.size(); i++)
	{
		string cmdVariants = "";
		for (int j = 0; j < cmdList[i].cmds.size(); j++)
		{	
			cmdVariants += cmdList[i].cmds[j] + "; ";
		}
		list += "\n" + to_string(i+1) + ". " + cmdVariants + " - " + cmdList[i].description;
	}
	return list;
}

string addFastTask(string s)
{
	string n = s.substr(0, s.find(" "));
	string d = s.substr(s.find(" ")+1, s.size());
	taskManager.addFastTask(n, d);
	return "Задача добавленна!";
}
string removeFastTask(string s)
{
	taskManager.removeFastTask(stoi(s));
	return "Задача удалена!";
}
string completeFastTask(string s)
{
	taskManager.completeFastTask(stoi(s));
	return "Задача выполнена!";
}
string listFastTask(string s)
{
	return taskManager.getListAllFastTasks();
}

string quit(string s)
{
	exit(0);
	return "Удачного дня Герой!";
}


	
vector<BaseCommand> getListCommands()
{
	cmdList.clear();
	cmdList.push_back(BaseCommand({"help", "h"}, "Выводит список всех комманд", help));
	cmdList.push_back(BaseCommand({"quit", "q"}, "Выходит из приложения", quit));
	cmdList.push_back(BaseCommand({"addFastTask", "aft"}, "Добавляет временную задачу", addFastTask));
	cmdList.push_back(BaseCommand({"removeFastTask", "rft"}, "Удаляет временную задачу", removeFastTask));
	cmdList.push_back(BaseCommand({"completeFastTask", "cft"}, "Отмечает временную задачу как выполненная", completeFastTask));
	cmdList.push_back(BaseCommand({"listFastTask", "list"}, "Выводит список всех задач", listFastTask));
	return cmdList;
}

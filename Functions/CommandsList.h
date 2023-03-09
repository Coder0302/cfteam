#include "../mainHeader.h"

struct BaseCommand
{
	BaseCommand(vector<string> _cmds, string _description, string(*_func)())
	{
		cmds = _cmds;
		description = _description;
		func = _func;
	}
	vector<string> cmds;
	string description;
	string(*func)();
};

vector<BaseCommand> cmdList;
	
string help()
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
string quit()
{
	exit(0);
	return "Удачного дня Герой!";
}

vector<BaseCommand> getListCommands()
{
	cmdList.clear();
	cmdList.push_back(BaseCommand({"help", "h"}, "Выводит список всех комманд", help));
	cmdList.push_back(BaseCommand({"quit", "q"}, "Выходит из приложения", quit));
	return cmdList;
}

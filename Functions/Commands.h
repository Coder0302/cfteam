#include "../mainHeader.h"

string ExecuteCommand(string str)
{
	string result = "Прости меня, я не понимаю что ты хочешь.\n Ты можешь написать help и узнать что я точно смогу сделать!";
	
	vector<BaseCommand> cmdList;
	cmdList = getListCommands();
	for (int i = 0; i < cmdList.size(); i++)
	{
		for (string c : cmdList[i].cmds)
		{
			string cmd = str.substr(0, str.find(" "));
			if (c == cmd)
			{
				return cmdList[i].func(str.substr(str.find(" ")+1, str.size()));
			}
		}
	}
	return result;
}

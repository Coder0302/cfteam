#include "../mainHeader.h"

string ExecuteCommand(string cmd)
{
	string result = "Прости меня, я не понимаю что ты хочешь.\n Ты можешь написать help и узнать что я точно смогу сделать!";
	
	vector<BaseCommand> cmdList;
	cmdList = getListCommands();
	for (int i = 0; i < cmdList.size(); i++)
	{
		for (string c : cmdList[i].cmds){
			if (c == cmd)
			{
				result = cmdList[i].func();
				break;
			}
		}
	}
	return result;
}

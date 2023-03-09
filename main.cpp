#include "mainHeader.h"

int main()
{
	cout << "Приветствую герой! Для ознакомления с моим функционалом вы можете ввести комманду help\n";
	bool isExit = false;
	while (!isExit)
	{
		string cmd;
		cout << "Герой: ";
		getline(cin, cmd);
		string answer = ExecuteCommand(cmd);
		cout << "Компьютер: " << answer << endl;
	}
	return 0;
}

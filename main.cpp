#include "mainHeader.h"

int main()
{
	srand(time(NULL));
	
	MainSave::LoadFromFile();
	
	Profile p = Profile();
	p.InitNewUser(&p);
	
	cout << "Приветствую герой! Для ознакомления с моим функционалом вы можете ввести комманду \"aa\"\n";
	bool isExit = false;
	while (!isExit)
	{
		string cmd;
		cout << "Герой: ";
		getline(cin, cmd);
		system("clear");
		string answer = ExecuteCommand(cmd);
		cout << "Арториус: " << answer << endl;
		USER.SaveInfo();
		MainSave::SaveInFile();
	}
	return 0;
}

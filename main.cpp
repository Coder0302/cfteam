#include "mainHeader.h"

int main()
{
	srand(time(NULL));
	
	MainSave::LoadFromFile();
	
	Profile p = Profile();
	p.InitNewUser(&p);
	
	cout << "О, привет авантюрист, меня зовут Арториус, как ты уже понял, я тут отвечаю почти за всё в нашей маленькой гильдии. Так как ты здесь новенький, тебе нужно для начала зарегистрироваться в гильдии. Такс... Дорогой авантюрист, подскажи, как тебя зовут?" << endl;
	
	getline(cin, USER.name);
	USER.isUserInit = true;
	USER.SaveInfo();
	
	cout << "Ну что же... Все бумаги я составил, приветствую тебя в нашей гильдии!\nДавай я проведу тебе краткий экскурс?\n";
	cout << ExecuteCommand("aa") << endl;
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
	}
	return 0;
}

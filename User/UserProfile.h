#include "../mainHeader.h"
class Profile
{
private:
	inline static Profile *_profile = NULL;
public:
// Локальная информация
	string name;
	int money;
	int exp;
	vector<FastTask> fastTasks;
	vector<DailyTask> dailyTasks;
	bool isUserInit;
// Информация аккаунта
	string email;
	string password;
	
	Profile(){}
	
	void InitNewUser(Profile* _p)
	{
		if (MainSave::GetSave("isUserInit")=="true")
		{
			LoadInfo();
		}
		else
		{
			name = to_string(rand());
			money = 0;
			exp = 0;
			isUserInit = true;
		}
		_profile = _p;
	}
	
	void AddMoney(int addMoneyCount)
	{
		money += addMoneyCount;
	}
	
	void AddExp(int addExp)
	{
		exp += addExp;
	}
	
	void SaveInfo()
	{
		MainSave::SetSave("name", name);
		MainSave::SetSave("money", to_string(money));
		MainSave::SetSave("exp", to_string(exp));
		MainSave::SetSave("isUserInit", (isUserInit?"true":"false"));
		
		// Saving Fast Tasks
		string saveFT = "";
		for (FastTask ft : fastTasks)
		{
			string b = (ft.isComplete?"True":"False");
			saveFT += ft.name + "♡" + ft.description + "♢" + b + "♤";
		}
		MainSave::SetSave("FastTaskSave", saveFT);
	}
	
	void LoadInfo()
	{
		name = MainSave::GetSave("name");
		money = stoi(MainSave::GetSave("money"));
		exp = stoi(MainSave::GetSave("exp"));
		isUserInit = (MainSave::GetSave("isUserInit")=="true"?true:false);
		
		// Loading Fast Tasks
		string saveFT = MainSave::GetSave("FastTaskSave");
		while (saveFT.find("♤") != -1 && saveFT != "")
		{
			string n = saveFT.substr(0, saveFT.find("♡"));
			string d = saveFT.substr(int(saveFT.find("♡"))+1,saveFT.find("♢"));
			bool b = (saveFT.substr(int(saveFT.find("♢"))+1, saveFT.find("♤"))=="True"?true:false);
			saveFT = saveFT.substr(int(saveFT.find("♤"))+1);
			fastTasks.push_back(FastTask(n, d, b));
		}
	}
	
	static Profile* GetUser()
	{
		return _profile;
	}
};

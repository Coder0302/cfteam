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
		
		MainSave::SetSave("FastTaskSaveCount", to_string(fastTasks.size()));
		
		// Saving Fast Tasks
		string saveFT = "";
		for (int i = 0; i < fastTasks.size(); i++)
		{
			MainSave::SetSave("FastTaskSaveName" + to_string(i), fastTasks[i].name);
			MainSave::SetSave("FastTaskSaveDescr" + to_string(i), fastTasks[i].description);
			MainSave::SetSave("FastTaskSaveIsComplete" + to_string(i),(fastTasks[i].isComplete?"True":"False"));
		}
		
		MainSave::SaveInFile();
		
		OnlineSaves::UploadSave();
	}
	
	void LoadInfo()
	{	
		OnlineSaves::DownloadSave();
		
		MainSave::LoadFromFile();
		
		name = MainSave::GetSave("name");
		money = stoi(MainSave::GetSave("money"));
		exp = stoi(MainSave::GetSave("exp"));
		isUserInit = (MainSave::GetSave("isUserInit")=="true"?true:false);
		// Loading Fast Tasks
		int count = stoi(MainSave::GetSave("FastTaskSaveCount"));
		for (int i = 0; i < count; i++)
		{
			string n = MainSave::GetSave("FastTaskSaveName" + to_string(i));
			string d = MainSave::GetSave("FastTaskSaveDescr" + to_string(i));
			bool b = (MainSave::GetSave("FastTaskSaveIsComplete" + to_string(i))=="True"?true:false);
			fastTasks.push_back(FastTask(n, d, b));
		}
	}
	
	void CreateCloudAccount(string e, string p)
	{
		string s = e + "\n" + p;
		ofstream out(".saves/account.save");
    	out << s;
    	out.close();
	}
	
	static Profile* GetUser()
	{
		return _profile;
	}
};

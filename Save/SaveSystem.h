#include "../mainHeader.h"
#define BASE_FILE_PATH ".saves/save.save"

class MainSave
{
private:
	inline static vector<pair<string, string>> allSaves;
public:
	static void SetSave(string key, string value)
	{
		bool isContain = false;
		for (int i = 0; i < allSaves.size(); i++)
		{
			if (allSaves[i].first == key)
			{
				allSaves[i].second = value;
				isContain = true;
				break;
			}
		}
		
		if (!isContain)
		{
			allSaves.push_back(pair(key, value));
		}
	}
	
	static string GetSave(string key)
	{
		string val = "";
		for (int i = 0; i < allSaves.size(); i++)
		{
			if (allSaves[i].first == key)
			{
				val = allSaves[i].second;
				break;
			}
		}
		return val;
	}
	
	static void SaveInFile(string filePath = BASE_FILE_PATH)
	{
		if (!filesystem::exists(".saves/"))
			filesystem::create_directory(".saves/");
	
		string s = "";
	
		ofstream out(filePath);
    	if (out.is_open())
    	{
    		for (int i = 0; i < allSaves.size(); i++)
    		{
    			s += allSaves[i].first + char('♥') + allSaves[i].second + "\n";
    		}
    	}
    	out << s;
    	out.close();
	}
	
	static void LoadFromFile(string filePath = BASE_FILE_PATH)
	{
		allSaves.clear();	
	
		std::string line;
	    std::ifstream in(filePath); // окрываем файл для чтения
    	if (in.is_open())
  		{
    	    while (getline(in, line) && line != "")
        	{
            	string k = line.substr(0, line.find(char('♥')));
            	string v = line.substr(line.find(char('♥'))+1, line.size());
            	allSaves.push_back(pair(k, v));
        	}
    	}
  		in.close();
	}
};

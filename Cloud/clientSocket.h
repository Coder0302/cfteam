#include "../mainHeader.h"
#define CURRENT_IP "3.127.253.86"
#define CURRENT_PORT 10458

class OnlineSaves
{
public:
	static void DownloadSave()
	{
		
		if (filesystem::exists(".saves/account.save"))
		{
			string email, password;
			ifstream in(".saves/account.save");
			getline(in, email);
			getline(in, password);
	  		in.close();
			
			int fd = socket(AF_INET, SOCK_STREAM, 0);
			struct sockaddr_in adr = {0};
			adr.sin_family = AF_INET;
			adr.sin_port = htons(CURRENT_PORT);
			inet_pton(AF_INET, CURRENT_IP, &adr.sin_addr);
			socklen_t adrlen = sizeof adr;
			connect(fd, (struct sockaddr *) &adr, adrlen);
			write(fd, ("get!email#" + email + "\npassword#" + password).c_str(), 21 + email.size() + password.size()); //get!f030204@mail.ru!030204
			char buf[512];
			ssize_t nread;
			nread = read(fd, buf, 512);
			shutdown(fd, SHUT_RDWR);
			
			if (!filesystem::exists(".saves/"))
				filesystem::create_directory(".saves/");
			string s(buf);
			ofstream out(BASE_FILE_PATH);
			out << s;
			out.close();
		}
	}
	
	static void UploadSave()
	{
		if (filesystem::exists(".saves/account.save"))
		{
			string email, password;
			ifstream in(".saves/account.save");
			getline(in, email);
			getline(in, password);
	  		in.close();
		
			string str, line;
			ifstream ins(BASE_FILE_PATH);
			while (getline(ins, str))
		    {
		        line += str + "\n";
		    }
	  		ins.close();
		
			int fd = socket(AF_INET, SOCK_STREAM, 0);
			struct sockaddr_in adr = {0};
			adr.sin_family = AF_INET;
			adr.sin_port = htons(CURRENT_PORT);
			inet_pton(AF_INET, CURRENT_IP, &adr.sin_addr);
			socklen_t adrlen = sizeof adr;
			connect(fd, (struct sockaddr *) &adr, adrlen);
			write(fd,("set!email#" + email + "\npassword#" + password+"\n"+line).c_str(), 22 + email.size() + password.size() + line.size());
			shutdown(fd, SHUT_RDWR);
		}
	}
};

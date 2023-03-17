#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <filesystem>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

#define BASE_FILE_PATH ".saves/save.save"
#define USER (*Profile::GetUser())

#include "Save/SaveSystem.h"

#include "TaskType/task.h"
#include "TaskType/fastTask.h"
#include "TaskType/dailyTask.h"

#include "Cloud/clientSocket.h"

#include "User/UserProfile.h"

#include "TaskType/tasksController.h"

#include "Functions/CommandsList.h"
#include "Functions/Commands.h"

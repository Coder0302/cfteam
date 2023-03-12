#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <filesystem>
using namespace std;

#define USER (*Profile::GetUser())

#include "Save/SaveSystem.h"

#include "TaskType/task.h"
#include "TaskType/fastTask.h"
#include "TaskType/dailyTask.h"

#include "User/UserProfile.h"

#include "TaskType/tasksController.h"

#include "Functions/CommandsList.h"
#include "Functions/Commands.h"

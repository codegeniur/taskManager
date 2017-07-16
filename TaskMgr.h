#ifndef _TASKMGR_H_
#define _TASKMGR_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class TaskMgr {

public:

TaskMgr(string filename="task.txt");
// Contructor
// @pre: none
// @post: _taskTxt has a filename

~TaskMgr();
// Destructor

void createTask();
// aim: ask for task name, check that validity of input
// @pre: no
// @post: if task name is valid, a task is added to the list
// note: duplicated task is not check yet

void editTask();
// aim: edit content of pre-existing task
// @pre: there are tasks in the list
// @post: task is edited or error is signaled
// note: duplicated task is not check yet

void deleteTask();
// aim: remove task from its list
// @pre: there are tasks in the list
// @post: task is removed or error is signaled

void listTask();
// aim: print tasks
// @pre: there are tasks in the list
// @post: all the tasks are printed or error is signaled

void saveTask();
// aim: save task list into a text file
// @pre: there are tasks in the list
// @post: txt file is saved or error is signaled


private:
vector<string> _taskList;
string _taskTxt;
string getTaskName();

};

#endif


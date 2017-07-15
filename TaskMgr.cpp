#include "TaskMgr.h"

TaskMgr::TaskMgr(string filename)
{
	_taskTxt = filename;
} 

TaskMgr::~TaskMgr() {}
// Destructor

void TaskMgr::createTask()
{
	string task = getTaskName();
	if( task.empty() )
	{
		cout << "\nEmpty string!\n";
	}
	else
	{
		cout << "New task '"<< task <<"' created :)\n";
		_taskList.push_back(task);		
	}
}

void TaskMgr::editTask()
{
	listTask();
	if(!_taskList.empty())
	{
		int taskIndex;
		cout << "Task to be edited: ";
		cin >> taskIndex;
		cin.ignore(999,'\n');

		if( cin.fail())
		{
			cin.clear();
			cout << "Please key in integers!\n";
		}
		else if( taskIndex <= _taskList.size() && taskIndex > 0 )
		{	// valid task index
			cout << "Task to be edited: " << _taskList[taskIndex-1] << "\n";
			string editedTask = getTaskName();
			if(!editedTask.empty())
			{
				cout << "Task edited from '"<< _taskList[taskIndex-1] << "' to '" << editedTask << "' :) \n";
				_taskList[taskIndex-1] = editedTask;
			}
			else
			{
				cout << "Empty string, please key in something!\n";
			}
		}
		else
		{
			cout << "Invalid task number!\n";
		}
	}
}
void TaskMgr::deleteTask()
{
	listTask();
	if(!_taskList.empty())
	{
		int taskIndex;
		cout << "Key in task to be deleted: ";
		cin >> taskIndex;
		cin.ignore(999,'\n');

		if( cin.fail() )
		{
			cin.clear();
			cout << "Cin failure!\n";
		}
		else if( taskIndex <= _taskList.size() && taskIndex > 0 )
		{
			char yn;
			cout << "Proceed deleting (y/n)? [y]\n";
			cin >> yn;
			cin.ignore(999,'\n');
			if(yn == 'y' || yn == '\n')
			{
				cout << "Task '" << _taskList[taskIndex-1] << "' has been deleted\n";
				_taskList.erase(_taskList.begin()+(taskIndex-1));
			}
			else
			{
				cout << "Deletion canceled\n";
			}
		}
		else
		{
			cout << "Invalid task number!\n";
		}
	}
}
void TaskMgr::listTask()
{
	if(_taskList.empty())
	{
		cout << "No tasks\n";
	}
	else
	{
		cout << "Task lists:\n";
		for(int i=0; i<_taskList.size(); i++ )
		{
			cout << i+1 << ". " << _taskList[i] << "\n";
		}
	}
}
void TaskMgr::saveTask()
{
	ofstream myfile;
  	myfile.open(_taskTxt);
	if(_taskList.empty())
	{
		cout << "No file save\n";
	}
	else
	{
		cout << "File saved\n";
		for(int i=0; i<_taskList.size(); i++ )
		{
			myfile << i+1 << ". " << _taskList[i] << "\n";
		}
	}  	
	myfile.close();
}

string TaskMgr::getTaskName()
{
	char input[50];
	string ret;
	cout << "Key in new task name: ";
	cin.getline(input,sizeof(input));
	ret = input;
	return ret;
}

#include <iostream>
#include <string>
#include "TaskMgr.h"

using namespace std;

// variable definition
char option='0';

static bool processMenu();
void printMenu();

int main(void)
{
	cout << "Welcome to Task Manager 1.0!\n";
	printMenu();

	TaskMgr myTask;
	do
	{
		if( processMenu() )
		{
			switch(option)
			{
				case '1':
				{
					myTask.createTask();
				}
				break;
				case '2':
				{
					myTask.editTask();
				}
				break;
				case '3':
				{
					myTask.deleteTask();
				}
				break;
				case '4':
				{
					myTask.listTask();
				}
				break;
				case 'q':
				{
					cout << "Exit Task Manager\n\n";
				}
				break;
				case 'p':
				{
					printMenu();
				}
				break;
				default:
				{
					cout << "Invalid input!\n\n";
				}
				break;
			}
		}
	} while( option != 'q');

	myTask.saveTask();
	return 0;
}

bool processMenu()
{
	bool validOption = true;

	cout << "\nPlease key in option: ";
	cin >> option;

	if(cin.fail() )
	{
		// cin error handling		
		cin.clear();  
		cout << "cin failed!\n";
		validOption = false;
	}
	else if( cin.peek() != '\n' )
	{
		// Program shall recognizes only single character option
		cout << "Please key in single character option!\n";
		validOption = false;
	}
	cin.ignore(999,'\n');

	return validOption;
}

void printMenu()
{
	cout << "\n****** Task Manager *********\n";
	cout << "1: Create Task\n";
	cout << "2: Edit Task\n";
	cout << "3: Delete Task\n";
	cout << "4: List Task\n";
	cout << "p: Menu\n";
	cout << "q: Quit\n";	
	cout << "*****************************\n";
}
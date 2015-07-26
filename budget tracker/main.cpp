#include<iostream>
#include<string>
#include"Interface.h"

using namespace std;
int main()
{
	
	
	Interface* userInterface = new Interface();
	string input = "";
	cout << "Welcome to Budget Tracker." << endl;
	
	do
	{
		cout << "******************************************" << endl;
		cout << "Please select one of the options below." << endl;
		cout << "1. Add an item." << endl;
		cout << "2. Remove and item." << endl;
		cout << "3. Display all itmes." << endl;
		cout << "4. Save changes." << endl;
		cout << "Q. Quit." << endl;
		cout << "******************************************" << endl;
		cin >> input;
		cin.sync();
		if (input == "1")
		{
			userInterface->add();
		}
		else if (input == "2")
		{
			if (!userInterface->remove())
				cout << "No item was removed." << endl;
		}
		else if (input == "3")
		{
			userInterface->displayAll();
		}
		else if (input == "4")
		{
			userInterface->save();
			cout << "<<saved>>" << endl;
			
		}
	} while (input != "Q");
	
	
	return 0;
}
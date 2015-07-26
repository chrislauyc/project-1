#include"Interface.h"

Interface::Interface()
{
	book = new Budget_book();
	book->readin();

}
void Interface::displayAll()
{
	stringstream ss;
	ss << "Total budget: " << book->get_Balance() << endl;
	ss << "Total income: " << book->get_Total_income() << endl;
	ss << "Total expense: " << book->get_Total_expense() << endl;
	ss << "Incomes: " << endl;
	for (int i = 0; i < book->get_Incomes().size(); i++)
	{
		ss << i << ". " << book->get_Incomes()[i]->get_Name() << endl;
		ss << book->get_Incomes()[i]->get_Amount() << endl;
		ss << book->get_Incomes()[i]->get_Time() << endl;

	}
	
	ss << "Expenses: " << endl;
	for (int i = 0; i < book->get_Expenses().size(); i++)
	{
		ss << i + book->get_Incomes().size() << ". ";
		ss << book->get_Expenses()[i]->get_Name() << endl;
		ss << book->get_Expenses()[i]->get_Amount() << endl;
		ss << book->get_Expenses()[i]->get_Time() << endl;

	}
	//this part set the display vector up so that remove() can be used. 
	display.clear();
	display = book->get_Incomes();
	for (auto s : book->get_Expenses())
	{
		display.push_back(s);
	}
	cout << ss.str();
}
bool Interface::add()
{
	string name;
	cout << "Enter the title of the entry: ";
	
	getline(cin, name);
	cout << "Enter the amount: ";
	double amount;
	cin >> amount;
	cin.sync();
	cout << "Enter the time(mm/dd/yy): ";
	string time;
	getline(cin, time);
	cout << "Is this an income or expense? ";
	string answer;
	cin >> answer;
	cin.sync();
	if (answer == "income")
	{
		if (book->add_Income(name, amount, time))
		{
			cout << "Item added." << endl;
			return true;
		}
	}

	else if (answer == "expense")
	{
		if (book->add_Expense(name, amount, time))
		{
			cout << "Item added." << endl;
			return true;
		}
	}
	
	cout << "Item is not added." << endl;
	return false;
}
bool Interface::remove()
{
	if (!display.empty())
	{
		cout << "Enter the index of the item you wish to delete. ";
		int input;
		cin >> input;
		return book->delete_Items(display[input]);
	}
	else
	{
		displayAll();
		return false;
	}
}
void Interface::save()
{
	book->writeout();
}
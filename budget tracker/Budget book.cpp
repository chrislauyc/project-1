#include"Budget book.h"
bool Budget_book::find_remove(Items* &to_Delete, vector<Items*> &the_vector)
{
	for (int i = 0; i < the_vector.size(); i++)
	{
		if (the_vector[i] == to_Delete)
		{
			the_vector[i] = NULL;
			the_vector[i] = the_vector[the_vector.size()-1];
			the_vector.pop_back();
			delete to_Delete;
			to_Delete = NULL;
			return true;
		}
	}
	return false;
	
}
Budget_book::Budget_book()
{
	balance = 0;
	total_income = 0;
	total_expense = 0;

}
bool Budget_book::add_Income(string category, double amount, string time)
{	
	balance += amount;
	total_income += amount;
	for (auto s : incomes)
	{
		if (s->get_Name() == category)
			return false;
	}

	Items* new_Item = new Items(category, amount, time);
	incomes.push_back(new_Item);
	return true;
}
bool Budget_book::add_Expense(string category, double amount, string time)
{
	balance -= amount;
	total_expense += amount;
	for (auto s : expenses)
	{
		if (s->get_Name() == category)
			return false;
	}
	Items* new_Item = new Items(category, amount, time);
	expenses.push_back(new_Item);
	return true;
}
double Budget_book::get_Balance()
{
	return balance;
}
double Budget_book::get_Total_expense()
{
	return total_expense;
}
double Budget_book::get_Total_income()
{
	return total_income;
}
vector<Items*> Budget_book::get_Incomes()
{
	return incomes;
}
vector<Items*> Budget_book::get_Expenses()
{
	return expenses;
}

bool Budget_book::delete_Items(Items* to_Delete)
{
	if (find_remove(to_Delete, incomes))
		return true;
	else if(find_remove(to_Delete, expenses))
		return true;
	else
		return false;
	
}
void Budget_book::readin()
{
	ifstream file;
	file.open("saves.txt");
	if (file.is_open())
	{
		string temp;
		getline(file, temp);
		double balance_temp = stod(temp);
		getline(file, temp);
		double total_income_temp = stod(temp);
		getline(file, temp);
		double total_expense_temp = stod(temp);
	
		while (getline(file,temp))
		{
			string name = temp;
			double amount;
			string time;
			getline(file, temp);
			amount = stod(temp);			
			getline(file, temp);			
			time = temp;
			if (amount > 0)
				add_Income(name, amount, time);
			else
				add_Expense(name, -amount, time);
			balance = balance_temp;
			total_income = total_income_temp;
			total_expense = total_expense_temp;
		}
	}

	file.close();
}
void Budget_book::writeout()
{
	ofstream file;
	remove("saves.txt");
	file.open("saves.txt");
	file << balance << endl << total_income << endl << total_expense << endl;//chnaged
	for (int i = 0; i < incomes.size(); i++)
	{
		file << incomes[i]->get_Name() << endl;		
		file << "+" << incomes[i]->get_Amount() << endl;
		file << incomes[i]->get_Time() << endl;
	}
	for (int i = 0; i < expenses.size(); i++)
	{
		file << expenses[i]->get_Name() << endl;
		file << "-" << expenses[i]->get_Amount() << endl;
		file << expenses[i]->get_Time() << endl;
	}
	file.close();
}
vector<Items*> Budget_book::get_month_Incomes(int month)
{
	vector<Items*> output;
	for (auto s : incomes)
	{
		if (month == s->get_Month())
			output.push_back(s);
	}
	return output;
}
vector<Items*> Budget_book::get_month_Expenses(int month)
{
	vector<Items*> output;
	for (auto s : expenses)
	{
		if (month == s->get_Month())
			output.push_back(s);
	}
	return output;
}
#pragma once
#include<vector>
#include<fstream>
#include<sstream>
#include<string>

#include"Items.h"
using namespace std;
class Budget_book
{
private:
	double balance;
	double total_income;
	double total_expense;
	vector<Items*> incomes;
	vector<Items*> expenses;
	bool find_remove(Items* &to_Delete, vector<Items*> &the_vector);


public:
	Budget_book();
	~Budget_book(){}
	bool add_Income(string category, double amount, string time);
	bool add_Expense(string category, double amount, string time);
	double get_Balance();
	double get_Total_income();
	double get_Total_expense();
	vector<Items*> get_Incomes();
	vector<Items*> get_Expenses();
	
	bool delete_Items(Items* to_Delete);
	void readin();
	void writeout();
	vector<Items*> get_month_Incomes(int month);
	vector<Items*> get_month_Expenses(int month);



};
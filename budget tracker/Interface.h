#pragma once
#include<iostream>
#include<sstream>
#include"Budget book.h"
#include"Items.h"
using namespace std;
class Interface
{
private:
	Budget_book* book;
	vector<Items*> display;
public:
	Interface();
	~Interface(){ delete book; }
	void displayAll();
	bool add();
	bool remove();
	void save();
};
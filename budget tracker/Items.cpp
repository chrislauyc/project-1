#pragma once
#include "Items.h"

Items::Items(string name, double money, string time)
{
	category = name;
	amount = money;
		date = time;
		day = stod(time.substr(0, 1));
		month = stod(time.substr(3, 1));
		year = stod(time.substr(6, 1));
		

	
}
string Items::get_Time()
{
	return date;
}

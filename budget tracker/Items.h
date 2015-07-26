#pragma once
#include<iostream>
#include<string>
using namespace std;
class Items
{
private:
	
	string category;
	double amount;
	string date;
	int year;
	int month;
	int day;
public:
	Items(string name, double money,string time);
	~Items(){}
	string get_Time();
	int get_Month(){ return month; }
	int get_Year(){ return year; }
	int get_Day(){ return day; }
	string get_Name(){ return category; }
	double get_Amount(){ return amount; }
};
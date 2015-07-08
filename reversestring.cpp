#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	string input;
	getline(cin, input);
	stack<char> temp;
	for (auto s : input)
	{
		temp.push(s);
	}
	for (int i = 0; i < input.length(); i++)
	{
		input[i] = temp.top();
		temp.pop();
	}
	cout << input << endl;



	//system("pause()");
	return 0;

}
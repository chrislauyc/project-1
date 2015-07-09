#include <iostream>

using namespace std;
long long int ExpoRecur(int a, int b)// everytime the function is called, the exponent is cut down in half
{
	if (b == 1)
	{
		return a;
	}
	else
	{
		if (b % 2 == 0)
		{
			long long int i = ExpoRecur(a, b / 2); // dealing with an even number
			return i*i;
		}
		else
		{
			long long int i = ExpoRecur(a, (b - 1) / 2);// dealing with an odd number
			return i*i*a;
		}
	}
	
}
int main()
{
	int a;
	int b;
	cout << "For a^b , please enter the first integer.\n";
	cin >> a;
	cout << "Please enter the second integer.\n";
	cin >> b;
	cout << "The result of a^b is: " << ExpoRecur(a, b) << endl; 
	cout << pow((double)a, (double)b) << endl;
	system("pause(0)");
	return 0;
}
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string word;
	cout << "Please enter your sentence or word." << endl;
	getline(cin, word);
	int countA = 0;
	int countE = 0;
	int countI = 0;
	int countO = 0;
	int countU = 0;
	for (auto s : word)
	{
		s = tolower(s);
		switch (s)
		{
		case 'a':
			countA++;
			break;
		case'e':
			countE++;
			break;
		case'i':
			countI++;
			break;
		case'o':
			countO++;
			break;
		case'u':
			countU++;
			break;

		}
	}
	cout << "Number of A(s): " << countA << endl;
	cout << "Number of E(s): " << countE << endl;
	cout << "Number of I(s): " << countI << endl;
	cout << "Number of O(s): " << countO << endl;
	cout << "Number of U(s): " << countU << endl;

	
	return 0;
}

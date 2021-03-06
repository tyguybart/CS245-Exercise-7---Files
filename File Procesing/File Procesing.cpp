// File Procesing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

void printTableHeader()
{
	cout << "Artist ID: " << fields <<
}

vector<string> splitString(string text, char sep)
{
	string field;
	vector<string> fields;
	
	stringstream inputStr(text);

	while (getline(inputStr, field, sep))
		fields.push_back(field);

	return fields;
}

int main()
{
	string line;
	ifstream input("Exercise 7.txt", ios::in);
	vector<string> fields;

	if (!input)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	printTableHeader();

	while (getline(input, line))
	{
		fields.push_back(splitString(line, '\t'));

		if (fields.size() == 4)
		{
			int artitstID = stoi(fields[0]);
			string name = fields[1];
			string hometown = fields[2];
			string homestate = fields[3];

			cout << name << " from " << hometown << ", " << homestate << "\n" << endl;
		}
	}

	input.close();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

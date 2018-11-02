/*******************************************************************************************
* Programmer: Marco Arceo
* Class: CptS 122, Spring 2018; Lab Section
* Programming Assignment: PA7
* Due Date: April 4th, 2018
* Description: Characters to Morse converter
* Sources: N/A
*******************************************************************************************/
#pragma once
#include "BST.h"
#include <Windows.h>

class Wrapper
{
public:

	void Wrapper::runApp()
	{ // Used the same menu outline as my previous PA 4
		bool flag = true;
		int option = 0;
		ifstream infile;
		infile.open("Convert.txt");

		while (flag)
		{
			do
			{
				option = determineOption();
				switch (option)
				{
				case 1:
					Tree.printTree(); // Prints the tree 
					cout << "\n";
					system("pause");
					system("cls");
					break;

				case 2:
					cout << "Morse Code: ";
					Tree.readConvert(infile); // Reads the file and converts it to morse code
					cout << "\n";
					system("pause");
					system("cls");
					break;

				case 3:
					cout << "Goodbye!" << endl;
					Sleep(3000);
					flag = false;
					break;
				}
				system("cls");
			} while (option > 0 && option < 3);
		}
	}

private:
	BST Tree;

	void Wrapper::displayMenu()
	{ // Displays the menu
		cout << "1.) Print out the tree" << endl;
		cout << "2.) Convert the text file to MorseCode" << endl;
		cout << "3.) Exit" << endl;
	}

	int Wrapper::getOption()
	{ // Gets the users option
		int option = 0, status = 0;
		cout << "\nEnter your option: ";
		cin >> option;
		status = option;
		if (status = 0)
		{
			cout << "Failed at reading the option" << endl;
		}
		return option;
	}

	int Wrapper::determineOption()
	{ // Determines if the option is valid
		int option = 0;

		do
		{
			displayMenu();
			option = getOption();
			system("cls");
		} while ((option < 1) || (option > 3));

		return option;
	}
};
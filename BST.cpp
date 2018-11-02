/*******************************************************************************************
* Programmer: Marco Arceo
* Class: CptS 122, Spring 2018; Lab Section
* Programming Assignment: PA7
* Due Date: April 4th, 2018
* Description: Characters to Morse converter
* Sources: O'Fallon class code, codescracker.com, FIZ TA, Github
*******************************************************************************************/
#include "BST.h"

BST::BST()
{
	this->mpRoot = nullptr;
	ifstream file;
	file.open("MorseTable.txt");

	while (!file.eof())
	{
		string strCharacter;
		string Morse;
		getline(file, strCharacter, '!');
		getline(file, Morse, '\n');
		const char *Character = strCharacter.c_str(); // Stackoverflow conversion from string to const char

		insert((*Character), Morse);
	}
	file.close();
}

void deleteTree(BSTNode * pLeaf)
{ // Got help in the Fiz to make this since my understanding of deleting was minimal for BST

	if (pLeaf != nullptr)
	{
		deleteTree(pLeaf->getLeft());
		deleteTree(pLeaf->getRight());
		delete pLeaf;
	}
}

BST::~BST()
{ // delete bottom to top, root is the last one
	deleteTree(mpRoot);
}

void BST::insert(const char &Character, const string &Morse)
{ // Public member function
	insert(this->mpRoot, Character, Morse);
}

void BST::insert(BSTNode *& pTree, const char &Character, const string &Morse)
{ // Similar to the example code given in class (Private member function)
	if (pTree == nullptr)
	{
		BSTNode *pMem = new BSTNode(Character, Morse);
		pTree = pMem;
	}
	else if (Character < pTree->getCharacter())
	{
		insert(pTree->getLeft(), Character, Morse);
	}
	else
	{
		insert(pTree->getRight(), Character, Morse);
	}
}

void BST::printTree()
{ // Same as inorderTraversal (Public member function)
	printTree(this->mpRoot);
}

void BST::printTree(BSTNode *pTree)
{ // Same as inorderTraversal (Private Member function)
	if (pTree != nullptr)
	{
		printTree(pTree->getLeft());
		cout << pTree->getCharacter() << endl;
		printTree(pTree->getRight());
	}
}

void BST::readConvert(ifstream &infile)
{ // Got some inspiration from Kellan Mebane Github

	while (!infile.eof())
	{
		string textline;
		getline(infile, textline, '\n');

		for (int index = 0; index < textline.size(); index++) // Allows me to check each char in the string separately
		{
			if (textline[index] >= 97 && textline[index] <= 122) // Convert Lowercase to Uppercase (codescracker.com)
			{
				textline[index] = textline[index] - 32; // Does the conversion
				convertTexttoMorse(this->mpRoot, textline[index]);
			}
			else
			{ // The character doesnt need to be converted into an uppercase
				convertTexttoMorse(this->mpRoot, textline[index]);
			}
		}
	}
	infile.close();
}

void BST::convertTexttoMorse(BSTNode * pTree, const char &textline)
{
	if (textline == ' ') // If there is a space then create 3 spaces when printing
	{
		cout << "  ";
	}
	else if (pTree->getCharacter() == textline)
	{ // There is a match for the character
		cout << pTree->getMorse() << ' ';
	}
	else if (pTree->getCharacter() > textline)
	{ // No match so the program will traverse to the left
		convertTexttoMorse(pTree->getLeft(), textline);
	}
	else
	{ // No match so the program will to the right
		convertTexttoMorse(pTree->getRight(), textline);
	}
}

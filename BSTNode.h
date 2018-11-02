/*******************************************************************************************
* Programmer: Marco Arceo
* Class: CptS 122, Spring 2018; Lab Section
* Programming Assignment: PA7
* Due Date: April 4th, 2018
* Description: Characters to Morse converter
* Sources: Similar to O'Fallon class code with some slight differences
*******************************************************************************************/
#pragma once
#include <iostream>


using std::cin;
using std::cout;
using std::endl;
using std::string;

class BSTNode
{
public:
	BSTNode(const char newCharacter = '\0', const string newMorse = "");

	// getters
	BSTNode *& getLeft();
	BSTNode *& getRight();
	char getCharacter() const;
	string getMorse() const;

	// setters
	void setLeft(BSTNode * const newLeft);
	void setRight(BSTNode * const newRight);
	void setCharacter(char newCharacter);
	void setMorse(string newMorse);

private:
	string mMorse;
	char mCharacter;
	BSTNode * mpRight;
	BSTNode * mpLeft;
};
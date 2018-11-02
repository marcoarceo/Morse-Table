#pragma once

/*******************************************************************************************
* Programmer: Marco Arceo
* Class: CptS 122, Spring 2018; Lab Section
* Programming Assignment: PA7
* Due Date: April 4th, 2018
* Description: Characters to Morse converter
* Sources: O'Fallon class code, codescracker.com, FIZ TA (Elijah and Ryan), Github
*******************************************************************************************/
#include "BSTNode.h"
#include <fstream>
#include <ostream>
#include <string>

using std::ifstream;
using std::getline;


class BST
{
public:
	BST();
	~BST();
	void insert(const char &Character, const string &Morse);
	void printTree();
	void readConvert(ifstream &infile);
	void convertTexttoMorse(BSTNode * pTree, const char &textline);


private:
	BSTNode * mpRoot;
	void insert(BSTNode *& pTree, const char &Character, const string &Morse);
	void printTree(BSTNode *pTree);
};

/*******************************************************************************************
* Programmer: Marco Arceo
* Class: CptS 122, Spring 2018; Lab Section
* Programming Assignment: PA7
* Due Date: April 4th, 2018
* Description: Characters to Morse converter
* Sources: Some O'Fallon class code was used
*******************************************************************************************/
#include "BSTNode.h"

BSTNode::BSTNode(const char newCharacter, const string newMorse)
{
	mMorse = newMorse;
	mCharacter = newCharacter;
	mpLeft = nullptr;
	mpRight = nullptr;
}

BSTNode *& BSTNode::getLeft()
{
	return this->mpLeft;
}

BSTNode *& BSTNode::getRight()
{
	return this->mpRight;
}

char BSTNode::getCharacter() const
{
	return this->mCharacter;
}

string BSTNode::getMorse() const
{
	return this->mMorse;
}

void BSTNode::setLeft(BSTNode * const newLeft)
{
	this->mpLeft = newLeft;
}

void BSTNode::setRight(BSTNode * const newRight)
{
	this->mpRight = newRight;
}

void BSTNode::setCharacter(char newCharacter)
{
	this->mCharacter = newCharacter;
}

void BSTNode::setMorse(string newMorse)
{
	this->mMorse = newMorse;
}
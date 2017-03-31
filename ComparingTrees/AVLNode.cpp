// AVLNode.cpp
// Author: David Naelitz
// Written for EECS2510 Fall 2017
// Date: 3/25/2017
// Description: This is the file used to run all of the AVL node functions. This includes
// sending properties of the node back to the tree that calls it.

#include "stdafx.h"
#include "AVLNode.h"

using namespace std;

AVLNode::AVLNode()
{
}

void AVLNode::SetBalanceFactor(int BF)
{
	intBalanceChanges++;
	intBalanceFactor = BF;
}

int AVLNode::GetBalanceFactor()
{
	return intBalanceFactor;
}

int AVLNode::GetBalanceChanges()
{
	return intBalanceChanges;
}


int AVLNode::GetPointerChanges()
{
	return intPointerChanges;
}

void AVLNode::SetKeyValue(std::string chWord)
{
	strKeyValue = chWord;
}

void AVLNode::SetLeftChild(AVLNode* newNode)
{
	intPointerChanges++;
	ptrLeftChild = newNode;
}

void AVLNode::SetRightChild(AVLNode* newNode)
{
	intPointerChanges++;
	ptrRightChild = newNode;
}

AVLNode* AVLNode::GetLeftChild()
{
	return ptrLeftChild;
}

AVLNode* AVLNode::GetRightChild()
{
	return ptrRightChild;
}

string AVLNode::GetKeyValue()
{
	return strKeyValue;
}

void AVLNode::IncrementOccurences()
{
	intCount++;
}


AVLNode::~AVLNode()
{
}

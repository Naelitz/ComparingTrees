// AVL.h
// Author: David Naelitz
// Written for EECS2510 Fall 2017
// Date: 3/25/2017
// Description: This is the header file the AVL tree object

#pragma once
#include "AVLNode.h"

class AVL
{
public:
	AVL();
	~AVL();
	void Insert(std::string chWord);
	void Traverse();

	int GetPointerChanges();
	int GetComparisonCount();
	int GetHeight();
	int GetNodeCount();
	int GetBalanceChanges();
	AVLNode* Root;
private:
	AVLNode* ptrCurrentNode;
	int intPointerChanges = 0;
	int intBalanceFactorChanges = 0;
	int intNodeCount = 0;
	int intComparisonCount = 0;
	int intHeight = 0;
	void Traversal(AVLNode* startNode, int height);
};


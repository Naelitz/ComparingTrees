// BST.h
// Author: David Naelitz
// Written for EECS2510 Fall 2017
// Date: 3/25/2017
// Description: This is the header file for the binary search tree. 

#pragma once
#include "BSTNode.h"

class BST
{
public:
	void Insert(std::string chWord);
	void Traverse();
	int GetPointerChanges();
	int GetComparisonCount();
	int GetNodeCount();
	int GetHeight();
	BSTNode* Root;
	BST();
	~BST();
private:
	BSTNode* ptrCurrentNode;
	int intPointerChanges = 0;
	int intNodeCount = 0;
	int intComparisonCount = 0;
	int intHeight = 0;
	void Traversal(BSTNode* startNode, int height);
};


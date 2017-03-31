// AVLNode.h
// Author: David Naelitz
// Written for EECS2510 Fall 2017
// Date: 3/25/2017
// Description: This is the header file for the node that will be used in the AVL algorithm

#pragma once
#include <string>

class AVLNode
{
public:
	AVLNode();
	~AVLNode();
	std::string GetKeyValue();
	void SetKeyValue(std::string chWord);
	AVLNode* GetLeftChild();
	AVLNode* GetRightChild();
	void SetBalanceFactor(int BF);
	int GetBalanceFactor();
	int GetBalanceChanges();
	void SetLeftChild(AVLNode* newNode);
	void SetRightChild(AVLNode* newNode);
	void IncrementOccurences();
	int GetPointerChanges();
private:
	AVLNode* ptrLeftChild;
	AVLNode* ptrRightChild;
	std::string strKeyValue;
	int intBalanceFactor = 0;
	int intBalanceChanges = 0;
	int intCount = 1;
	int intPointerChanges = 0;
};


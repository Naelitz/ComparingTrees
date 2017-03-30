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
	int GetNodeCount();
	AVLNode* Root;
private:
	AVLNode* ptrCurrentNode;
	int intPointerChanges = 0;
	int intBalanceFactorChanges = 0;
	int intNodeCount = 0;
	int intComparisonCount = 0;
	int intHeight = 0;
	void Traversal(AVLNode* startNode);
};


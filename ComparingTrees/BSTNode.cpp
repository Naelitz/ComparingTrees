#include "stdafx.h"
#include "BSTNode.h"

using namespace std;
BSTNode::BSTNode()
{
}

BSTNode::BSTNode(string chWord)
{
	strKeyValue = chWord;
}

int BSTNode::GetPointerChanges()
{
	return intPointerChanges;
}


void BSTNode::SetKeyValue(char* chWord)
{
	strKeyValue = chWord;
}

void BSTNode::SetLeftChild(BSTNode* newNode)
{
	intPointerChanges++;
	ptrLeftChild = newNode;
}

void BSTNode::SetRightChild(BSTNode* newNode)
{
	intPointerChanges++;
	ptrRightChild = newNode;
}

BSTNode* BSTNode::GetLeftChild()
{
	return ptrLeftChild;
}

BSTNode* BSTNode::GetRightChild()
{
	return ptrRightChild;
}

string BSTNode::GetKeyValue()
{
	return strKeyValue;
}

void BSTNode::IncrementOccurences()
{
	intCount++;
}






BSTNode::~BSTNode()
{
}

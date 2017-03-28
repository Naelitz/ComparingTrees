#include "stdafx.h"
#include "AVLNode.h"

using namespace std;

AVLNode::AVLNode()
{
}

void AVLNode::SetBalanceFactor(int BF)
{
	intBalanceFactor = BF;
}

int AVLNode::GetBalanceFactor()
{
	return intBalanceFactor;
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

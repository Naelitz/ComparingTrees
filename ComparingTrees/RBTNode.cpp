// RBTNode.cpp
// Author: David Naelitz
// Written for EECS2510 Fall 2017
// Date: 3/25/2017
// Description: This is the node file for the red black tree. This allows the tree 
// to call getter and setters for the different functions needed in the tree.

#include "stdafx.h"
#include "RBTNode.h"

using namespace std;
RBTNode::RBTNode()
{
}

void RBTNode::SetKeyValue(string chWord)
{
	strKeyValue = chWord;
}

string RBTNode::GetKeyValue()
{
	return strKeyValue;
}

void RBTNode::IncrementOccurences()
{
	intCount++;
}

void RBTNode::SetColor(bool blnColor)
{
	blnColorRed = blnColor;
}

void RBTNode::SetRightChild(RBTNode* newNode)
{
	intPointerChanges++;
	RightChild = newNode;
}

void RBTNode::SetLeftChild(RBTNode* newNode)
{
	intPointerChanges++;
	leftChild = newNode;
}

void RBTNode::SetParent(RBTNode* newNode)
{
	intPointerChanges++;
	parent = newNode;
}

RBTNode* RBTNode::GetLeftChild()
{
	return leftChild;
}

RBTNode* RBTNode::GetRightChild()
{
	return RightChild;
}

RBTNode* RBTNode::GetParent()
{
	return parent;
}

void RBTNode::AddPointerChanges(int num)
{
	intPointerChanges += num;
}


int RBTNode::GetPointerChanges()
{
	return intPointerChanges;
}

bool RBTNode::IsRed()
{
	return blnColorRed;
}


RBTNode::~RBTNode()
{
}

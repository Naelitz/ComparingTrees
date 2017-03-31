// RBT.cpp
// Author: David Naelitz
// Written for EECS2510 Fall 2017
// Date: 3/25/2017
// Description: This is the RBT file that will take care of all the functions required
// for the tree. This includes inserting, balancing / rotating. Balancing in this instance
// is done by following the red black tree rules.

#include "stdafx.h"
#include "RBT.h"
#include <iostream>

using namespace std;
RBT::RBT()
{
	nil = new RBTNode();
	nil->SetKeyValue("");
	nil->SetColor(false);
	intColorChanges++;
	nil->SetLeftChild(nil);
	nil->SetRightChild(nil);
	nil->SetParent(nil);
	//Root = nil;
}

void RBT::Insert(std::string chWord)	//Insert node with key value chWord into this tree
{
	if (Root == nullptr)		//If nothing has been put in the tree yet make root and return.
	{
		Root = new RBTNode();
		Root->SetKeyValue(chWord);
		Root->SetColor(false);
		Root->SetParent(nil);
		Root->SetLeftChild(nil);
		Root->SetRightChild(nil);
		intColorChanges++;
		return;
	}
	auto z = new RBTNode();		//Create new node
	z->SetKeyValue(chWord);
	RBTNode* y = nullptr;		//y lags one step behind x (y is x's parent)
	RBTNode* x = Root;			//x searches for insertion point
	while (x != nil)
	{
		y = x;
		if (x->GetKeyValue() == chWord) //This tree allows for duplicates
		{
			//This node already exists so just increment its occurences and return
			intComparisonCount++;
			x->IncrementOccurences();
			return;
		}

		else if (z->GetKeyValue() < x->GetKeyValue())
		{
			intComparisonCount += 2;
			x = x->GetLeftChild();
		}
		else
		{
			intComparisonCount += 2;
			x = x->GetRightChild();
		}
	}
	z->SetParent(y);
	if (y == nil)	//If the Tree was empty, our new node z becomes
	{				//the new root
		intComparisonCount++;
		Root = z;
	}
	else
	{
		if (z->GetKeyValue() < y->GetKeyValue())	//Otherwise, z must be either y's new
		{											//left or right child (per BST property)
			intComparisonCount += 2;
			y->SetLeftChild(z);
		}
		else
		{
			intComparisonCount += 2;
			y->SetRightChild(z);
		}
	}
	intColorChanges++;
	z->SetLeftChild(nil);						//Our new node is at the bottom...
	z->SetRightChild(nil);						//.. of the tree, so its children are nil
	z->SetColor(true);							//Color this node red for now (may not be a safe decision)
	Fixup(z);									//Fix anything we broke.
}


void RBT::Fixup(RBTNode* startNode)
{
	//This fixes the tree after an insert incase we broke the rules for a red black tree.
	//this is handled by solving for 3 different cases.
	while (startNode->GetParent()->IsRed())
	{
		if (startNode->GetParent() == startNode->GetParent()->GetParent()->GetLeftChild())
		{
			auto y = new RBTNode();
			y = startNode->GetParent()->GetParent()->GetRightChild();
			if (y->IsRed())
			{
				intColorChanges += 3;
				startNode->GetParent()->SetColor(false);				//Case 1 (re-color only)
				y->SetColor(false);										//Case 1
				startNode->GetParent()->GetParent()->SetColor(true);	//Case 1
				startNode = startNode->GetParent()->GetParent();		//Case 1
			}
			else
			{
				if (startNode == startNode->GetParent()->GetRightChild()) //Is z the right child of its parent?
				{
					startNode = startNode->GetParent();					//Case 2
					LeftRotate(startNode);								//Case 2
				}
				//wether we have a case 2 or not we have a case 3
				intColorChanges += 2;
				startNode->GetParent()->SetColor(false);				//Case 3
				startNode->GetParent()->GetParent()->SetColor(true);	//Case 3
				RightRotate(startNode->GetParent()->GetParent());		//Case 3
			}
		}
		else   //"else" clase is symmetric to "then" clause above
		{
			auto y = new RBTNode();
			y = startNode->GetParent()->GetParent()->GetLeftChild();
			if (y->IsRed())
			{
				intColorChanges += 3;
				startNode->GetParent()->SetColor(false);
				y->SetColor(false);
				startNode->GetParent()->GetParent()->SetColor(true);
				startNode = startNode->GetParent()->GetParent();
			}
			else
			{
				if (startNode == startNode->GetParent()->GetLeftChild())
				{
					startNode = startNode->GetParent();
					RightRotate(startNode);
				}
				intColorChanges += 2;
				startNode->GetParent()->SetColor(false);
				startNode->GetParent()->GetParent()->SetColor(true);
				LeftRotate(startNode->GetParent()->GetParent());
			}
		}
	}
	intColorChanges++;
	Root->SetColor(false); //Make sure root is black according to RBT rules.
}

void RBT::RightRotate(RBTNode* z)
{
	auto y = z->GetLeftChild();
	z->SetLeftChild(y->GetRightChild());

	if (y->GetRightChild() != nil)
	{
		y->GetRightChild()->SetParent(z);
	}

	y->SetParent(z->GetParent());
	if (z->GetParent() == nil)
	{
		Root = y;
	}
	else if (z == z->GetParent()->GetRightChild())
	{
		z->GetParent()->SetRightChild(y);
	}
	else
	{
		z->GetParent()->SetLeftChild(y);
	}
	y->SetRightChild(z);
	z->SetParent(y);
}

void RBT::LeftRotate(RBTNode* z)
{
	auto y = z->GetRightChild();
	z->SetRightChild(y->GetLeftChild());

	if (y->GetLeftChild() != nil)
	{
		y->GetLeftChild()->SetParent(z);
	}

	y->SetParent(z->GetParent());
	if (z->GetParent() == nil)
	{
		Root = y;
	}
	else if (z == z->GetParent()->GetLeftChild())
	{
		z->GetParent()->SetLeftChild(y);
	}
	else
	{
		z->GetParent()->SetRightChild(y);
	}
	y->SetLeftChild(z);
	z->SetParent(y);
}

void RBT::Traverse()
{
	Traversal(Root, 1);
}

void RBT::Traversal(RBTNode* startNode, int height)
{
	//This function steps through the tree and collects the height of each tree and records the highest
	//height as the height of the tree. As it stops at each node it also gets the statistics needed from each
	//node and increments how many nodes are in the tree.
	if (startNode != nil && startNode != nullptr)
	{
		if (height > intHeight)intHeight = height;
		Traversal(startNode->GetLeftChild(), height+1);
		intPointerChanges += startNode->GetPointerChanges();
		intNodeCount++;
		Traversal(startNode->GetRightChild(), height+1);
	}
}

int RBT::GetNodeCount()
{
	return intNodeCount;
}

int RBT::GetHeight()
{
	return intHeight;
}


int RBT::GetPointerChanges()
{
	return intPointerChanges;
}

int RBT::GetComparisonCount()
{
	return intComparisonCount;
}

int RBT::GetColorChanges()
{
	return intColorChanges;
}


RBT::~RBT()
{
}

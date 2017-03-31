// BST.cpp
// Author: David Naelitz
// Written for EECS2510 Fall 2017
// Date: 3/25/2017
// Description: This is the binary search tree file that will take care of all the functions required
// for the tree. This only requires inserting and handling statistics.


#include "stdafx.h"
#include "BST.h"
#include <ostream>
#include <iostream>

using namespace std;

BST::BST()
{
}

void BST::Insert(string chWord)
{
	//This handles an insert into the BST. This compares its key at every node and follows the 
	//BST rules to place the node in the correct location
	if(Root == nullptr)
	{
		//if the tree is empty make the new node, set it as root
		Root = new BSTNode(chWord);
		intPointerChanges++;
	}
	else
	{
		//Tree was not empty so start looking at the root of the tree
		ptrCurrentNode = Root;
		while(true)//All routes lead to a break so this ensures we loop until then.
		{
			if (chWord == ptrCurrentNode->GetKeyValue())
			{
				//The tree allows duplicates so if this word already exists then just add to the count
				intComparisonCount++;
				ptrCurrentNode->IncrementOccurences();
				break;
			}
			else if (chWord < ptrCurrentNode->GetKeyValue())
			{
				//The word is less then the current node so we have to go left
				//unless we are at the end of the tree then we just make a new node
				//and attach it to the bottom of the tree.
				intComparisonCount += 2;
				if (ptrCurrentNode->GetLeftChild() == nullptr)
				{
					ptrCurrentNode->SetLeftChild(new BSTNode(chWord));
					break;
				}
				else
				{
					ptrCurrentNode = ptrCurrentNode->GetLeftChild();
				}
			}
			else//same as above but we need to go right.
			{
				intComparisonCount += 2;
				if (ptrCurrentNode->GetRightChild() == nullptr)
				{
					ptrCurrentNode->SetRightChild(new BSTNode(chWord));
					break;
				}
				else
				{
					ptrCurrentNode = ptrCurrentNode->GetRightChild();
				}
			}
		}
		
	}
}

int BST::GetPointerChanges()
{
	return intPointerChanges;
}

int BST::GetComparisonCount()
{
	return intComparisonCount;
}


int BST::GetNodeCount()
{
	return intNodeCount;
}

int BST::GetHeight()
{
	return intHeight;
}


void BST::Traverse()
{
	Traversal(Root, 1);
}


void BST::Traversal(BSTNode* startNode, int height)
{
	//This function steps through the tree and collects the height of each tree and records the highest
	//height as the height of the tree. As it stops at each node it also gets the statistics needed from each
	//node and increments how many nodes are in the tree.
	if(startNode != nullptr)
	{
		if (height > intHeight) intHeight = height;
		Traversal(startNode->GetLeftChild(), height + 1);
		intPointerChanges += startNode->GetPointerChanges();
		intNodeCount++;
		Traversal(startNode->GetRightChild(), height+ 1);
	}
}



BST::~BST()
{
}

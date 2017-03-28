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
	if(Root == nullptr)
	{
		Root = new BSTNode(chWord);
		intPointerChanges++;
	}
	else
	{
		ptrCurrentNode = Root;
		while(true)
		{
			if (chWord == ptrCurrentNode->GetKeyValue())
			{
				intComparisonCount++;
				ptrCurrentNode->IncrementOccurences();
				break;
			}
			else if (chWord < ptrCurrentNode->GetKeyValue())
			{
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
			else
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


void BST::Traverse()
{
	Traversal(Root);
}


void BST::Traversal(BSTNode* startNode)
{
	if(startNode != nullptr)
	{
		Traversal(startNode->GetLeftChild());
		intPointerChanges += startNode->GetPointerChanges();
		intNodeCount++;
		Traversal(startNode->GetRightChild());
	}
}



BST::~BST()
{
}

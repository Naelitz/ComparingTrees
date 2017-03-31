// AVL.cpp
// Author: David Naelitz
// Written for EECS2510 Fall 2017
// Date: 3/25/2017
// Description: This is the AVL tree file that will take care of all the functions required
// for the tree. This includes inserting, balancing / rotating

#include "stdafx.h"
#include "AVL.h"
#include <iostream>

using namespace std;

AVL::AVL()
{
}

void AVL::Insert(std::string chWord)
{
	//This function inserts into the tree. Doing a dumb insert at first and then fixing any 
	//balancing issues that may have arisen from the insertion.
	AVLNode* Y;
	AVLNode* A, *B, *F;
	AVLNode* P, *Q;
	AVLNode* C, *CL, *CR;
	int d;

	if (Root == nullptr)
	{
		//If the tree is empty then create the node, make it the root and return.
		Y = new AVLNode();
		Y->SetKeyValue(chWord);
		Y->SetBalanceFactor(0);
		Root = Y;
		return;
	}
	// Locate insertion point for X.
	// P scans through the tree until it falls off bottom (x previously)
	// Q is P’s parent (Q lags one step behind P) (y previously)
	// The new Node Y will be added as either the Left or Right child of Q
	// A is the last parent above Y with a BF of ±1 (before the insert)
	// F is A’s parent (F lags one step behind A)
	//

	F = Q = nullptr;	// F and Q lag, so they start NULL
	A = P = Root;		// A and P start at the root
	while (P != nullptr) // Search the tree
	{
		if (chWord == P->GetKeyValue()) // Found the word in the tree already
		{
			intComparisonCount++;		//Used a compare
			P->IncrementOccurences();
			return;
		}
		if (P->GetBalanceFactor() != 0) //Remember the last place balance factor was not 0
		{
			A = P;
			F = Q;
		}
		if (chWord < P->GetKeyValue())
		{
			intComparisonCount += 2;	//Counts the first compare it failed and this one
			Q = P;
			P = P->GetLeftChild();
		}
		else
		{
			intComparisonCount += 2;	//Counts the last two compares it failed.
			Q = P;
			P = P->GetRightChild();
		}
	}
	Y = new AVLNode();			//Create a new node
	Y->SetKeyValue(chWord);
	Y->SetBalanceFactor(0);

	if (chWord < Q->GetKeyValue())	//Check to see if Y will be Q's left or right child.
	{
		intComparisonCount++;
		Q->SetLeftChild(Y);
	}
	else
	{
		intComparisonCount++;
		Q->SetRightChild(Y);
	}

	if (chWord > A->GetKeyValue()) //Finding which way the displacement is.
	{
		intComparisonCount++;
		B = P = A->GetRightChild();
		d = -1;
	}
	else
	{
		intComparisonCount++;
		B = P = A->GetLeftChild();
		d = +1;
	}
	while (P != Y)	// P is now one node below A.  Adjust from here to the
	{				// insertion point.  Don’t do anything to new node (Y)
		if (chWord > P->GetKeyValue())
		{
			intComparisonCount++;
			P->SetBalanceFactor(-1);
			P = P->GetRightChild();
		}
		else
		{
			intComparisonCount++;
			P->SetBalanceFactor(1);
			P = P->GetLeftChild();
		}
	}

	// Now we check the BF at A and see if we just pushed the tree INTO 
	// BALANCE, into an “unacceptable IMBALANCE”, or if it is still
	// “BALANCED ENOUGH”.

	if (A->GetBalanceFactor() == 0) //Tree was already balanced, add the new displacement.
	{
		A->SetBalanceFactor(d);
		return;
	}
	if (A->GetBalanceFactor() == -d) //If the tree was displaced the other way then we fixed it.
	{
		A->SetBalanceFactor(0);
		return;
	}

	if (d == 1)			//This is a left inbalance
	{
		if (B->GetBalanceFactor() == 1) //Left left rotation
		{
			//Change the child pointers at A and B to reflect the rotation
			// See Schematic (1)
			A->SetLeftChild(B->GetRightChild());
			B->SetRightChild(A);
			B->SetBalanceFactor(0);
			A->SetBalanceFactor(0);

		}
		else //LR Rotation
		{

			// Adjust the child pointers of nodes A, B, & C to refelct
			// the new post-rotation structure

			C = B->GetRightChild();
			CL = C->GetLeftChild();
			CR = C->GetRightChild();

			B->SetRightChild(CL);
			A->SetLeftChild(CR);

			C->SetLeftChild(B);
			C->SetRightChild(A);

			switch (C->GetBalanceFactor())
			{
			case 1:
				A->SetBalanceFactor(-1);
				B->SetBalanceFactor(0);
				break;
			case 0:
				A->SetBalanceFactor(0);
				B->SetBalanceFactor(0);
				break;
			case -1:
				A->SetBalanceFactor(0);
				B->SetBalanceFactor(1);
				break;
			}

			C->SetBalanceFactor(0); // C is now balanced
			B = C;					// B is the root of the now-rebalanced subtree
		}
	}
	else // d=-1 this is a right imbalance. 
	{
		// This is symetrical to the code above.
		if (B->GetBalanceFactor() == -1)
		{
			A->SetRightChild(B->GetLeftChild());
			B->SetLeftChild(A);
			B->SetBalanceFactor(0);
			A->SetBalanceFactor(0);
			//Change the child pointers at A and B to reflect the rotation
			// Adjust the BFs at A & B
			// See Schematic (1)
		}
		else //RL Rotation
		{

			//Adjust the child pointers of nodes A, B, & C to refelct
			// the new post-rotation structure

			C = B->GetLeftChild();
			CL = C->GetLeftChild();
			CR = C->GetRightChild();

			B->SetLeftChild(CR);
			A->SetRightChild(CL);

			C->SetLeftChild(A);
			C->SetRightChild(B);

			switch (C->GetBalanceFactor())
			{
			case 1:
				A->SetBalanceFactor(0);
				B->SetBalanceFactor(-1);
				break;
			case 0:
				A->SetBalanceFactor(0);
				B->SetBalanceFactor(0);
				break;
			case -1:
				A->SetBalanceFactor(1);
				B->SetBalanceFactor(0);
				break;

			}

			C->SetBalanceFactor(0);
			B = C;
		}
	}

	// Finish up:
	//
	// Regardless, the subtree rooted at B has been rebalanced, and needs to
	// be the new child of F.  The original subtree of F had root A.

	// did we rebalance the whole tree’s root?

	if (F == nullptr)	// B is the tree’s new root - done
	{
		Root = B;
		return;
	}
	// The root of what we rebalanced WAS A; now it’s B.  If the subtree we
	// rebalanced was LEFT of F, then B needs to be left of F;
	// if A was RIGHT of F, then B now needs to be right of F.
	//

	if (A == F->GetLeftChild())
	{
		F->SetLeftChild(B);
		return;
	}
	if (A == F->GetRightChild())
	{
		F->SetRightChild(B);
		return;
		std::cout << "We should never be here" << endl;
	}
}

int AVL::GetPointerChanges()
{
	return intPointerChanges;
}

int AVL::GetComparisonCount()
{
	return intComparisonCount;
}

int AVL::GetNodeCount()
{
	return intNodeCount;
}

int AVL::GetHeight()
{
	return intHeight;
}

int AVL::GetBalanceChanges()
{
	return intBalanceFactorChanges;
}


void AVL::Traverse()
{
	Traversal(Root, 1);
}

void AVL::Traversal(AVLNode* startNode, int height)
{
	//This function steps through the tree and collects the height of each tree and records the highest
	//height as the height of the tree. As it stops at each node it also gets the statistics needed from each
	//node and increments how many nodes are in the tree.
	if (startNode != nullptr)
	{
		if (height > intHeight) intHeight = height;
		Traversal(startNode->GetLeftChild(), height + 1);
		intPointerChanges += startNode->GetPointerChanges();
		intBalanceFactorChanges += startNode->GetBalanceChanges();
		intNodeCount++;
		Traversal(startNode->GetRightChild(), height + 1);
	}
}

AVL::~AVL()
{
}

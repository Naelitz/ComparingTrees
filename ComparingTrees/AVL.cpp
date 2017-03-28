#include "stdafx.h"
#include "AVL.h"
#include <iostream>

using namespace std;

AVL::AVL()
{
}

void AVL::Insert(std::string chWord)
{
	AVLNode* Y;
	AVLNode* A, *B, *F;
	AVLNode* P, *Q;
	AVLNode* C, *CL, *CR;
	int d;

	if (Root == nullptr)
	{
		Y = new AVLNode();
		Y->SetKeyValue(chWord);
		Y->SetBalanceFactor(0);
		Root = Y;
		return;
	}
	F = Q = nullptr;
	A = P = Root;
	while (P != nullptr)
	{
		if (chWord == P->GetKeyValue())
		{
			P->IncrementOccurences();
			return;
		}
		if (P->GetBalanceFactor() != 0)
		{
			A = P;
			F = Q;
		}
		if (chWord < P->GetKeyValue())
		{
			Q = P;
			P = P->GetLeftChild();
		}
		else
		{
			Q = P;
			P = P->GetRightChild();
		}
	}
	Y = new AVLNode();
	Y->SetKeyValue(chWord);
	Y->SetBalanceFactor(0);

	if (chWord < Q->GetKeyValue()) Q->SetLeftChild(Y);
	else						   Q->SetRightChild(Y);

	if (chWord > A->GetKeyValue())
	{
		B = P = A->GetRightChild();
		d = -1;
	}
	else
	{
		B = P = A->GetLeftChild();
		d = +1;
	}
	while (P != Y)
	{
		if (chWord > P->GetKeyValue())
		{
			P->SetBalanceFactor(-1);
			P = P->GetRightChild();
		}
		else
		{
			P->SetBalanceFactor(1);
			P = P->GetLeftChild();
		}
	}

	if (A->GetBalanceFactor() == 0)
	{
		A->SetBalanceFactor(d);
		return;
	}
	if (A->GetBalanceFactor() == -d)
	{
		A->SetBalanceFactor(0);
		return;
	}

	if (d == 1)
	{
		if (B->GetBalanceFactor() == 1)
		{
			A->SetLeftChild(B->GetRightChild());
			B->SetRightChild(A);
			B->SetBalanceFactor(0);
			A->SetBalanceFactor(0);
			//todo: Change the child pointers at A and B to reflect the rotation
			// Adjust the BFs at A & B
			// <<< LEFT FOR YOU TO WRITE (3-4 LOC) >>>
			// See Schematic (1)
		}
		else //LR Rotation
		{

			//todo: Adjust the child pointers of nodes A, B, & C to refelct
			// the new post-rotation structure
			// <<< LEFT FOR YOU TO WRITE, BUT HERE’S >>>
			// <<< A HEAD START (4 LOC here)         >>>
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
				//todo: Cases (3 LOC/CASE)

			}

			C->SetBalanceFactor(0);
			B = C;
		}
	}
	else
	{
		if (B->GetBalanceFactor() == -1)
		{
			A->SetRightChild(B->GetLeftChild());
			B->SetLeftChild(A);
			B->SetBalanceFactor(0);
			A->SetBalanceFactor(0);
			//todo: Change the child pointers at A and B to reflect the rotation
			// Adjust the BFs at A & B
			// <<< LEFT FOR YOU TO WRITE (3-4 LOC) >>>
			// See Schematic (1)
		}
		else //RL Rotation
		{

			//todo: Adjust the child pointers of nodes A, B, & C to refelct
			// the new post-rotation structure
			// <<< LEFT FOR YOU TO WRITE, BUT HERE’S >>>
			// <<< A HEAD START (4 LOC here)         >>>
			C = B->GetLeftChild();
			CL = C->GetRightChild();
			CR = C->GetLeftChild();

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
				//todo: Cases (3 LOC/CASE)

			}

			C->SetBalanceFactor(0);
			B = C;
		}
		//todo: (RR or RL).  THAT code goes here.
		 // <<< LEFT FOR YOU TO WRITE, BUT IT’S >>>
		 // <<< SYMMETRIC TO THE LEFT IMBALANCE >>>

	}

	if (F == nullptr)
	{
		Root = B;
		return;
	}
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

void AVL::Traverse()
{
	Traversal(Root);
}

void AVL::Traversal(AVLNode* startNode)
{
	if (startNode != nullptr)
	{
		Traversal(startNode->GetLeftChild());
		intPointerChanges += startNode->GetPointerChanges();
		intNodeCount++;
		Traversal(startNode->GetRightChild());
	}
}

AVL::~AVL()
{
}

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

void RBT::Insert(std::string chWord)
{
	if (Root == nullptr)
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
	auto z = new RBTNode();
	z->SetKeyValue(chWord);
	RBTNode* y = nullptr;
	RBTNode* x = Root;
	while (x != nil)
	{
		y = x;
		if (x->GetKeyValue() == chWord)
		{
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
	if (y == nil)
	{
		intComparisonCount++;
		Root = z;
	}
	else
	{
		if (z->GetKeyValue() < y->GetKeyValue())
		{
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
	z->SetLeftChild(nil);
	z->SetRightChild(nil);
	z->SetColor(true);
	Fixup(z);
}


void RBT::Fixup(RBTNode* startNode)
{
	while (startNode->GetParent()->IsRed())
	{
		if (startNode->GetParent() == startNode->GetParent()->GetParent()->GetLeftChild())
		{
			auto y = new RBTNode();
			y = startNode->GetParent()->GetParent()->GetRightChild();
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
				if (startNode == startNode->GetParent()->GetRightChild())
				{
					startNode = startNode->GetParent();
					LeftRotate(startNode);
				}
				intColorChanges += 2;
				startNode->GetParent()->SetColor(false);
				startNode->GetParent()->GetParent()->SetColor(true);
				RightRotate(startNode->GetParent()->GetParent());
			}
		}
		else
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
	Root->SetColor(false);
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
	Traversal(Root);
}

void RBT::Traversal(RBTNode* startNode)
{
	if (startNode != nil && startNode != nullptr)
	{
		Traversal(startNode->GetLeftChild());
		intPointerChanges += startNode->GetPointerChanges();
		intNodeCount++;
		Traversal(startNode->GetRightChild());
	}
}

int RBT::GetNodeCount()
{
	return intNodeCount;
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

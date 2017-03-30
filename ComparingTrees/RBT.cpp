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
	nil->AddPointerChanges(4);
	Root = nil;
}

void RBT::Insert(std::string chWord)
{
	if (Root == nullptr)
	{
		//todo: reference + 4
		Root = new RBTNode();
		Root->SetKeyValue(chWord);
		Root->SetColor(false);
		Root->SetParent(nil);
		Root->SetLeftChild(nil);
		Root->SetRightChild(nil);
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
	z->AddPointerChanges(1);
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
			y->AddPointerChanges(1);
			y->SetLeftChild(z);
		}
		else
		{
			intComparisonCount += 2;
			y->AddPointerChanges(1);
			y->SetRightChild(z);
		}
	}
	z->AddPointerChanges(2);
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
				startNode->GetParent()->SetColor(false);
				startNode->GetParent()->GetParent()->SetColor(true);
				LeftRotate(startNode->GetParent()->GetParent());
			}
		}
	}
	Root->SetColor(false);
}

void RBT::RightRotate(RBTNode* z)
{
	auto y = z->GetLeftChild();
	z->SetLeftChild(y->GetRightChild());
	z->AddPointerChanges(1);

	if (y->GetRightChild() != nil)
	{
		y->GetRightChild()->AddPointerChanges(1);
		y->GetRightChild()->SetParent(z);
	}

	y->AddPointerChanges(1);
	y->SetParent(z->GetParent());
	if (z->GetParent() == nil)
	{
		Root = y;
		Root->AddPointerChanges(1);
	}
	else if (z == z->GetParent()->GetRightChild())
	{
		z->GetParent()->SetRightChild(y);
		z->GetParent()->AddPointerChanges(1);
	}
	else
	{
		z->GetParent()->AddPointerChanges(1);
		z->GetParent()->SetLeftChild(y);
	}
	y->AddPointerChanges(1);
	z->AddPointerChanges(1);
	y->SetRightChild(z);
	z->SetParent(y);
}

void RBT::LeftRotate(RBTNode* z)
{
	auto y = z->GetRightChild();
	z->SetRightChild(y->GetLeftChild());
	z->AddPointerChanges(1);

	if (y->GetLeftChild() != nil)
	{
		y->GetLeftChild()->SetParent(z);
		y->GetLeftChild()->AddPointerChanges(1);
	}

	y->AddPointerChanges(1);
	y->SetParent(z->GetParent());
	if (z->GetParent() == nil)
	{
		Root = y;
		Root->AddPointerChanges(1);
	}
	else if (z == z->GetParent()->GetLeftChild())
	{
		z->GetParent()->SetLeftChild(y);
		z->GetParent()->AddPointerChanges(1);
	}
	else
	{
		z->GetParent()->SetRightChild(y);
		z->GetParent()->AddPointerChanges(1);
	}
	y->AddPointerChanges(1);
	z->AddPointerChanges(1);
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


RBT::~RBT()
{
}

#include "stdafx.h"
#include "RBT.h"
#include <iostream>

using namespace std;
RBT::RBT()
{
	nil = new RBTNode();
	nil->SetKeyValue("");
	nil->SetColor(false);
	nil->SetLeftChild(nil);
	nil->SetRightChild(nil);
	nil->SetParent(nil);
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
			x->IncrementOccurences();
			return;
		}

		else if (z->GetKeyValue() < x->GetKeyValue())
		{
			x = x->GetLeftChild();
		}
		else
		{
			x = x->GetRightChild();
		}
	}
	z->SetParent(y);
	if (y == nil)
	{
		Root = z;
	}
	else
	{
		if (z->GetKeyValue() < y->GetKeyValue())
		{
			y->SetLeftChild(z);
		}
		else
		{
			y->SetRightChild(z);
		}
	}
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
}

void RBT::RightRotate(RBTNode* z)
{
	auto y = z->GetLeftChild();
	z->SetRightChild(y->GetRightChild());
	//todo:Reference + 1

	if (y->GetRightChild() != nil)
	{
		//todo:Reference + 1;
		y->GetRightChild()->SetParent(z);
	}

	//todo:References + 4
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
	//todo: Reference + 1

	if (y->GetLeftChild() != nil)
	{
		y->GetLeftChild()->SetParent(z);
		//todo: Reference + 1
	}

	//todo: Reference + 4
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
	if (startNode != nil || startNode != nullptr)
	{
		Traversal(startNode->GetLeftChild());
		intPointerChanges += startNode->GetPointerChanges();
		intNodeCount++;
		cout << startNode->GetKeyValue() << endl;
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

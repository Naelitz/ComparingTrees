#pragma once
#include <string>

class RBTNode
{
public:
	RBTNode();
	~RBTNode();
	void SetKeyValue(std::string chWord);
	std::string GetKeyValue();
	void IncrementOccurences();
	void SetColor(bool blnColor);
	void SetRightChild(RBTNode* newNode);
	void SetLeftChild(RBTNode* newNode);
	void SetParent(RBTNode* newNode);
	RBTNode* GetLeftChild();
	RBTNode* GetRightChild();
	RBTNode* GetParent();
	int GetPointerChanges();
	bool IsRed();
private:
	std::string strKeyValue;
	RBTNode* leftChild;
	RBTNode* RightChild;
	RBTNode* parent;
	bool blnColorRed = false;
	int intCount = 1;
	int intPointerChanges = 0;
};


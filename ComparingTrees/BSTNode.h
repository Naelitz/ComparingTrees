#pragma once
#include <string>

class BSTNode
{
public:
	std::string GetKeyValue();
	void SetKeyValue(char* chWord);
	BSTNode* GetLeftChild();
	BSTNode* GetRightChild();
	void SetLeftChild(BSTNode* newNode);
	void SetRightChild(BSTNode* newNode);
	void IncrementOccurences();
	int GetPointerChanges();
	BSTNode(std::string chWord);
	BSTNode();
	~BSTNode();
private:
	BSTNode* ptrLeftChild;
	BSTNode* ptrRightChild;
	std::string strKeyValue;
	int intCount = 1;
	int intPointerChanges = 0;


};


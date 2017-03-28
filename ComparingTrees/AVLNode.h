#pragma once
#include <string>

class AVLNode
{
public:
	AVLNode();
	~AVLNode();
	std::string GetKeyValue();
	void SetKeyValue(std::string chWord);
	AVLNode* GetLeftChild();
	AVLNode* GetRightChild();
	void SetBalanceFactor(int BF);
	int GetBalanceFactor();
	void SetLeftChild(AVLNode* newNode);
	void SetRightChild(AVLNode* newNode);
	void IncrementOccurences();
	int GetPointerChanges();
private:
	AVLNode* ptrLeftChild;
	AVLNode* ptrRightChild;
	std::string strKeyValue;
	int intBalanceFactor = 0;
	int intCount = 1;
	int intPointerChanges = 0;
};


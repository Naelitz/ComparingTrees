// ComparingTrees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AVL.h"
#include "BST.h"
#include "RBT.h"
#include <time.h>
#include <fstream>
#include <iostream>

using namespace std;

void RunBlank();
void RunAVL();
void RunBST();
void RunRBT();

char c;
string fileName = "Shakespeare.txt";
RBT treeRBT;
AVL treeAVL;
BST treeBST;

char chari[75];
string strWord;
int iPtr;
int intWordCount = 0;
bool IsDelimiter = false, WasDelimiter = false;

ifstream inFile;

int main()
{

	RunBlank();
	RunBST();
	RunAVL();
    return 0;
}

void RunBlank()
{
	for (int i = 0; i < 75; i++) chari[i] = '\0';


	inFile.open(fileName, ios::binary);
	if (inFile.fail())
	{
		cout << "Unable to open input file\n\n" << "Program Exiting\n\nPress ENTER to exit\n";
		cin.get(c);
		exit(1);
	}
	clock_t t;
	t = clock();
	iPtr = 0;
	inFile.get(c);
	while (!inFile.eof())
	{
		IsDelimiter = (c == 32 || c == 10 || c == 13 || c == 9 ||
			c == '.' || c == ',' || c == '!' || c == ';' ||
			c == ':' || c == '(' || c == ')');
		if (IsDelimiter && !WasDelimiter)
		{
			WasDelimiter = true;
			strWord = string(chari);
			intWordCount++;
			for (int i = 0; i < 50; i++) chari[i] = '\0';
			iPtr = 0;
		}
		else if (!IsDelimiter)
		{
			chari[iPtr] = c;
			iPtr++;
		}
		else if (IsDelimiter && WasDelimiter)
		{
			// Do Nothing
		}
		WasDelimiter = IsDelimiter;
		inFile.get(c);
	}
	inFile.close();
	t = clock() - t;
}

void RunBST()
{
	intWordCount = 0;
	for (int i = 0; i < 75; i++) chari[i] = '\0';


	inFile.open(fileName, ios::binary);
	if (inFile.fail())
	{
		cout << "Unable to open input file\n\n" << "Program Exiting\n\nPress ENTER to exit\n";
		cin.get(c);
		exit(1);
	}
	clock_t t;
	t = clock();
	iPtr = 0;
	inFile.get(c);
	while (!inFile.eof())
	{
		IsDelimiter = (c == 32 || c == 10 || c == 13 || c == 9 ||
			c == '.' || c == ',' || c == '!' || c == ';' ||
			c == ':' || c == '(' || c == ')');
		if (IsDelimiter && !WasDelimiter)
		{
			WasDelimiter = true;
			//treeRBT;
			//treeAVL;
			strWord = string(chari);
			intWordCount++;
			if (intWordCount == 4799) cout << strWord << endl;
			treeBST.Insert(strWord);
			//treeBST;

			for (int i = 0; i < 75; i++) chari[i] = '\0';
			iPtr = 0;
		}
		else if (!IsDelimiter)
		{
			chari[iPtr] = c;
			iPtr++;
		}
		else if (IsDelimiter && WasDelimiter)
		{
			// Do Nothing
		}
		WasDelimiter = IsDelimiter;
		inFile.get(c);
	}
	inFile.close();
	t = clock() - t;
	treeBST.Traverse();
	cout << intWordCount << "\t" << treeBST.GetNodeCount() << "\t" << treeBST.GetPointerChanges() << "\t" << treeBST.GetComparisonCount() << endl;
	cout << "It took " << t << " clocks" << endl;
}

void RunAVL()
{
	intWordCount = 0;
	for (int i = 0; i < 75; i++) chari[i] = '\0';


	inFile.open(fileName, ios::binary);
	if (inFile.fail())
	{
		cout << "Unable to open input file\n\n" << "Program Exiting\n\nPress ENTER to exit\n";
		cin.get(c);
		exit(1);
	}
	clock_t t;
	t = clock();
	iPtr = 0;
	inFile.get(c);
	while (!inFile.eof())
	{
		IsDelimiter = (c == 32 || c == 10 || c == 13 || c == 9 ||
			c == '.' || c == ',' || c == '!' || c == ';' ||
			c == ':' || c == '(' || c == ')');
		if (IsDelimiter && !WasDelimiter)
		{
			WasDelimiter = true;
			//treeRBT;
			//treeAVL;
			strWord = string(chari);
			intWordCount++;
			cout << strWord << intWordCount << endl;
			treeAVL.Insert(strWord);
			//treeBST;

			for (int i = 0; i < 75; i++) chari[i] = '\0';
			iPtr = 0;
		}
		else if (!IsDelimiter)
		{
			chari[iPtr] = c;
			iPtr++;
		}
		else if (IsDelimiter && WasDelimiter)
		{
			// Do Nothing
		}
		WasDelimiter = IsDelimiter;
		inFile.get(c);
	}
	inFile.close();
	t = clock() - t;
	treeBST.Traverse();
	cout << intWordCount << "\t" << treeAVL.GetNodeCount() << "\t" << treeAVL.GetPointerChanges() << "\t" << treeAVL.GetComparisonCount() << endl;
	cout << "It took " << t << " clocks" << endl;
	cin;
}


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
	RunRBT();
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
			strWord = string(chari);
			intWordCount++;
			treeBST.Insert(strWord);
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
	cout << "Run Time\tTotal Words\tDistinct\tPointer Change\tCompares\tReference" << endl;
	cout << t << "\t" << intWordCount 
	<< "\t" << treeBST.GetNodeCount() 
	<< "\t" << treeBST.GetPointerChanges() 
	<< "\t" << treeBST.GetComparisonCount() << endl;
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
			strWord = string(chari);
			intWordCount++;
			treeAVL.Insert(strWord);

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
	treeAVL.Traverse();
	cout << t << "\t" << intWordCount 
	<< "\t" << treeAVL.GetNodeCount() 
	<< "\t" << treeAVL.GetPointerChanges() 
	<< "\t" << treeAVL.GetComparisonCount() << endl;
}

void RunRBT()
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
			strWord = string(chari);
			intWordCount++;
			treeRBT.Insert(strWord);

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
	treeRBT.Traverse();
	cout << "RBT\t" <<  t << "\t" << intWordCount 
	<< "\t" << treeRBT.GetNodeCount() << "\t" 
	<< treeRBT.GetPointerChanges() << "\t" 
	<< treeRBT.GetComparisonCount() << "\t" 
	<< treeRBT.GetColorChanges() << endl;
	cin.get(c);
}


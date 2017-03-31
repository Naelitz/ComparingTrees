// ComparingTrees.cpp : Defines the entry point for the console application.
// Author: David Naelitz
// Written for EECS2510 Fall 2017
// Date: 3/25/2017
// Description: This is the main file of the program. This file parses the file and sends information 
// to the respected trees. It also tracks the time it takes for each tree to run.

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
bool blnRunAll = false;	// This toggles between running all files or the specified one above.
string files[14];
ifstream inFile;
clock_t overhead;
int main()
{
	// This is main and is used to identify the files that will be run as well as calling the tree functions.
	files[0] = "AnnaKareninaTolstoy.txt";
	files[1] = "BleakHouseDickens.txt";
	files[2] = "DavidCopperfieldDickens.txt";
	files[3] = "DonQuixoteCervantes.txt";
	files[4] = "KingJamesBible.txt";
	files[5] = "LesMiserablesHugo.txt";
	files[6] = "MiddlemarchEliot.txt";
	files[7] = "MobyDickMelville.txt";
	files[8] = "Shakespeare.txt";
	files[9] = "TheBrothersKaramazovDostoyevsky.txt";
	files[10] = "TheHunchbackOfNotreDameHugo.txt";
	files[11] = "TheThreeMusketeersDumas.txt";
	files[12] = "WarAndPeaceTolstoy.txt";
	files[13] = "combinedFiles.txt";

	if (blnRunAll)
	{
		for (int intCounter = 0; intCounter <= 13; intCounter++)
		{
			fileName = files[intCounter];
			RunBlank();
			RunBlank();
			RunBST();

		}
		for (int intCounter = 0; intCounter <= 13; intCounter++)
		{
			fileName = files[intCounter];
			RunBlank();
			RunBlank();
			RunAVL();

		}
		for (int intCounter = 0; intCounter <= 13; intCounter++)
		{
			fileName = files[intCounter];
			RunBlank();
			RunBlank();
			RunRBT();
		}
		cin.get(c);
	}
	else
	{
		RunBlank();
		RunBlank();
		RunBST();
		RunAVL();
		RunRBT();
		cin.get(c);
	}

	return 0;
}

void RunBlank()
{
	// Goes through the file and parses into individual words and tracks the time this takes to 
	// store as overhead in other runs. 
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
	overhead = t;
}

void RunBST()
{
	// Goes through the file and parses into individual words and then sends it to a BST 
	// It keeps track how long this takes. Then is calls the different statistics needed 
	// from the tree and outputs it to the console. 
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
	cout << fileName << "\t"
		<< "BST " << t - overhead
		<< "\t" << treeBST.GetHeight()
		<< "\t" << intWordCount
		<< "\t" << treeBST.GetNodeCount()
		<< "\t" << treeBST.GetPointerChanges()
		<< "\t" << treeBST.GetComparisonCount() << endl;
}

void RunAVL()
{
	// Goes through the file and parses into individual words and then sends it to a AVL 
	// tree. It keeps track how long this takes. Then is calls the different statistics needed 
	// from the tree and outputs it to the console. 
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

	cout << fileName << "\t"
		<< "AVL\t" << t - overhead
		<< "\t" << treeAVL.GetHeight()
		<< "\t" << intWordCount
		<< "\t" << treeAVL.GetNodeCount()
		<< "\t" << treeAVL.GetPointerChanges()
		<< "\t" << treeAVL.GetComparisonCount()
		<< "\t" << treeAVL.GetBalanceChanges()
		<< endl;
}

void RunRBT()
{
	// Goes through the file and parses into individual words and then sends it to a RBT 
	// It keeps track how long this takes. Then is calls the different statistics needed 
	// from the tree and outputs it to the console.
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

	cout << fileName << "\t"
		<< "RBT\t" << t - overhead
		<< "\t" << treeRBT.GetHeight()
		<< "\t" << intWordCount
		<< "\t" << treeRBT.GetNodeCount() << "\t"
		<< treeRBT.GetPointerChanges() << "\t"
		<< treeRBT.GetComparisonCount() << "\t"
		<< treeRBT.GetColorChanges() << endl;
}


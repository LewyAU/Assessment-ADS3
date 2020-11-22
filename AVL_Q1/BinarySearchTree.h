#pragma once
#include <queue>
#include "Nodes.h"
using namespace std;

class Nodeslevel
{
public:

	Nodes* Level;
	int levnumber;

	Nodeslevel(Nodes* Level, int levnumber)
	{
		this->Level =Level;
		this->levnumber = levnumber;
	}
	// constructor needs to be same name as class

};

class BinarySearchTree // root node acting as centre
{
	// binary tree insert and search functions
public:
	Nodes* root = NULL;
	virtual void insert(Nodes* newLevel); // takes us to pointer to insert new students
	Nodes* search(int levelnumber, bool showSearchPath = false);	// serach returns a student matching the student ID
	//default value - can call search function and give it a value for studentID and will use the bool as its default one

	//traversals ( recursive )
	void inOrderTraversal(Nodes* current);
	void preOrderTraversal(Nodes* current);
	void postOrderTraversal(Nodes* current);

	void show(Nodes* p);
};

	// -1,1,0 is a balanced tree

	// useing inheritence from week 7 work for week 8 to save time




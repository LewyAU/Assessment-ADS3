#pragma once
#include <iostream>
#include <string>

using namespace std;

class Nodes
{
public:
	string levelname;
	int levelnumber; // data we feed to thee function
	Nodes* leftChild;
	Nodes* rightChild; // nodes pointing

	Nodes(int levelnumber,string levelname);
	// constructor needs to be same name as class

};


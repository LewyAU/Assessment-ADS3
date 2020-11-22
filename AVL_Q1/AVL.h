#pragma once
#include "BinarySearchTree.h"

class AVL : public BinarySearchTree
{
public:

	bool displayRotation = true;

	int height(Nodes* node);
	int difference(Nodes* node);

	//ROTATIONS
	// parameter current parent of sub tree
	// returns new parent of the set ( sub tree )
	// right branch right child
	Nodes* RRrotation(Nodes* parent);
	Nodes* LLrotation(Nodes* parent);
	Nodes* RLrotation(Nodes* parent);
	Nodes* LRrotation(Nodes* parent);

	//BALANCE
	//parents in the middle become balanced
	// returns new parent after balancing
	Nodes* balance(Nodes* parent);

	//INSERT
	// recursive insert htat considers parent a sub tree
	// this insert also balnces itself
	// returns the new node of the tree
	Nodes* insertAVL(Nodes* parent, Nodes* newLevel);

	// overriding insert from parent
	void insert(Nodes* newLevel);

};


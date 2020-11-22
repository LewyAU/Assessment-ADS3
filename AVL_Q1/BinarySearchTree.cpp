#include "BinarySearchTree.h"

void BinarySearchTree::insert(Nodes* newlevel)
{
	// insert root node, or go left or right if not empty
	if (root == NULL)
	{
		root = newlevel;
		return; // exit function eearly
	}

	Nodes* current = root; // current node pointing at
	Nodes* parent = NULL; //  parent of current

	while (true)
	{
		//keep track of where we were before moving downw further
		parent = current;
		if (newlevel->levelnumber< current->levelnumber)
		{
			// means we go down deeper into tree on left side
			current = current->leftChild;
			//if current is NULL, we just found an empty space to insert new student
			if (current == NULL)
			{
				// done, stick newlevel here
				parent->leftChild = newlevel;
				return;
			}
		}
		else
		{
			// go down right
			current = current->rightChild;
			// if current null, insert there
			if (current == NULL)
			{
				parent->rightChild = newlevel;
				return;
			}
		}

	}


}

Nodes* BinarySearchTree::search(int levelnumber, bool showSearchPath)
{
	// if root null return NULL ( cant find matching level ID ID)
	if (root == NULL)
	{
		return NULL;
	}

	Nodes* current = root; // current node pointing at

	while (current->levelnumber!= levelnumber)// keep looping until there a match
	{
		// if current is NULL, search newLevelID cannot be found
		if (current == NULL)
		{
			return NULL;
		}
		if (showSearchPath)
			cout << current->levelnumber << " " << current->levelname << endl;
		// exploring left side of tree
		if (levelnumber < current->levelnumber)
		{
			current = current->leftChild;// current pointer pointing to node in the tree, point to left child of tree to move pointer down tree
		}
		else // go right
		{
			current = current->rightChild;
		}
	}

	return current;
}

void BinarySearchTree::inOrderTraversal(Nodes* current)
{
	if (current != NULL) // currentt == NULL is end of this branch path
	{// need to have a few versions to prevent an infinite loop(keeps going)
		inOrderTraversal(current->leftChild);
		cout << current->levelnumber<< " " << current->levelname << endl;
		inOrderTraversal(current->rightChild);
	// takes a node and explores down the left or right 
	}// puts tree in ascending order


}

void BinarySearchTree::preOrderTraversal(Nodes* current)
{
	if (current != NULL) // currentt == NULL is end of this branch path
	{// need to have a few versions to prevent an infinite loop(keeps going)
		cout << current->levelnumber << " " << current->levelname << endl;
		preOrderTraversal(current->leftChild);
		preOrderTraversal(current->rightChild);
	}

}

void BinarySearchTree::postOrderTraversal(Nodes* current)
{
	if (current != NULL)
	{

		postOrderTraversal(current->leftChild);
		postOrderTraversal(current->rightChild);
		cout << current->levelnumber<< " " << current->levelname << endl;
	}



}

void BinarySearchTree::show(Nodes* p)
{
	if (root == NULL) return;

	queue<Nodeslevel>q;

	q.push(Nodeslevel(root, 0));

	int previousOutputLevel = -1;

	while (q.empty() == false)
	{
		Nodeslevel node = q.front();
		if (node.levnumber != previousOutputLevel)
		{
			cout << endl;
			cout << node.levnumber << "  ";
			previousOutputLevel= node.levnumber;

		}
		cout << node.Level->levelnumber<< " " << node.Level->levelname << " ";
		q.pop();


		if (node.Level->leftChild != NULL)
		q.push(Nodeslevel(node.Level->leftChild, node.levnumber+1));
		
		if (node.Level->rightChild != NULL)

			q.push(Nodeslevel(node.Level->rightChild, node.levnumber+1));


	}




}

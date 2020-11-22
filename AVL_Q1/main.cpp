#include <iostream>
#include <string>
#include "AVL.h"

using namespace std;

int main()
{
	
	AVL level;
	level.displayRotations = true;
	level.insert(new Nodes(23, "level23"));
	level.insert(new Nodes(12, "level12"));
	level.insert(new Nodes(5, "level5"));
	level.insert(new Nodes(8, "level8"));
	level.insert(new Nodes(10, "level10"));
	level.insert(new Nodes(21, "level21"));
	level.insert(new Nodes(11, "level11"));
	level.insert(new Nodes(17, "level17"));
	level.show(level.root);
	cout << "tree height thus far: " << level.height(level.root) << endl;
	cout << "avl root: " << level.root->levelname << " " << level.root->levelnumber << endl;

	
	
		system("pause");
}
#include <iostream>
#include <string>
#include "BinaryMaxHeap.h"
using namespace std;

int main()
{
	BinaryMaxHeap topRankedNumbers;

	topRankedNumbers.insert(NumberRanking("23"));
	topRankedNumbers.insert(NumberRanking("12"));
	topRankedNumbers.insert(NumberRanking("5"));
	topRankedNumbers.insert(NumberRanking("8"));
	// NumberRanking p1( "1");
	topRankedNumbers.insert(NumberRanking("10"));
	topRankedNumbers.insert(NumberRanking("21"));
	topRankedNumbers.insert(NumberRanking("11"));
	topRankedNumbers.insert(NumberRanking("17"));

	topRankedNumbers.showHeap();

	NumberRanking* topNumber = topRankedNumbers.ExtractMax(); // class player, ( name of the player class , name of iterator, what iterator is pointing to( name of binary search and the inserts so we can display players and sort them via the heap
	if (topNumber != NULL)
		cout << "highest ranked number: " << topNumber->rank << " " << endl;
	else
		cout << "Heap must be empty" << endl;

		cout << "Deleteing number" << endl;




	system("pause");
}


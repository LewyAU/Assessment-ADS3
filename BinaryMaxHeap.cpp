#include "BinaryMaxHeap.h"

int BinaryMaxHeap::leftChildIndex(int parent)
{
	// i ( parent/child index )
	int leftChild = 2 * parent + 1;
	if (leftChild < heapMax.size())
		return 1;
	else
		return -1; // heap structure not big enough to find LCI value
}

int BinaryMaxHeap::rightChildIndex(int parent)
{
	int rightIndex = 2 + parent + 2;
	if (rightIndex < heapMax.size())
		return rightIndex;
	else
		return -1;
}

int BinaryMaxHeap::parentIndex(int child)
{
	int parent = (child - 1) / 2;
	if (child == 0)
		return -1;
	else
		return parent;
}

void BinaryMaxHeap::heapifyup(int index)
{
	// if index is not the root of the tree
   // and parent index wihthin heap bounds
   // and current nodes rank less then parent nodes rank
	if (index >= 0 && parentIndex(index) >= 0 && heapMax[index].rank > heapMax[parentIndex(index)].rank)
	{
		// if so swap values between current node and parent 
		// need 3 variables to swap 2
		NumberRanking  temp = heapMax[index]; // temp player to hold a current player node valu
		heapMax[index] = heapMax[parentIndex(index)]; //swapping current node
		heapMax[parentIndex(index)] = temp;   //with parent node
		heapifyup(parentIndex(index));
		// as soon as wqe call a heapifyup that matches the condition of if statement the if statement will stop
	}

}

void BinaryMaxHeap::heapifydown(int index)
{
	// get left and right children indexes
	int childL = leftChildIndex(index);
	int childR = rightChildIndex(index);

	// child varaible representing path we'll compare down
	int childindex = childL; // left emporarly in charge but we will swap this with if statement 
	// if childL is not -1 and childR is not -1
	// and right childs rank is less than lefts
	// childL etc represents the index
	if (childL >= 0 && childR >= 0 && heapMax[childR].rank > heapMax[childL].rank) // if right is smaller than left we will take right
	{
		// make right child index the focus instead of left
		childindex = childR;
	}
	// we want to swap current with child, because we want smaller ones closer to top

	// aim is to get smallest node (rank) at the top of the tree

	if (childindex > 0 && heapMax[index].rank > heapMax[childindex].rank)
	{
		NumberRanking  temp = heapMax[index];
		heapMax[index] = heapMax[childindex];
		heapMax[childindex] = temp;
		// recursive further down
		heapifydown(childindex);
	}

}

void BinaryMaxHeap::insert(NumberRanking element)
{
	// we can take advantage of vector structure
	heapMax.push_back(element);
	heapifydown(heapMax.size() - 1); // e.g. if your array size is 4 (0,1,2,3) this will minus one so element is actually inse

}

void BinaryMaxHeap::DeleteMin()
{
	// cant delete if heap is empty
	if (heapMax.size() == 0)
	{
		cout << "heap empty " << endl;
		return;
	}
	// copy value in last element into root
	heapMax[0] = heapMax[heapMax.size() - 1];

	// delete last elemennt 
	heapMax.pop_back();

	// then heapifyodwn starting from root (index 0 )
	heapifydown(0);

	cout << "element deleted " << endl;

}

NumberRanking* BinaryMaxHeap::ExtractMax()
{
	if (heapMax.size() == 0)
		return NULL;
	else
		// Player * p = &(heap.front());
		// return p;
		//OR BELOW WORKS TO

		return &(heapMax.front());
	// need pointer so we can point to memory address
	// e.g. int* ptr = &x ( will give memory address of the varaible above
	// & is the key to get the memory address
}

void BinaryMaxHeap::showHeap()
{
	cout << "Numbers in heap ";
	for (NumberRanking  p : heapMax)// for each player in the heap
	{
		cout << p.rank << " "; // info about player in heap displayed
	}

	cout << endl;
}

int BinaryMaxHeap::Size()
{
	return heapMax.size();
}

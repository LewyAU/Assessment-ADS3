#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include "NumberRanking.h"

using namespace std;

class BinaryMaxHeap
{
	public:
		vector< NumberRanking> heapMax;		 // vector can shrink and grow
		int leftChildIndex(int parent);
		int rightChildIndex(int parent);
		int parentIndex(int child);
		// use 3 formulas from theory video

		void heapifyup(int index);
		void heapifydown(int index);

		void insert(NumberRanking element);
		void DeleteMin();
		NumberRanking* ExtractMax();		// get whatever root node is, pointer is handy as NULL can be returned if no player for example, or if there is ppoint to the player

		void showHeap(); // shows whats in array/vector
		int Size();
};
// heap structures work better with arrays



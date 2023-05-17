#include "Sorter.h"
#include "IComparable.h"
#include <iostream>

using namespace std;

void Sorter::BubbleSort(IComparable** pItems, unsigned itemCount) {
	// Bubble sort: https://www.geeksforgeeks.org/bubble-sort/
	for (unsigned int i = 0; i < itemCount - 1; i++) {
		for (unsigned int j = 0; j < itemCount - i - 1; j++) {
			if (*pItems[j] > *pItems[j + 1]) {
				IComparable* temp = pItems[j];
				pItems[j] = pItems[j + 1];
				pItems[j + 1] = temp;
			}
		}
	}
}

void Sorter::QuickSortRecursive(IComparable** pItems, int low, int high) {
	if (low < high) {
		int pi = Partition(pItems, low, high);
		QuickSortRecursive(pItems, low, pi - 1);
		QuickSortRecursive(pItems, pi + 1, high);
	}
}

int Sorter::Partition(IComparable** pItems, int low, int high) {
	IComparable* pivot = pItems[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (*pivot > *pItems[j]) {
			i++;
			IComparable* temp = pItems[i];
			pItems[i] = pItems[j];
			pItems[j] = temp;
		}
	}
	IComparable* temp = pItems[i + 1];
	pItems[i + 1] = pItems[high];
	pItems[high] = temp;
	return (i + 1);
}

void Sorter::QuickSort(IComparable** pItems, unsigned itemCount) {
	// Quick sort: https://www.geeksforgeeks.org/quick-sort/
	QuickSortRecursive(pItems, 0, itemCount - 1);
}
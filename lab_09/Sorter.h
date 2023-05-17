#ifndef SORTER_H
#define SORTER_H

#include "IComparable.h"

class Sorter {
	static void QuickSortRecursive(IComparable** pItems, int low, int high);
	static int Partition(IComparable** pItems, int low, int high);

public:
  static void BubbleSort(IComparable** pItems, unsigned itemCount);
  static void QuickSort(IComparable ** pItems, unsigned itemCount);
  // Other sorting algorithms can be implemented here...

};

#endif /* SORTER_H */
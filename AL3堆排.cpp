#include <iostream>
using namespace std;

void heapSort(int *arr, int heapSize, int index) {

	int leftChild = index * 2 + 1;
	int maxIndex;

	//使用下标判断，是否有还需要继续往深层比较大小
	while (leftChild < heapSize) {

		//两个孩子比较，谁大放入谁的下标
		maxIndex = arr[leftChild] > arr[leftChild + 1] && (leftChild + 1) <  heapSize? leftChild : leftChild + 1;

		//父亲和大孩子比较
		maxIndex = arr[index] > arr[maxIndex] ? index : maxIndex;

		if (maxIndex == index) break;

		swap(arr[index], arr[maxIndex]);

		index = maxIndex;

		leftChild = index * 2 + 1;

	}

}
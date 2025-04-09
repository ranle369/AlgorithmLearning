#include <iostream>
using namespace std;

void heapSort(int *arr, int heapSize, int index) {

	int leftChild = index * 2 + 1;
	int maxIndex;

	//ʹ���±��жϣ��Ƿ��л���Ҫ���������Ƚϴ�С
	while (leftChild < heapSize) {

		//�������ӱȽϣ�˭�����˭���±�
		maxIndex = arr[leftChild] > arr[leftChild + 1] && (leftChild + 1) <  heapSize? leftChild : leftChild + 1;

		//���׺ʹ��ӱȽ�
		maxIndex = arr[index] > arr[maxIndex] ? index : maxIndex;

		if (maxIndex == index) break;

		swap(arr[index], arr[maxIndex]);

		index = maxIndex;

		leftChild = index * 2 + 1;

	}

}
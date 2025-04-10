#include <iostream>
using namespace std;

void heapSort(int *arr) {

	int heapSize = sizeof(arr) / sizeof(arr[0]);

	if (heapSize < 2 || arr == NULL) {
		return;
	}

	int last = heapSize - 1;

	//����һ�������
	for (int i = 0; i < heapSize; i++) {
		heapify(arr, heapSize, i);
	}

	//�����������ˣ���ʼ������
	swap(arr[0], arr[last]);

	while (--heapSize > 0) {
		heapify(arr, heapSize, 0);
		swap(arr[0], arr[heapSize - 1]);
	}

}

void heapify(int *arr, int heapSize, int index) {

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
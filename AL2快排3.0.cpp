#include <iostream>
#include<math.h>
using namespace std;

void quickSort(int* arr,int L,int R) {

	if (L == R) {
		return;
	}

	int randInt = (rand() % (R - L + 1)) + L;
	swap(arr[randInt], arr[R]);

	//ʹ�ú�������˼�룬��һ�������Ϊ���Σ�< = >
	//Ȼ��ȥ�м���ڵ�һ����������
	int *p = parition(arr, L, R);
	quickSort(arr, L, p[0] - 1);
	quickSort(arr, p[1] + 1, R);

}

int* parition(int *p ,int L ,int R) {

	int key = p[R];
	int less = L - 1;
	//Ϊʲô��R����R+1�أ�
	//��ΪR�����ǱȽ�ֵ
	int more = R;
	int arr[2];


	while (L < R) {
		if (p[L]<key)
		{
			p[++less] = p[L++];
		}
		else if (p[L] > key) {
			p[--more] = p[L];
		}
		else {
			L++;
		}
	}

	//Ϊʲôswap�ǽ���key�����i==Lλ���أ�
	//��Ϊi��������������ı߽磬˵��i������Ӧ��ֵһ������key
	swap(p[R], p[L]);
	arr[0] = less;
	arr[1] = more;

	return arr;

}
#include <iostream>
#include<math.h>
using namespace std;


int* parition(int* p, int L, int R);
void quickSort(int* arr,int L,int R) {

	if (L == R) {
		return;
	}

	int randInt = (rand() % (R - L + 1)) + L;
	swap(arr[randInt], arr[R]);

	//使用荷兰国旗思想，把一个数组分为三段，< = >
	//然后去中间等于的一段索引出来
	int *p = parition(arr, L, R);
	quickSort(arr, L, p[0] - 1);
	quickSort(arr, p[1] + 1, R);

}

int* parition(int *p ,int L ,int R) {

	int key = p[R];
	int less = L - 1;
	//为什么是R不是R+1呢？
	//因为R坐标是比较值
	int more = R;
	int arr[2];


	while (L < more) {
		if (p[L]<key)
		{
			swap(arr[++less], arr[L++]);
		}
		else if (p[L] > key) {
			swap(arr[--more], arr[L]);
		}
		else {
			L++;
		}
	}

	//为什么swap是交换key和最后i==L位置呢？
	//因为i会碰到大于区域的边界，说明i索引对应的值一定大于key
	swap(p[R], p[L]);
	arr[0] = less;
	arr[1] = more;

	return arr;

}
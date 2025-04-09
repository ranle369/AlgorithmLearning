#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> arr,int L,int Mid,int R) {

	vector<int> helpArr(R - L + 1);
	int help = 0;
	int p1 = L;
	int p2 = Mid;

	while (p1 <= Mid && p2 <= R) {
		helpArr[help++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}

	while (p1 <= Mid) {
		helpArr[help++] = arr[p1++];

	}

	while (p2 <= R) {
		helpArr[help++] = arr[p2++];
	}

	for (int i = 0; i < R - L + 1; i++)
	{
		arr[L + i] = helpArr[i];
	}
}

void guiBing(vector<int> arr,int L,int R) {

	int Mid = L + ((R - L) >> 1);

	//◊Û≈≈–Ú
	guiBing(arr, L, Mid);
	//”“≈≈–Ú
	guiBing(arr, Mid + 1, R);
	//∫œ≤¢
	merge(arr, L, Mid, R);

}
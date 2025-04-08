#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> arr,int L,int Mid,int R) {

	int help = 0;
	int p1 = L;
	int p2 = Mid;

	while (p1 <= Mid && p2 <= R) {
		arr[help++ + L] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}

	while (p1 <= Mid) {
		arr[help++ + L] = arr[p1++];
	}

	while (p2 <= R) {
		arr[help++ + L] = arr[p2++];
	}

}

void guiBing(vector<int> arr,int L,int R) {

	int Mid = L + ((R - L) >> 1);

	//×óÅÅĞò
	guiBing(arr, L, Mid);
	//ÓÒÅÅĞò
	guiBing(arr, Mid + 1, R);
	//ºÏ²¢
	merge(arr, L, Mid, R);

}
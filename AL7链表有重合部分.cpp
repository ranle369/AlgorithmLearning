#include <iostream>
using namespace std;

typedef struct Node {
	int data;
	Node* next;
}Node;

//两条链表查找两链表重合部分，补充和返回null，重合返回第一个重合节点
Node* findMerge(Node * head1,Node* head2) {
	if (head1 == NULL || head2 == NULL) {
		return NULL;
	}

	Node* linkList1 = head1;
	Node* linkList2 = head2;

	//使用变量N，记录两条链表长度差值
	int n = 0;
	while (linkList1->next != NULL)
	{
		n++;
		linkList1 = linkList1->next;
	}

	while (linkList2->next != NULL) {
		n--;
		linkList2 = linkList2->next;
	}

	if (linkList1 != linkList2) {
		return NULL;
	}

	//长的链表做linklist1
	linkList1 = n > 0 ? head1 : head2;
	linkList2 = head1 == linkList1 ? head2 : head1;

	n = abs(n);
	while (n != 0) {
		n--;
		linkList1 = linkList1->next;
	}

	while (linkList1 != linkList2) {
		linkList1 = linkList1->next;
		linkList2 = linkList2->next;
	}

	return linkList1;

}
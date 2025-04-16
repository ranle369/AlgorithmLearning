#include <iostream>
using namespace std;

typedef struct Node {
	int data;
	Node* next;
}Node;

//������������������غϲ��֣�����ͷ���null���غϷ��ص�һ���غϽڵ�
Node* findMerge(Node * head1,Node* head2) {
	if (head1 == NULL || head2 == NULL) {
		return NULL;
	}

	Node* linkList1 = head1;
	Node* linkList2 = head2;

	//ʹ�ñ���N����¼���������Ȳ�ֵ
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

	//����������linklist1
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
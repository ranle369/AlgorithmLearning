#include<iostream>
#include<stack>
using namespace std;

struct Node {
	int data;
	Node* next;
};

//ʹ��n/2���ڴ�ջ�ռ�洢����Ȼ�󣬽��б���
bool stackHuiWen1(Node *head) {
	if (head->next == NULL || head == NULL) {
		return true;
	}
	stack<Node> stack;

	Node *one = head;
	Node* two = head->next;

	while (one != NULL && two != NULL) {
		one = one->next;
		two = two->next->next;
	}

	while(one != NULL){
		stack.push(*one);
	}

	while (!stack.empty()) {
		if (stack.top().data != head->data)
		{
			return false;
		}
		stack.pop();
		head = head->next;
	}

	return true;
}

//����n/2�ռ临�Ӷ��Ż����ռ临�Ӷ�Ϊ1
bool huiWen(Node *head) {
	if (head == NULL || head->next == NULL) {
		return true;
	}

	Node *n1 = head;
	Node* n2 = head;

	while (n1->next != NULL && n2->next->next != NULL) {
		n1 = n1->next;
		n2 = n2->next->next;
	}

	//ʹ��ͷ�巨˼�룬��n1�����node�����������ӵ������е�
	/*
	while (n1->next != NULL) {
		temp = n1;
		n1 = n1->next;
		temp->next = PHead;
		PHead = temp;
	}*/

	Node* NewHead = n1->next;
	n1->next = NULL;
	Node* PreNode = n1;
	Node* Temp = NULL;
	//�Ż�ͷ�巨
	while (NewHead != NULL) {
		Temp = NewHead;
		NewHead = NewHead->next;
		Temp->next = PreNode;
		PreNode = Temp;
	}
	
	n1 = head;
	n2 = NewHead;

	while (n1 != NULL && n2 != NULL) {
		if (n1->data != n2->data) {
			return false;
		}
		n1 = n1->next;
		n2 = n2->next;
	}

	PreNode = NULL;
	while (NewHead != NULL) {
		Temp = NewHead;
		NewHead = NewHead->next;
		Temp->next = PreNode;
		PreNode = Temp;
	}

	return true;

}
#include<iostream>
using namespace std;

typedef struct Node {
	int data;
	Node* Next;
}Node;

//两个带环链表，链表1和链表2.可能两链表相交在一起，也可能不相交在一起。
//相交在一起时候，可以在同一个node相交，也可能在不同node相交,然后找出第一个相重合的第一个节点
//head1：链表1，loop1：入环节点1，head2：链表2，loop2：入环节点2
Node* bothLoop(Node* head1,Node* Loop1,Node* head2,Node* Loop2) {
	Node* n1 = NULL;
	Node* n2 = NULL;

	if (Loop1 == Loop2) {

		n1 = head1;
		n2 = head2;

		int count = 0;
		while (n1 != Loop1) {
			count++;
			n1 = n1->Next;
		}

		while (n2 != Loop2) {
			count--;
			n2 = n2->Next;
		}

		n1 = count > 0 ? head1 : head2;
		n2 = n1 == head1 ? head2 : head1;

		count = abs(count);

		while (count != 0) {
			n1 = n1->Next;
		}

		while (n1 != n2) {
			n1 = n1->Next;
			n2 = n2->Next;
		}

		return findLoopNode(n1);
	}
	else {
		n1 = Loop1->Next;
		while (n1 != Loop1) {
			if (n1 == Loop2) {
				return Loop1;
			}
			n1 = n1->Next;
		}

		return NULL;
	}

}

Node* findLoopNode(Node* head) {

	if (head == NULL || head->Next == NULL || head->Next->Next == NULL) {
		return NULL;
	}

	Node* slow = head->Next;
	Node* fast = head->Next->Next;

	while (fast != slow) {
		fast = fast->Next->Next;
		slow = slow->Next;
	}

	fast = head->Next;

	while (fast != slow) {
		fast = fast->Next;
		slow = slow->Next;
	}

	return fast;
}

//无环链表返回第一个相遇节点
Node* noLoop(Node* head1, Node* head2) {
	if (head1 == NULL || head2 == NULL) {
		return NULL;
	}

	Node* n1 = NULL;
	Node* n2 = NULL;


	n1 = head1;
	n2 = head2;

	int count = 0;
	while (n1 != NULL) {
		count++;
		n1 = n1->Next;
	}

	while (n2 != NULL) {
		count--;
		n2 = n2->Next;
	}

	n1 = count > 0 ? head1 : head2;
	n2 = n1 == head1 ? head2 : head1;

	count = abs(count);

	while (count > 0) {
		n1 = n1->Next;
	}

	while (n1 != n2) {
		n1 = n1->Next;
		n2 = n2->Next;
	}

	return n1;
}


Node* getFirstMeet(Node* head1, Node* head2) {
	if (head1 == NULL || head2 == NULL) {
		return NULL;
	}

	Node* loop1 = findLoopNode(head1);
	Node* loop2 = findLoopNode(head2);

	if (loop1 != NULL && loop2 != NULL) {
		//是否两条链表都有环,都有环，返回环中相遇节点，或重合节点，无则null
		return bothLoop(head1, loop1, head2, loop2);
	}
	else if (loop1 == NULL && loop2 == NULL) {
		//两条链表都无环，返回重合的第一个节点，无则返回null
		return noLoop(head1,head2);
	}
	else
	{
		return NULL;
	}


}
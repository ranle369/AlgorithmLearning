#include<iostream>
#include<stack>
using namespace std;

struct Node {
	int data;
	Node* next;
};

//使用n/2的内存栈空间存储链表然后，进行比照
bool stackHuiWen(Node *head) {
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
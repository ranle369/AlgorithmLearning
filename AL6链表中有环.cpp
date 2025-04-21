#include<iostream>
#include<unordered_set>
using namespace std;

//找到入环的第一个节点，无则返回null

typedef struct Node {
	int data;
	Node* next;
}Node;

//空间复杂度为1的做法
Node* findLoopNode1(Node* head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL) {
		return NULL;
	}

	Node* fast = head->next->next;
	Node* slow = head->next;

	while (slow != fast) {
		if (slow == NULL || fast == NULL) {
			return NULL;
		}

		fast = fast->next->next;
		slow = slow->next;
	}

	fast = head->next;

	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

//初始化自定义哈希函数
struct NodeHash
{
	size_t operator()(const Node& node) const{
		return hash<int>()(node.data) ^ hash<Node*>()(node.next);
	}
};

//自定义相等比较
struct NodeEqueal {
	bool operator()(const Node& node1,const Node& node2) const{
		return node1.data == node2.data && node1.next == node2.next;
	}
};

//空间复杂度为n的
Node* findLoopNodeN(Node* head) {
	if (head == NULL) {
		return NULL;
	}

	//初始化自定义哈希set需要给，自定义对象，自定义哈希函数，和相等时候的比较方法
	unordered_set<Node, NodeHash, NodeEqueal> mySet;

	Node* node = head;

	while (node != NULL) {
		auto find = mySet.find(*node);
		if (mySet.empty() || find == mySet.end())
		{
			mySet.insert(*node);
		}

		if (find != mySet.end()) {
			return node;
		}
		node = node->next;
	}

	return NULL;
}

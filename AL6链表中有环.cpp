#include<iostream>
#include<unordered_set>
using namespace std;

//�ҵ��뻷�ĵ�һ���ڵ㣬���򷵻�null

typedef struct Node {
	int data;
	Node* next;
}Node;

//�ռ临�Ӷ�Ϊ1������
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

//��ʼ���Զ����ϣ����
struct NodeHash
{
	size_t operator()(const Node& node) const{
		return hash<int>()(node.data) ^ hash<Node*>()(node.next);
	}
};

//�Զ�����ȱȽ�
struct NodeEqueal {
	bool operator()(const Node& node1,const Node& node2) const{
		return node1.data == node2.data && node1.next == node2.next;
	}
};

//�ռ临�Ӷ�Ϊn��
Node* findLoopNodeN(Node* head) {
	if (head == NULL) {
		return NULL;
	}

	//��ʼ���Զ����ϣset��Ҫ�����Զ�������Զ����ϣ�����������ʱ��ıȽϷ���
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

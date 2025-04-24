#include<iostream>
using namespace std;
#include <queue>
#include<unordered_map>
#include <map>

typedef struct Node {
	int data;
	Node* left;
	Node* right;
};

struct hashFun {
	size_t operator()(const Node& node) const {
		return hash<int>()(node.data) ^ hash<Node*>()(node.left) ^ hash<Node*>()(node.right);
	}
};

struct hashEqual {
	bool operator()(const Node& node1, const Node& node2) const {
		return node1.data == node2.data && node1.left == node2.left && node1.right == node2.right;
	}
};

void firstWidth(Node* head) {
	if (head != NULL) {
		return;
	}
	queue<Node> queue;

	queue.push(*head);

	int max = -1;
	int curLevel = 1;
	unordered_map<Node, int, hashFun, hashEqual> map;
	int cruLevelCount = 0;
	while (!queue.empty()) {
		Node node = queue.front();
		map.insert(pair<Node,int>(node,curLevel));
		queue.pop();
		if (node.left != NULL) {
			queue.push(*node.left);
		}
		if (node.right != NULL) {
			queue.push(*node.right);
		}
		
	}

}
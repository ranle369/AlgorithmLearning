#include<iostream>
using namespace std;
#include<stack>

template<typename T>
struct Node {
	T data;
	Node* left;
	Node* right;
};

//先序遍历，头左右，进栈顺序头右左
void preOrderByStack(Node<int>& head) {
	cout << "pre-order"<<endl;

	stack<Node<int>> stack;

	stack.push(head);

	while (!stack.empty()) {

		cout << stack.top().data<< endl;

		if (stack.top().right != NULL) {
			stack.push(*stack.top().right);
		}

		if (stack.top().left != NULL) {
			stack.push(*stack.top().left);
		}
	}
}

//先序遍历，头左右，进栈1顺序头右左，出栈2顺序左右头
void postOrder(Node<int>& head) {
	stack<Node<int>> stack1;
	stack<Node<int>> stack2;

	stack1.push(head);

	while (!stack1.empty()) {
		Node<int> node = stack1.top();
		stack2.push(node);
		stack1.pop();

		if (node.left != NULL) {
			stack1.push(*node.left);
		}

		if (node.right != NULL) {
			stack1.push(*node.right);
		}
	}

	while (!stack2.empty()) {
		cout << stack2.top().data << endl;
		stack2.pop();
	}
}

template<typename T>
void centerOrder(Node<T>* head) {
	stack<Node<T>*>* stack = new stack();

	stack->push(head);
	
	//Node<T>* nodePoint;
	while (!stack->empty()) {
		Node<T>* node = stack->top();
		//nodePoint = node;
		//我这样写栈里面会存放之前所留在元素，让后一直执行
		// if (node->left != NULL) {
		//stack->push(node->left);
	//}
		/*if (node->left != NULL) {
			stack->push(node->left);
		}
		else
		{
			cout << node->data << endl;
			
			if (node->right != NULL) {
				stack->push(node->right);
			}

			if (node->right == NULL)
			{
				stack->pop();
			}
		}*/

		/*if (head != NULL)
		{
			stack->push(head);
			head = head->left;
		}
		else
		{
			head = stack->top();
			stack->pop();
			cout << head->data << endl;
			head = head->right;
		}*/

		if (node->left != NULL) {
			stack->push(node->left);
		}
		else if (node->right != NULL) {
			stack->pop();
			stack->push(node->right);
			cout << node->data << endl;
		}
	}

	
}
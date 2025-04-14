#include <iostream>
using namespace std;

typedef struct Node {
	int data;
	Node* Next;
}Node;

Node* LinkListFlag(Node* head,int num) {
	Node* sHead = NULL;
	Node* sTail = NULL;
	Node* eHead = NULL;
	Node* eTail = NULL;
	Node* mHead = NULL;
	Node* mTail = NULL;

	Node* newHead = NULL;

	while (head != NULL) {

		//ִ�ж�������
		newHead = head->Next;
		head->Next = NULL;

		if (head->data > num) {
			if (sHead == NULL) {
				sHead = head;
				sTail = head;
			}
			else
			{
				//������β������һ����βָ��Ҫ�������һ��λ��
				sTail->Next = head;
				sTail = head;
			}
		}
		else if (head->data < num) {
			if (eHead == NULL) {
				eHead = head;
				eTail = head;
			}
			else
			{
				eTail->Next = head;
				eTail = head;
			}
		}
		else
		{
			if (mHead == NULL) {
				mHead = head;
				mTail = head;
			}
			else
			{
				mHead->Next = head;
				mHead = head;
			}
		}
	}

	if (sTail != NULL) {
		//����eHeadʱnullҲû�£���Ϊstail������һ��Ҳ�ǿ�
		sTail->Next = eHead;
		//�ؼ�һ��������ж�ֱ�Ӷ��ǿգ��ǾͲ�Ҫ���ն˵�β��ָ���ε�ͷ������ֿ�ָ��ûָ��Ĵ���
		//Ҫ���ж�β��ָ��ǰ��β�ͣ�����������ж�
		eTail = eTail != NULL ? eTail : sTail;
	}

	if (eTail != NULL) {
		eTail->Next = mHead;
	}

	return sHead != NULL ? sHead : (eHead != NULL ? eHead : mHead);
}
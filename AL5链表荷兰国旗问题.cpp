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

		//执行断链操作
		newHead = head->Next;
		head->Next = NULL;

		if (head->data > num) {
			if (sHead == NULL) {
				sHead = head;
				sTail = head;
			}
			else
			{
				//处理完尾部的下一个后，尾指针要来到最后一个位置
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
		//就算eHead时null也没事，因为stail本身下一个也是空
		sTail->Next = eHead;
		//关键一部，如果中段直接都是空，那就不要让终端的尾巴指向大段的头，会出现空指针没指向的错误，
		//要让中段尾巴指向前段尾巴，像短语舍弃中段
		eTail = eTail != NULL ? eTail : sTail;
	}

	if (eTail != NULL) {
		eTail->Next = mHead;
	}

	return sHead != NULL ? sHead : (eHead != NULL ? eHead : mHead);
}
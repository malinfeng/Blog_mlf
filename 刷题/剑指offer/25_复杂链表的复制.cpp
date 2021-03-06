
#include <iostream>

struct RandomListNode
{
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
		{
			return pHead;
		}
		RandomListNode* pNode1 = pHead;
		while(pNode1 != NULL)//主链复制
		{
			RandomListNode* tempNode = new RandomListNode(pNode1->label);
			tempNode->next = pNode1->next;
			pNode1->next = tempNode;
			pNode1 = pNode1->next->next;//向下连走两个,指向主链新节点
		}

		pNode1 = pHead;
		while (pNode1 != NULL)//random复制
		{
			if (pNode1->random)
			{
				pNode1->next->random = pNode1->random->next;
			}
			pNode1 = pNode1->next->next;//向下连走两个,指向主链新节点
		}

		RandomListNode* pNewHead = pHead->next;
		RandomListNode* pNode2 = pNewHead;
		pNode1 = pHead;
		while (pNode1 != NULL)//分成两个链表
		{
			pNode1->next = pNode1->next->next;
			if (pNode2->next)
			{
				pNode2->next = pNode2->next->next;
			}
			else
			{
				pNode2->next = NULL;
			}

			pNode1 = pNode1->next;
			pNode2 = pNode2->next;
		}

		return pNewHead;
	}

	
};

// 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
// 返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

int main()
{
	RandomListNode *pNode1 = new RandomListNode(1);
	RandomListNode *pNode2 = new RandomListNode(2);
	RandomListNode *pNode3 = new RandomListNode(3);
	RandomListNode *pNode4 = new RandomListNode(4);
	RandomListNode *pNode5 = new RandomListNode(5);
	pNode1->next = pNode2;
	pNode2->next = pNode3;
	pNode3->next = pNode4;
	pNode4->next = pNode5;
	pNode1->random = pNode3;
	pNode2->random = pNode5;
	pNode4->random = pNode2;

	Solution a;
	RandomListNode *pResult = a.Clone(pNode1);
	return 0;
}



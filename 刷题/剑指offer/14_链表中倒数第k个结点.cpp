
#include <iostream>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
		if (pListHead == NULL)
		{
			return NULL;
		}

		ListNode* pret = pListHead;
		for (int i = 0; i < k; ++i)
		{
			if (pListHead == NULL)
			{
				return NULL;
			}
			pListHead = pListHead->next;
		}
		while (pListHead != NULL)
		{
			pListHead = pListHead->next;
			pret = pret->next;
		}
		return pret;
	}
};

// 输入一个链表，输出该链表中倒数第k个结点

int main()
{
	ListNode *pNode = new ListNode(1);
	pNode->next = new ListNode(2);
	pNode->next->next = new ListNode(3);
	pNode->next->next->next = new ListNode(4);
	
	Solution a;
	auto ret = a.FindKthToTail(pNode, 2);
	return 0;
}



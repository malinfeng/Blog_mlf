
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
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL)
		{
			return NULL;
		}

		ListNode *pT1 = pHead;
		ListNode *pT2 = pHead->next;
		while (pT1 != pT2)
		{
			if (pT1 == NULL || pT2 == NULL || pT2->next == NULL)
			{
				return NULL;
			}
			pT1 = pT1->next;
			pT2 = pT2->next->next;
		}//二者相遇，说明有环

		pT1 = pT1->next;
		pT2 = pHead;
		while (pT1 != pT2)
		{
			pT1 = pT1->next;
			pT2 = pT2->next;
		}
		return pT1;
	}
};

//给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

int main()
{
	ListNode *phead = new ListNode(1);
	phead->next = new ListNode(2);
	phead->next->next = new ListNode(3);
	ListNode *result = new ListNode(4);
	phead->next->next = result;
	result->next = new ListNode(5);
	result->next->next = new ListNode(6);
	result->next->next->next = new ListNode(7);
	result->next->next->next->next = result;

	Solution a;
	ListNode *ret = a.EntryNodeOfLoop(phead);
	
	
	return 0;
}




#include <iostream>

using namespace std;


struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
		{
			return pHead;
		}
		ListNode* ppre = new ListNode(-1);
		ppre->next = pHead;
		ListNode* pcur = pHead;
		ListNode* pnext = pHead->next;

		while (pnext != NULL)
		{
			pcur->next = ppre;
			ppre = pcur;
			pcur = pnext;
			pnext = pnext->next;
		}
		pcur->next = ppre;
		delete pHead->next;
		pHead->next = NULL;
		return pcur;
	}
};

// 输入一个链表，反转链表后，输出新链表的表头。

int main()
{
	Solution a;
	ListNode *pNode = new ListNode(1);
	pNode->next = new ListNode(2);
	pNode->next->next = new ListNode(3);
	pNode->next->next->next = new ListNode(4);

	auto ret = a.ReverseList(pNode);
	return 0;
}



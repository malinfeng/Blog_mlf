
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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* pret = new ListNode(-1);
		ListNode* travel = pret;
		while (pHead1 != NULL && pHead2 != NULL)
		{
			if (pHead1->val < pHead2->val)
			{
				travel->next = pHead1;
				travel = travel->next;
				pHead1 = pHead1->next;
			}
			else
			{
				travel->next = pHead2;
				travel = travel->next;
				pHead2 = pHead2->next;
			}
		}

		if (pHead1 == NULL)
		{
			travel->next = pHead2;
		}
		else if (pHead2 == NULL)
		{
			travel->next = pHead1;
		}
		ListNode* phelp = pret->next;
		delete pret;
		return phelp;
	}
};

// 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

int main()
{
	Solution a;
	ListNode *pNode1 = new ListNode(1);
	pNode1->next = new ListNode(2);
	pNode1->next->next = new ListNode(3);
	pNode1->next->next->next = new ListNode(4);
	
	ListNode *pNode2 = new ListNode(1);
	pNode2->next = new ListNode(2);
	pNode2->next->next = new ListNode(3);
	pNode2->next->next->next = new ListNode(4);
	
	auto ret = a.Merge(pNode1, pNode2);
	return 0;
}



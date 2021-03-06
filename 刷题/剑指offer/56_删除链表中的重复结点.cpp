
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
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL)
		{
			return NULL;
		}
		ListNode* pHeadpre = new ListNode(-1);
		pHeadpre->next = pHead;
		ListNode* ppre = pHeadpre;
		ListNode* pcur = pHead;
		ListNode* pnext = pcur->next;
		int deleflag = 0;
		while (pnext != NULL)
		{
			if (pcur->val == pnext->val)
			{
				deleflag = 1;
				delete pcur;
				ppre->next = pnext;
				pcur = pnext;
				pnext = pnext->next;
			}
			else if (deleflag)
			{
				deleflag = 0;
				delete pcur;
				ppre->next = pnext;
				pcur = pnext;
				pnext = pnext->next;
			}
			else
			{
				ppre = pcur;
				pcur = pnext;
				pnext = pnext->next;
			}
		}
		if (deleflag)
		{
			delete pcur;
			ppre->next = pnext;
		}

		return pHeadpre->next;
	}
};

//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

int main()
{
	ListNode *phead = new ListNode(1);
	phead->next = new ListNode(2);
	phead->next->next = new ListNode(3);
	phead->next->next->next = new ListNode(3);
	phead->next->next->next->next = new ListNode(4);
	phead->next->next->next->next->next = new ListNode(4);
	phead->next->next->next->next->next->next = new ListNode(5);

	Solution a;
	ListNode *ret = a.deleteDuplication(phead);
	
	return 0;
}



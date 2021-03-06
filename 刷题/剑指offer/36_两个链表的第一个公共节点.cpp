
#include <iostream>

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL)
	{
	}
};

class Solution 
{
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr || pHead2 == nullptr)
		{
			return nullptr;
		}
		int len1 = 0, len2 = 0, delta = 0;
		ListNode* travel1 = pHead1;
		ListNode* travel2 = pHead2;
		while (travel1 != nullptr)
		{
			travel1 = travel1->next;
			len1++;
		}
		while (travel2 != nullptr)
		{
			travel2 = travel2->next;
			len2++;
		}
		delta = len1 - len2;

		travel1 = pHead1;
		travel2 = pHead2;
		if (delta > 0)
		{
			while (delta > 0)
			{
				travel1 = travel1->next;
				delta--;
			}
		}
		else
		{
			delta = -delta;
			while (delta > 0)
			{
				travel2 = travel2->next;
				delta--;
			}
		}

		while (travel1 != nullptr && travel2 != nullptr)
		{
			if (travel1 == travel2)
			{
				return travel1;
			}
			travel1 = travel1->next;
			travel2 = travel2->next;
		}
		return nullptr;
	}
};
//输入两个链表，找出它们的第一个公共结点。
int main()
{
	ListNode* pHead1 = new ListNode(5);
	pHead1->next = new ListNode(7);
	pHead1->next->next = new ListNode(6);

	ListNode* pHead2 = new ListNode(3);
	pHead2->next = new ListNode(2);

	ListNode* pNode = new ListNode(3);//公共段
	pNode->next = new ListNode(10);

	pHead1->next->next->next = pNode;
	pHead2->next->next = pNode;

	Solution a;
	ListNode* presult = a.FindFirstCommonNode(pHead1, pHead2);

	return 0;
}



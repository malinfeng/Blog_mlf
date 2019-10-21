
#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) 
	{
		if (head == NULL)
		{
			return head;
		}
		ListNode* ret = new ListNode(-1);
		ret->next = head;
		ListNode* pre = ret;
		ListNode* cur1 = head;
		ListNode* cur2 = head->next;
		while (cur1 && cur2)
		{
			ListNode* nextstart = cur2->next;
			pre->next = cur2;
			cur2->next = cur1;
			cur1->next = nextstart;
			pre = cur1;
			cur1 = nextstart;
			if (cur1 == NULL)
			{
				break;
			}
			else
			{
				cur2 = cur1->next;
			}
			
		}
		return ret->next;
	}
};

/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。


示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


int main()
{
	return 0;
}

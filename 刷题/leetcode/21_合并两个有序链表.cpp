
#include <iostream>

using namespace std;


struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		if (l1 == NULL)
		{
			return l2;
		}
		if (l2 == NULL)
		{
			return l1;
		}
		ListNode* head = NULL;
		if (l1->val < l2->val)
		{
			head = l1;
			l1 = l1->next;
		}
		else
		{
			head = l2;
			l2 = l2->next;
		}
		ListNode* travel = head;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				travel->next = l1;
				travel = travel->next;
				l1 = l1->next;
			}
			else
			{
				travel->next = l2;
				travel = travel->next;
				l2 = l2->next;
			}
		}

		if (l1)
		{
			travel->next = l1;
		}
		else
		{
			travel->next = l2;
		}
		return head;
	}
};

/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


int main()
{
	return 0;
}

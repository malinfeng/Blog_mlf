
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		int count = 0;
		ListNode* pre = new ListNode(-1);
		pre->next = head;
		ListNode* tempnode = head;
		while (tempnode != NULL)
		{
			count++;
			tempnode = tempnode->next;
			if (count == n)
			{
				break;
			}
		}
		if (count < n)
		{
			throw std::logic_error("error");
			return head;
		}

		while (tempnode != NULL)
		{
			tempnode = tempnode->next;
			pre = pre->next;
		}

		ListNode* ret;
		if (pre->next == head)//删除头
		{
			ret = head->next;
			delete pre;
			delete head;
		}
		else
		{
			ret = head;
			pre->next = pre->next->next;
		}
		return ret;
	}
};

/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.


说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


int main()
{
	Solution a;
	ListNode *pnode = new ListNode(1);
	pnode->next = new ListNode(2);
	pnode->next->next = new ListNode(3);
	pnode->next->next->next = new ListNode(4);
	pnode->next->next->next->next = new ListNode(5);

	auto ret = a.removeNthFromEnd(pnode, 6);
	return 0;
}


#include <iostream>
#include <vector>

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
	vector<int> printListFromTailToHead(ListNode* head)
	{
		std::vector<int> retvec;
		while (head != NULL)
		{
			retvec.emplace_back(head->val);
			head = head->next;
		}
		reverse(retvec.begin(), retvec.end());
		return retvec;
	}
};

// 输入一个链表，按链表从尾到头的顺序返回一个ArrayList。


int main()
{
	Solution a;
	ListNode *pNode = new ListNode(1);
	pNode->next = new ListNode(2);
	pNode->next->next = new ListNode(3);
	pNode->next->next->next = new ListNode(4);

	auto ret = a.printListFromTailToHead(pNode);
	return 0;
}


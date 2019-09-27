
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL || l2 == NULL)
        {
            return NULL;
        }
        ListNode* ret = l1;
        ListNode* l1pre = new ListNode(-1);
        int flag = 0;
        while(l1 && l2)
        {
            l1->val += (l2->val + flag);
            flag = 0;
            if (l1->val > 9)
            {
                l1->val -= 10;
                flag = 1;
            }
            l1pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 && flag)
        {
            l1->val += flag;
            flag = 0;
            if (l1->val > 9)
            {
                l1->val -= 10;
                flag = 1;
            }
            l1pre = l1;
            l1 = l1->next;
        }
        
        if (l2)
        {
            l1pre->next = l2;
            while(l2 && flag)
            {
                l2->val += flag;
                flag = 0;
                if (l2->val > 9)
                {
                    l2->val -= 10;
                    flag = 1;
                }
                l1pre = l2;
                l2 = l2->next;
            }
        }
        if (flag)
        {
            l1pre->next = new ListNode(1);
        }
        
        return ret;
    }
};

/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


int main()
{

	return 0;
}


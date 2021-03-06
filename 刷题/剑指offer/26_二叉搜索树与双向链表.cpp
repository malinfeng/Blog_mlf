
#include <iostream>

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) 
	{
	}
};

class Solution 
{
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr)
		{
			return nullptr;
		}
		TreeNode* pre = nullptr;
		Travel(pRootOfTree,pre);

		while (pRootOfTree->left != nullptr)
		{
			pRootOfTree = pRootOfTree->left;
		}
		return pRootOfTree;
	}

	void Travel(TreeNode* cur, TreeNode*& pre)
	{
		if (cur == NULL)
		{
			return;
		}
		Travel(cur->left, pre);//遍历完,per指向已经转成双向链表的左子树的尾节点

		cur->left = pre;//当前节点的左边指向上一个节点
		if (pre != nullptr)
		{
			pre->right = cur;
		}
		pre = cur;//访问完，当前节点成为前一个节点
		Travel(cur->right, pre);//接着遍历右子树
	}

};

// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。

//思路，中序遍历的方法，顺便形成双向链表
int main()
{
	TreeNode *testTree = new struct TreeNode(10);
	testTree->left = new struct TreeNode(4);
	testTree->right = new struct TreeNode(14);
	testTree->left->left = new struct TreeNode(2);
	testTree->left->right = new struct TreeNode(5);
	testTree->right->left = new struct TreeNode(11);
	testTree->right->right = new struct TreeNode(16);

// 	TreeNode *testTree = new struct TreeNode(5);
// 	testTree->right = new struct TreeNode(6);
// 	testTree->right->right = new struct TreeNode(8);
// 	testTree->right->right->right = new struct TreeNode(9);
// 	testTree->right->right->right->right = new struct TreeNode(11);


	Solution a;
	TreeNode *result = a.Convert(testTree);

	return 0;
}


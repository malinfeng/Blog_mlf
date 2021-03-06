
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot)
	{
		vector<vector<int> > results;
		if (pRoot == NULL)
		{
			return results;
		}
		vector<TreeNode*> vec1;
		vector<TreeNode*> vec2;
		vec1.push_back(pRoot);
		bool flag = true; //从左向右的标记位
		while (!vec1.empty() || !vec2.empty())
		{
			if (flag)//从左向右打印
			{
				vector<int> result;
				for (auto it = vec1.begin(); it != vec1.end(); ++it)
				{
					if (*it == NULL)
					{
						continue;
					}
					vec2.push_back((*it)->left);
					vec2.push_back((*it)->right);
					result.push_back((*it)->val);
				}
				flag = !flag;
				vec1.clear();
				results.push_back(result);
			}
			else//从右往左打印
			{
				vector<int> result;
				for (auto it = vec2.begin(); it != vec2.end(); ++it)
				{
					if (*it == NULL)
					{
						continue;
					}
					vec1.push_back((*it)->left);
					vec1.push_back((*it)->right);
					result.push_back((*it)->val);
				}
				flag = !flag;
				vec2.clear();
				reverse(result.begin(), result.end());
				results.push_back(result);
			}
		}
		return results;
	}

};

//请实现一个函数按照之字形打印二叉树，
// 即第一行按照从左到右的顺序打印，
// 第二层按照从右至左的顺序打印，
// 第三行按照从左到右的顺序打印，其他行以此类推。
// 用例:
// {8, 6, 10, 5, 7, 9, 11}
// 对应输出应该为:
// [[8], [10, 6], [5, 7, 9, 11]]


int main()
{
	Solution a;
	TreeNode *testTree = new struct TreeNode(8);
	testTree->left = new struct TreeNode(6);
	testTree->right = new struct TreeNode(10);
	testTree->left->left = new struct TreeNode(5);
	testTree->left->right = new struct TreeNode(7);
	testTree->right->left = new struct TreeNode(9);
	testTree->right->right = new struct TreeNode(11);
	
	vector<vector<int> > result = a.Print(testTree);

	return 0;
}

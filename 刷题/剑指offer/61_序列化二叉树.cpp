
#include <iostream>
#include <string>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};


class Solution
{
public:
	char* Serialize(TreeNode *root)//前序遍历
	{
		string str;
		Serialize_Str(root, str);

		char *ret = new char[str.length() + 1];
		int i;
		for (i = 0; i < str.length(); i++) 
		{
			ret[i] = str[i];
		}
		ret[i] = '\0';
		return ret;
	}
	TreeNode* Deserialize(char *str)
	{
		string Str = str;
		return Deserialize_Str(Str);
	}

	void Serialize_Str(TreeNode *root, string &str)
	{
		if (root)//有值
		{
			str += to_string(root->val);
			str += ',';//表示数字结束
		}
		else//NULL
		{
			str += '#';
			return;
		}
		Serialize_Str(root->left, str);
		Serialize_Str(root->right, str);
		return;
	}

	TreeNode* Deserialize_Str(string &str)
	{
		if (str.front() != '#')//根节点存在
		{
			int curNum = 0;
			int i = 0;
			while (str[i] != ',')
			{
				curNum = curNum * 10 + (str[i] - '0');
				++i;
			}
			TreeNode* curNode = new TreeNode(curNum);
			str = str.substr(i + 1, str.length() - 1);

			curNode->left = Deserialize_Str(str);
			curNode->right = Deserialize_Str(str);
			return curNode;
		}
		else//当前节点为null
		{
			str = str.substr(1, str.length() - 1);
			return NULL;
		}
	}
};

//请实现两个函数，分别用来序列化和反序列化二叉树


//这ZZ题目非要用char*,蛋疼的一批

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

	char * str = a.Serialize(testTree);
	TreeNode *result = a.Deserialize(str);

	return 0;
}
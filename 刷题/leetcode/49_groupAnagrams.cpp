#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		vector<vector<string>> ret;
		map<unsigned long, int> num2idx;
		vector<int> nums = 
		{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
		31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 
		79, 83, 89, 97, 101, 103 };
		
		for (int i = 0; i < strs.size(); ++i)
		{
			unsigned long strnum = 1;
			for (int j = 0; j < strs[i].size(); ++j)
			{
				strnum *= nums[strs[i][j] - 'a'];
			}
			if (num2idx.count(strnum))
			{
				ret[num2idx[strnum]].push_back(strs[i]);
			}
			else
			{
				ret.push_back(vector<string>(1, strs[i]));
				num2idx[strnum] = ret.size() - 1;
			}
		}
		return ret;
	}
};

/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:
输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{
	Solution a;
	vector<string> vec = {"eat", "tea", "tan", "ate", "nat", "bat"};
	auto ret = a.groupAnagrams(vec);
	return 0;
}

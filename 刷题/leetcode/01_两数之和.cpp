
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ret;
        unordered_map<int, int> mymap;
        for (int i = 0; i < nums.size(); ++i)
        {
            mymap[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mymap.count(target - nums[i]))
            {
                int num2 = mymap[target - nums[i]];
                if (num2 == i)
                {
                    continue;
                }
                else if (num2 < i)
                {
                    ret.push_back(num2);
                    ret.push_back(i);
                    return ret;
                }
                else
                {
                    ret.push_back(i);
                    ret.push_back(num2);
                    return ret;
                }
            }
        }
        return ret;
    }
};

/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//一个map解决，空间换时间
//或者排序后两端查找也可以

int main()
{

	return 0;
}


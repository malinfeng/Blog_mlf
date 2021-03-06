
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool IsContinuous(vector<int> numbers ) 
    {
        if(numbers.size() != 5)
        {
            return false;
        }
        int min = 65535;
        int max = -1;
        int nums[14] = {0};
        for(auto num : numbers)
        {
            if (num == 0)
            {
                continue;
            }
            nums[num]++;
            if(nums[num] == 2)
            {
                return false;
            }
            if(num < min)
            {
                min = num;
            }
            else if(num > max)
            {
                max = num;
            }
        }
        if((max - min)<5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

//对于一副扑克牌，大\小 王可以看成任何数字,随机抽五张牌，看能否排成顺子。
//如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。

int main()
{
	vector<int> numbers = {0, 3, 4, 5, 6};
	Solution a;
	auto result = a.IsContinuous(numbers);
	return 0;
}



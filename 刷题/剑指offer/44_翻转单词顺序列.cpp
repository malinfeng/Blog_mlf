
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string ReverseSentence(string str) 
    {
        string res = "", tmp = "";
        for(unsigned int i = 0; i < str.size(); ++i)
        {
            if(str[i] == ' ') 
            {
                res = " " + tmp + res;
                tmp = "";
            }
            else 
            {
                tmp += str[i];
            }
        }
        if(tmp.size()) 
        {
            res = tmp + res;
        }
        return res;
    }
};

//翻转单词，例如，“student. a am I”。
//正确的句子应该是“I am a student.”。
//Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

int main()
{
	string str = "student. a am I";
	Solution a;
	auto result = a.ReverseSentence(str);
	return 0;
}



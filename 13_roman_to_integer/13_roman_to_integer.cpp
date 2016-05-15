/*************************************************************************
	> File Name: 13_roman_to_integer.cpp
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/15
 ************************************************************************/

class Solution {
public:
    bool isIXC(char ch){
        return ((ch == 'I') || (ch == 'X') || (ch == 'C'));
    }
    
    int romanToInt(string s) {
        int len = s.length();
        unordered_map<char, int> dict = {   {'I', 1},
                                            {'X', 10},
                                            {'C', 100},
                                            {'M', 1000},
                                            {'V', 5},
                                            {'L', 50},
                                            {'D', 500}  };
        int sum = dict[ s[len - 1] ];

        for(int i=len-2; i>=0; i--){ // 小技巧：从字符串的末尾开始处理，更简单
            if(isIXC(s[i]) && dict[s[i]] < dict[s[i+1]]){
                sum -= dict[s[i]];
            }else{
                sum += dict[s[i]];
            }
        }
        
        return sum;
    }
};

/*************************************************************************
	> File Name: 242_valid_anagram.cpp
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/15
 ************************************************************************/

class Solution {
public:
    // 用map容器映射字符串中每个字符和其出现的次数
    // 在s中出现，则次数加一，在t中出现，则次数减一
    // 最后检查map中的value值是否都为0
    bool isAnagram_1(string s, string t) {
        int len = s.length();
        unordered_map<char, int> count;
        
        if(len != t.length()) return false;
        
        for(int i=0; i<len; i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        
        for(auto i : count) if(i.second) 
            return false;
        
        return true;
    }
    
    // 先对这两个字符串进行排序，然后比较，时间开销最大
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};


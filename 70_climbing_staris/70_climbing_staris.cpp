/*************************************************************************
	> File Name: 70_climbing_staris.cpp
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/16
 ************************************************************************/

class Solution {
public:
    // fibonacci数列
    // 不用递归方法，因为数字过大时，递归需要耗费太大的内存
    int climbStairs(int n) {
        if(n <= 3) return n;
        
        int first = 2; // 求和时的前面第一个数
        int second = 3; // 求和时的前面第二个数
        int ways = 0;
        
        for(int i=3; i<n; ++i){
            ways = first + second;
            first = second;
            second = ways;
        }
        
        return ways;
    }
};


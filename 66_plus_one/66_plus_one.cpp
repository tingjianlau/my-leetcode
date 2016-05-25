/*************************************************************************
	> File Name: 66_plus_one.cpp
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/25
 ************************************************************************/

class Solution {
public:
    vector<int> plusOne_1(vector<int>& digits) {
        bool carry = true; // 进位标志，初始化为1，是将加一操作看做进位标志
        
        for(int i = digits.size()-1; i >=0; --i){
            if(digits[i] == 9 && carry){
                digits[i] = 0;
                carry = true;
            }else{
                if(carry)
                    digits[i] += 1;
                carry = false;
            }
        }
        
        if(carry){  // 最高位是否进位 
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
      
    vector<int> plusOne(vector<int>& digits) {  // 这种方法更简单 
        for(int i = digits.size()-1; i >=0; --i){
            if(digits[i] == 9){
                digits[i] = 0;
            }else{
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        
        return digits;
    }
};


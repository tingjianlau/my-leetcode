/*************************************************************************
	> File Name: 326_power_of_three.c
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/16
 ************************************************************************/

// loop
bool isPowerOfThree_1(int n) {
    while(n){
        if(n % 3 != 0)
            return false;
        n /= 3;
    }
    
    return true;
}

// recursion
bool isPowerOfThree_2(int n) {
    return (n > 0) && ((n == 1) || ((n %3 == 0) && isPowerOfThree(n / 3)));
}

// no loop and recursion
bool isPowerOfThree(int n) {
    return (n > 0) && (1162261467 % n == 0); // 3^19=1162261467 and 3^20>max(int)
}

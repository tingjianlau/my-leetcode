/*************************************************************************
	> File Name: 342_power_of_four.c
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/30
 ************************************************************************/

// Runtime: 4ms
// (num&(num-1)) == 0: 将num和num-1作位与操作，如果是4的powe，则等于0
bool isPowerOfFour(int num) {
    return (num > 0) && ((num&(num-1)) == 0 && (num-1)%3 == 0);
}




/*************************************************************************
	> File Name: 202_happy_number.c
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/16
 ************************************************************************/

int digitSquareSum(int n){
    int sum = 0;
    
    while(n){
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

// 采用Floyd Cycle Detection算法
bool isHappy(int n) {
    int slow = n, fast = n;
    
    do{
        slow = digitSquareSum(slow); // tortoise
        fast = digitSquareSum(digitSquareSum(fast)); // hare每次前进两步
    }while(slow != fast); // 龟兔相遇时停止

    return (slow == 1);
}


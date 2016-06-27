/*************************************************************************
	> File Name: 9_palindrome_number.c
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/06/27
#	> Detail: 
 ************************************************************************/

bool isPalindrome_1(int x) {
    if(x<0 || (x!=0 && x%10==0)) return false;
    int half_sum = 0;   // 反转x的一半

    while(x > half_sum){
        half_sum = half_sum * 10 + x % 10;
        x /= 10;
    }

    return (x == half_sum) || (x == half_sum/10);
}

bool isPalindrome(int x) {
    int y = 0, z = x;   

    while(z > 0){
        y = y * 10 + z % 10;
        z /= 10;
    }

    return x == y;
}


/*************************************************************************
	> File Name: 344_reverse_string.cpp
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/10
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// Time: O(n)
// Space: O(1)
string reverseString_1(string s){
    reverse(s.begin(), s.end());

    return s;
}

// Time: O(n)
// Space: O(1)
string reverseString_2(string s){
    for(int p=0, q=s.length()-1; p < q; p++, q--){
        swap(s[p], s[q]);
    }

    return s;
}

int main(){
    cout << reverseString_1("hello") << endl;
    cout << reverseString_2("abcdef") << endl;

    return 0;
}

/*************************************************************************
	> File Name: 345_reverse_vowels_of_a_string.cpp
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/11
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char ch){
    const string vowels = "aeiou";
    
    return vowels.find(tolower(ch)) != string::npos;
}

// Time: O(n)
// Space: O(1)
string reverseVowels_1(string s){
    for(int p=0, q=s.length()-1; p<q;){
        if(!isVowel(s[p]))
            ++p;
        else if(!isVowel(s[q]))
            --q;
        else{
            swap(s[p++], s[q--]);
        }
    }

    return s;
}

int main(){
    cout << reverseVowels_1("leetcode") << endl;
    cout << reverseVowels_1("hello") << endl;
    cout << reverseVowels_1("aeiou") << endl;
    cout << reverseVowels_1("") << endl;

    return 0;
}

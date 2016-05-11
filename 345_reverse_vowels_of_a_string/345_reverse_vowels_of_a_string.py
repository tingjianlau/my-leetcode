#!/usr/bin/env python
#-*- coding: UTF-8 -*-

##########################################################################
#	> File Name: 345_reverse_vowels_of_a_string.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/11
#########################################################################

# Time: O(n)
# Space: O(1)
def reverseString_1(s):
    vowels = 'aeiou'
    string = list(s)
    p, q = 0, len(s)-1

    while(p < q):
        if string[p].lower() not in vowels:
            p += 1
        elif string[q].lower() not in vowels:
            q -= 1;
        else:
            string[p], string[q] = string[q], string[p]
            p += 1
            q -= 1

    return "".join(string)

if __name__ == '__main__':
    print reverseString_1('leetcode')
    print reverseString_1('hello')
    print reverseString_1('aeiou')
    print reverseString_1('')

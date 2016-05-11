#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: 344_reverse_string.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/10
#########################################################################

# Time: O(n)
# Space: O(n)
def reverseString_1(s):
    return s[::-1]  # 切分

# Time: O(n)
# Space: O(n)
def reverseString_2(s):
    string = list(s)
    p, q = 0, len(string)-1
    while(p < q):
       string[p], string[q] = string[q], string[p]
       p += 1
       q -= 1

    return "".join(string)
        
if __name__ == '__main__':
    print reverseString_1("hello")
    print reverseString_2("abcdef")


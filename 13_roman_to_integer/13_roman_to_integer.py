#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: 13_roman_to_integer.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/15
#########################################################################

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        dict = {'I':1, 'X':10, 'C':100, 'M':1000, 'V':5, 'L':50, 'D':500}
    
        sum = dict[ s[-1] ] 
        
        for i in range(len(s)-2, -1, -1): # 从字符串的最后一个字符开始累加，可过滤长度为1的字符串 
            if s[i] in 'IXC' and dict[ s[i] ] <  dict[ s[i+1] ]:
                sum -= dict[ s[i] ]
            else:
                sum += dict[ s[i] ]
        
        return sum

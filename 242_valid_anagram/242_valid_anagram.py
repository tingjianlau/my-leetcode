#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: 242_valid_anagram.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/15
#########################################################################

class Solution(object):
    def isAnagram_1(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return sorted(s) == sorted(t)
        
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
            
        dict = {}
        for item in s:
            dict[item] = dict.get(item, 0) + 1  # 如果找不到对应字符时，将其键值设为0，否则加一
        for item in t:
            dict[item] = dict.get(item, 0) - 1;
            
        for count in dict.values():
            if count is not 0:
                return False
        
        return True
            
        

#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: 70_climbing_stairs.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/16
#########################################################################

class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 3: return n
        
        first, second, ways = 2, 3, 0
        
        for i in range(3, n):
            ways = first + second
            first = second
            second = ways
            
        return ways

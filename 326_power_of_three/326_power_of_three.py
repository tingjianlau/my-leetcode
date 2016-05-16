#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: 326_power_of_three.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/16
#########################################################################

// Recursion
// Runtimme: 48ms
class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return (n > 0) and (n is 1 or (n %3 == 0 and self.isPowerOfThree(n/3)))

#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: 66_plus_one.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/25
#########################################################################

ass Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        for i in range(len(digits)):
            if digits[i] is 9:
                digits[i] = 0
            else:
                digits[i] += 1
                return digits
        
        digits[0] = 1
        digits.append(0)
        
        return digits

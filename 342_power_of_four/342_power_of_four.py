#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: 342_power_of_four.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/30
#########################################################################

class Solution(object):
    # Runtime: 69 ms
    def isPowerOfFour_1(self, num):
        """
        :type num: int
        :rtype: bool
        """
        return num > 0 and (num is 1 or (num % 4 == 0 and self.isPowerOfFour(num / 4)))
    # 转换成二进制，如果是4的power，则除最高位是1外其他位为0，其位数是奇数
    
    # Runtime: 69 ms
    def isPowerOfFour_2(self, num):
        """
        :type num: int
        :rtype: bool
        """
        binNum = bin(num).replace('0b', '')
        
        return num == 1 or ((len(binNum) - 1) %2 == 0 and num - int(math.pow(2, len(binNum) - 1)) == 0)
    
    # Runtime: 60 ms
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        return num > 0 and ((num&(num-1)) == 0 and (num-1) %3 == 0)

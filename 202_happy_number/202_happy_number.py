#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: 202_happy_number.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/16
#########################################################################

class Solution(object):
    def digitSquareSum(self, n):
        return sum([int(i) ** 2 for i in str(n)])   # 注意此简练写法
    
    # Floyd判圈算法
    def isHappy_1(self, n):
        """
        :type n: int
        :rtype: bool
        """
        slow, fast = n, self.digitSquareSum(n)
        
        while slow != fast:
            slow = self.digitSquareSum(slow)
            fast = self.digitSquareSum(self.digitSquareSum(fast))
            
        return slow is 1
    
    # hash table法
    def isHappy(self, n):
        hashTable = set()  # 申请一个无序无重复的集合
        
        while n != 1:
            n = self.digitSquareSum(n)
            if n in hashTable:
                return False
            else:
                hashTable.add(n)
        else:      
            return True 

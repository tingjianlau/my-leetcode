#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: 1_two_sum.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/17
#########################################################################

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}   # 差值字典
        
        for i in range(len(nums)):
            if nums[i] not in dict: # 将差值压入字典中
                dict[target - nums[i]] = i
            else:   # 在差值字典中找到当前值相同的元素
                return [dict[nums[i]], i]

#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: 88_merge_sorted_array.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/31
#########################################################################

class Solution(object):
    # Runtime: 60 ms
    def merge_1(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        p, q, idx = m - 1, n - 1, m + n - 1
        
        while p >= 0 and q >= 0:
            if nums1[p] > nums2[q]:
                nums1[idx] = nums1[p]
                p -= 1
            else:
                nums1[idx] = nums2[q]
                q -= 1
            idx -= 1
            
        while q >= 0:
            nums1[idx] = nums2[q]
            idx -= 1
            q -= 1
        
    # 方法1的简略写法  
    # Runtime: 68 ms
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        while m > 0 and n > 0:
            if nums1[m-1] > nums2[n-1]:
                nums1[m + n - 1] = nums1[m-1]
                m -= 1
            else:
                nums1[m + n - 1] = nums2[n-1]
                n -= 1
            
        if n>0:
            nums1[:n] = nums2[:n]
        

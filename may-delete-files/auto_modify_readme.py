#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: auto_modify_readme.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/26
#########################################################################

import os
from os import system

if __name__ == '__main__':
    dict = { }
    dict['linked-list-cycle/'] = '用Floyd Cycle Detection算法判断链表是否有环'
    dict['two-sum/'] = '用Hash Table法求数组中某两数的特定和'
    dict['happy-number/'] = 'Floyd判圈算法的应用'
    dict['merge-two-sorted-lists/'] = '合并两个已排序的单链表'
    dict['lowest-common-ancestor-of-a-binary-search-tree/'] = '二叉搜索树的最小祖先节点'
    dict['valid-anagram/'] = '判断是否是易位构词'
    dict['swap-nodes-in-pairs/'] = '单链表交换相邻的两个节点'
    dict['power-of-three/'] = '3的幂次方'
    dict['reverse-string/'] = '反转字符串'
    dict['reverse-vowels-of-a-string/'] = '转置特定字符串'
    dict['puls-one'] = '字符串的整数加法运算'
    dict['climbing-stairs/'] = 'fibonacci数列的非递归写法'
    dict['remove-duplicates-from-sorted-list/'] = '已排序的单链表去重操作'

    for key, val in dict.items():
        command = 'python capture_html_content.py ' + key + ' ' + val
        system(command)

    print ('Done!')

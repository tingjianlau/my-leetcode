#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: 26_remove_duplicates_from_sorted_array.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/30
#########################################################################

class Solution {
public:
    // Runtime: 32 ms
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int j = 1;
        
        if(len < 2) return len;
        
        for(int i=1; i<len; ++i){
            if(nums[i] != nums[i-1]){ // 不理会其他的变化，只要相邻元素不一样就将后者放到不重复的子列中。
                nums[j++] = nums[i]; // j指明了不重复子列的边界
            }
        }
        
        return j;
    }
};

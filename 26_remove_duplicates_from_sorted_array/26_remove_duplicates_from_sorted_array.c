/*************************************************************************
	> File Name: 26_remove_duplicates_from_sorted_array.c
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/30
 ************************************************************************/

// Runtime: 12 ms
int removeDuplicates(int* nums, int numsSize) {
    int j = 1;
    if(numsSize < 2) return numsSize;
    
    for(int i=1; i<numsSize; ++i)
        if(nums[i] != nums[i-1]) // 不理会其他的变化，只要相邻元素不一样就将后者放到不重复的子列中。
            nums[j++] = nums[i]; // j指明了不重复子列的边界
    
    return j;
}


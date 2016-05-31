/*************************************************************************
	> File Name: 88_merge_sorted_array.cpp
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/31
 ************************************************************************/

class Solution {
public:
    // Runtime: 4 ms
    // 两个指针，分别指向两个数组的末尾，而不是数组的头
    // 第三个指针指向最后数组的最后一个位置，用于接收前两个指针中指向元素的最大值
    void merge_1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m - 1;
        int q = n - 1;
        int idx = m + n - 1;
        
        while(p >= 0 && q >= 0){
            if(nums1[p] > nums2[q]){
                nums1[idx--] = nums1[p--];
            }else{
                nums1[idx--] = nums2[q--];
            }
        }
        while(q >= 0){
            nums1[idx--] = nums2[q--];
        }
    }
    
    // Runtime: 4 ms
    // 方法1的简略写法
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m - 1;
        int q = n - 1;
        int idx = m + n - 1;
        
        while(q >= 0){
            nums1[idx--] = (p >= 0 && nums1[p] > nums2[q]) ? nums1[p--] : nums2[q--];
        }
    }
};


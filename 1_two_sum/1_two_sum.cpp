/*************************************************************************
	> File Name: 1_two_sum.cpp
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/17
 ************************************************************************/

class Solution {
public:
    vector<int> twoSum_1(vector<int>& nums, int target) {
        unordered_map<int, int> m; // 存放扫描过的元素
        int len = nums.size();
        int delta = 0;      // 差值
        vector<int> res;
        
        for(int i = 0; i < len; ++i){
            delta = target - nums[i];
            
            if(m.find(delta) != m.end()){   // 在已有的map中查找是否有值等于差值
                res.push_back(m[delta]);
                res.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        
        return res;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;  // 存放已经扫描过的元素与target的差值
        int len = nums.size();
        vector<int> res;
        
        for(int i = 0; i < len; ++i){
            if(m.find(nums[i]) != m.end()){  
                res.push_back(m[nums[i]]);
                res.push_back(i);
                break;
            }else{
                m[target - nums[i]] = i;
            }
        }
        
        return res;
    }
}; 

/*************************************************************************
	> File Name: 118_Pascals_Triangle.cpp
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/19
 ************************************************************************/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        //cout << res[0][1] << endl;
        for(int j = 0; j < numRows; ++j){
            res[j].resize(j+1);
            res[j][0] = 1; // 第一列全置为1
        }
        
        for(int i = 1; i < numRows; ++i){
            for(int j = 1; j <= i; ++j){
                res[i][j] = (j == i) ? res[j-1][j-1] : res[i-1][j-1] + res[i-1][j]; // 每个元素是上一行前一列和上一行当前列两个元素的和
            }
        }
        
        return res;
    }
    
};


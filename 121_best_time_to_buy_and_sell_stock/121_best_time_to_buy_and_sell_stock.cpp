/*************************************************************************
	> File Name: 121_best_time_to_buy_and_sell_stock.cpp
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/16
 ************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxProfit = 0;
       int minPrice = INT_MAX;
       int len = prices.size();
       
       for(int i=0; i<len; ++i){
           minPrice = min(minPrice, prices[i]);
           maxProfit = max(maxProfit, prices[i] - minPrice);
       }
       
       return maxProfit;
    }
};


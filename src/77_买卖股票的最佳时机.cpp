#include<iostream>
using namespace std;
#include<vector>

//暴力
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int res=0;
//         int n = prices.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 res=max(prices[j]-prices[i],res);
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_prices=prices[0];
        int res=0;
        for(int price:prices){
            res = max(res,price-min_prices);
            min_prices = min(min_prices,price);
        }
        return res;
    }
};
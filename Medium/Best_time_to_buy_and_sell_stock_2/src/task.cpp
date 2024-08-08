#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    void recursive_profit(vector<int> & prices,int cur_profit, bool has_stock,int stock_value,int cur_index,int & best_value) {

        if(cur_index>=(int)prices.size()-1) {
            if(has_stock) {
                if(cur_profit-stock_value+prices[cur_index]>best_value) {
                    best_value=cur_profit-stock_value+prices[cur_index];
                }

            }
            else {
                if(cur_profit>best_value) {
                    best_value=cur_profit;
                }

            }
            return;
        }
        for(size_t i=(size_t)cur_index+1;i<prices.size();i++) {
            if(has_stock) {
                recursive_profit(prices,cur_profit-stock_value+prices[i],false,0,(int)i,best_value);

            }
            else {
                recursive_profit(prices,cur_profit,true,prices[i],(int)i,best_value);

            }
        }

    }

    int maxProfit(vector<int>& prices) {
        int profit=0;
        int best_profit=0;
        recursive_profit(prices,profit,false,0,-1,best_profit);

        return best_profit;
    }
};

int main(void) {

    Solution sol;

    vector<int>prices_1={7,1,5,3,6,4};
    assert(sol.maxProfit(prices_1)==7);

    vector<int>prices_2={1,2,3,4,5};
    assert(sol.maxProfit(prices_2)==4);

    vector<int>prices_3={7,6,4,3,1};
    assert(sol.maxProfit(prices_3)==0);
}
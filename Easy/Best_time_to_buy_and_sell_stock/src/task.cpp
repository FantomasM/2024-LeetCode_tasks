#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_profit=0;

        int best_profit_prev=0;
        for(ssize_t i=(ssize_t)prices.size()-2;i>=0;i--) {
            if(i==(ssize_t)prices.size()-2) {
                best_profit_prev=prices[i+1]-prices[i];

            }
            else {
                if(prices[i+1]-prices[i]>best_profit_prev+prices[i+1]-prices[i]) {
                    best_profit_prev=prices[i+1]-prices[i];

                }
                else {
                    best_profit_prev=best_profit_prev+prices[i+1]-prices[i];

                }
            }
            if(best_profit_prev>best_profit) {
                best_profit=best_profit_prev;
               
            }
        }


        return best_profit;
    }
};


int main(void) {

    Solution sol;

    vector<int>prices_1={7,1,5,3,6,4};

    assert(sol.maxProfit(prices_1)==5);

    vector<int>prices_2={7,6,4,3,1};

    assert(sol.maxProfit(prices_2)==0);

}
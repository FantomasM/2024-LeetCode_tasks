#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
   

    int maxProfit(vector<int>& prices) {


        int profit=0;
        int start=prices[0];
        for(size_t i=1;i<prices.size();i++) {
            if(start<prices[i]) {
                profit+=prices[i]-start;
            }
            start=prices[i];
        }
        return profit;



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
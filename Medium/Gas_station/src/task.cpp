#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int next_index(const vector<int> & gas , int index_next) {
        if (index_next >= (int)gas.size()) {
            int tmp=index_next%(int)gas.size();
            if(tmp<0) {
                tmp+=(int)gas.size();
            }
            return tmp;
        }
        if(index_next<0) {
            index_next+=(int)gas.size();
        }
        return index_next;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> low_gas(cost.size(),-1);

        for(size_t i = 0; i < gas.size(); i++) {
            int current_gas=gas[i];
            int next_index_int=next_index(gas,(int)i+1);
            bool can_go=true;
       
            for(size_t z=0;z<gas.size();z++) {

                if(current_gas>=cost[next_index(gas,next_index_int-1)] && current_gas>low_gas[next_index(gas,next_index_int-1)]) {
                    low_gas[next_index(gas,next_index_int-1)]=current_gas;

                    current_gas-=cost[next_index(gas,next_index_int-1)];
                    current_gas+=gas[next_index(gas,next_index_int)];
                    next_index_int=next_index(gas,next_index_int+1);
                }
                else {
                    can_go=false;
                    low_gas[next_index(gas,next_index_int-1)]=current_gas;

                    break;
                }
            }
            if(can_go) {

                return (int)i;
            }

        }

        return -1;
    }
};

int main(void) {

    Solution s;

    vector<int>gas_1={1,2,3,4,5};
    vector<int>cost_1={3,4,5,1,2};
    assert(s.canCompleteCircuit(gas_1,cost_1)==3);

    vector<int>gas_2={2,3,4};
    vector<int>cost_2={3,4,3};
    assert(s.canCompleteCircuit(gas_2,cost_2)==-1);
}
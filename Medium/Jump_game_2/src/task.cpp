#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cassert>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:

    int simple_solution(const vector<int> & nums) {

        int radius=0;
         int index=0;

         int jumps=0;
         while(radius<(int)nums.size()-1) {
             int farthest=0;
             for(int z=index;z<=radius;z++) {
                 farthest=max(farthest,z+nums[z]);
             }
             index=radius+1;
             radius=farthest;
             jumps++;

         }
         return jumps;

     }
    int jump(vector<int>& nums) {
        return simple_solution(nums);


    }
};

int main(void) {
    Solution sol;
    vector<int>jump_1={2,3,1,1,4};
    assert(sol.jump(jump_1)==2);

    vector<int>jump_2={2,3,0,1,4};
    assert(sol.jump(jump_2)==2);

    vector<int>jump_3={4,1,1,1,4};
    assert(sol.jump(jump_3)==1);

    vector<int>jump_4={1,2,3};
    assert(sol.jump(jump_4)==2);


    return EXIT_SUCCESS;
}
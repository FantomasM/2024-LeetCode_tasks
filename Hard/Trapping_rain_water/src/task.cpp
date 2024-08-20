#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
            int left_index=0;
            int right_index=(int)height.size()-1;
            int left_max=height[left_index];
            int right_max=height[right_index];
            int water=0;
        while(left_index<right_index) {
            if(left_max<right_max) {
                left_index++;
                left_max=std::max(left_max,height[left_index]);
                water+=left_max-height[left_index];
            }
            else {
                right_index--;
                right_max=std::max(right_max,height[right_index]);
                water+=right_max-height[right_index];
            }
        }
        return water;
    }
};

int main(void) {

    Solution s;
    vector<int> height_1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    assert(6 == s.trap(height_1));

    vector<int> height_2 = {4,2,0,3,2,5};
    assert(9 == s.trap(height_2));

    return EXIT_SUCCESS;
}
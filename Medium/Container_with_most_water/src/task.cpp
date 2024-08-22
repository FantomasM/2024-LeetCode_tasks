#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area=0;
        while (left < right) {
            max_area=std::max(max_area, (right-left)*(std::min(height[left], height[right])));
            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return max_area;
    }
};

int main() {

    Solution s;

    vector<int> height = {1,8,6,2,5,4,8,3,7};
    assert(s.maxArea(height) == 49);

    height={1,1};
    assert(s.maxArea(height) == 1);



    return EXIT_SUCCESS;
}
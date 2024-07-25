#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int sol_with_hashmap(vector<int> &nums) {
        std::unordered_map<int,int> freq;
        int most_frequent=nums[0];
        int frequency=1;
        freq[most_frequent]=1;
        for(size_t i=1;i<nums.size();i++) {
            freq[nums[i]]++;
            if(nums[i]!=frequency) {
                if(freq[nums[i]]>most_frequent) {
                    most_frequent=nums[i];
                    frequency=freq[nums[i]];
                }
            }
        }
        return most_frequent;
    }

    int majorityElement(vector<int>& nums) {
        int res=nums[0];
        int major=0;
        for (size_t i=0;i<nums.size();i++) {
            if(nums[i]==res) {
                major++;
            }
            else {
                major--;
                if(major==0) {
                    res=nums[i];
                    major++;
                }
            }
        }
        return res;
    }
};





int main(void) {
    Solution sol;
    vector<int> nums_1={3,2,3};
    assert(sol.majorityElement(nums_1)==3);

    vector<int>nums_2={2,2,1,1,1,2,2};
    assert(sol.majorityElement(nums_2)==2);
}
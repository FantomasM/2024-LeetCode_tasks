#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count_of_unique_nums=0;
        int current_number;
        int occurences=1;
        int position=1;
        if(!nums.empty()) {
            count_of_unique_nums=1;
            current_number=nums[0];
        }
        for(size_t i=1;i<nums.size();i++) {
            if(nums[i]==current_number) {
                occurences++;
                if(occurences>2) {
                    continue;
                }
                else {
                    count_of_unique_nums++;
                    nums[position++]=nums[i];
                }
            }
            else {
                count_of_unique_nums++;
                current_number=nums[i];
                occurences=1;
                nums[position++]=nums[i];
            }
        }
        return count_of_unique_nums;
    }
};

int main(void) {
    Solution sol;
    vector<int> nums_1={1,1,1,2,2,3};
    int res=sol.removeDuplicates(nums_1);
    vector<int> result_1={1,1,2,2,3};
    assert(res==5 && nums_1.size()>=5);
    for(int i=0;i<5;i++) {
        assert(result_1[i]==nums_1[i]);
    }

    vector<int> nums_2={0,0,1,1,1,1,2,3,3};
    res=sol.removeDuplicates(nums_2);
    vector<int> result_2={0,0,1,1,2,3,3};
    assert(res==7 && nums_2.size()>=7);
    for(int i=0;i<7;i++) {
        assert(nums_2[i]==result_2[i]);
    }

}
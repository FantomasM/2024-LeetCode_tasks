#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <algorithm>
#include <strings.h>

using namespace std;

class Solution {
public:
    int find_index_of_number_in_sorted_array(vector<int> & nums, bool & found,int number_to_find) {
        auto element=std::lower_bound(nums.begin(),nums.end(),number_to_find);
        //No such number
        if(element==nums.end() || *element!=number_to_find) {
            found=false;
            return -1;
        }
        found=true;
        return static_cast<int>(std::distance(nums.begin(),element));

    }
    std::vector<int> indexes_before_changes(int first_index,int second_index,vector<int> & nums,vector<int> & nums_before) {
        std::vector<int> solution;
        solution.resize(2);
        //Finding first number
        for(size_t i=0;i<nums.size();i++) {
            if(nums[first_index]==nums_before[i]) {
                solution[0]=static_cast<int>(i);
                break;
            }
        }
        //Finding second number
        for(size_t i=0;i<nums.size();i++) {
            if(nums[second_index]==nums_before[i] && static_cast<int>(i)!=solution[0]) {
                solution[1]=static_cast<int>(i);
                break;
            }
        }
        return solution;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums_before=nums;
        sort(nums.begin(),nums.end());
        for(size_t i=0;i<nums.size();i++) {
            int num_to_add=target-nums[i];

            if(num_to_add!=nums[i]) {
                bool found;
                int index=find_index_of_number_in_sorted_array(nums,found,num_to_add);
                if(!found) {
                    continue;
                }
                else {

                    return indexes_before_changes(static_cast<int>(i),index,nums,nums_before);
                }
            }
            else {
                bool found;
                int index=find_index_of_number_in_sorted_array(nums,found,num_to_add);
                index++;
                if(index >=0 && index < static_cast<int>(nums.size()) && nums[index]==num_to_add) {

                    return indexes_before_changes(static_cast<int>(i),index,nums,nums_before);
                }
                else {
                    continue;
                }
            }

        }
        return vector<int>{};
   }
};


int main(void) {
    Solution sol;
    vector<int> test_first={2,7,11,15};
    int target=9;

    vector<int> result;
    result=sol.twoSum(test_first,target);

    assert(result.size()==2 && result[0]==0 && result[1]==1);
    result.clear();

    vector<int> test_second={3,2,4};
    target=6;

    result=sol.twoSum(test_second,target);
    assert(result.size()==2 && result[0]==1 && result[1]==2);
    result.clear();

    vector<int> test_third={3,3};
    result=sol.twoSum(test_third,target);
    assert(result.size()==2 && result[0]==0 && result[1]==1);


}
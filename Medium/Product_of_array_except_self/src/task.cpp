#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int extract_from_left_vector(const vector<int> & left_vector,int index) {
        if(index==0) {
            return 1;

        }
        else {
            return left_vector[index];
        }
    }
    int extract_from_right_vector(const vector<int> & right_vector,int index) {
        if(index==(int)right_vector.size()-1) {
            return 1;
        }
        else {
            return right_vector[index];
        }
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result_vector(nums.size(), 0);
        vector<int> left_vector(nums.size(), 0);
        vector<int> right_vector(nums.size(), 0);

        for (int i = 0; i < (int)nums.size(); i++) {
            if(i==0) {
                left_vector[i]=nums[i];
            }
            else if(i==1) {
                left_vector[i]=nums[0];
            }
            else {
                left_vector[i]=left_vector[i-1]*nums[i-1];
            }

        }



        for (int i = (int)nums.size()-1; i>=0; i--) {
            if(i==(int)nums.size()-1) {
                right_vector[i]=nums[i];
            }
            else if(i==(int)nums.size()-2) {
                right_vector[i]=nums[nums.size()-1];
            }
            else {
                right_vector[i]=right_vector[i+1]*nums[i+1];
            }

        }



        for(size_t i=0;i<nums.size();i++) {
            if(i==0) {
                result_vector[i]=right_vector[i];
            }
            else if(i==nums.size()-1) {
                result_vector[i]=left_vector[i];
            }
            else {
                result_vector[i]=(left_vector[i-1]*extract_from_left_vector(nums,(int)i-1))*(right_vector[i+1]*extract_from_right_vector(nums,(int)i+1));
            }

        }


        return result_vector;
    }
};

int main(void) {
    Solution s;

    vector<int> nums_1={1,2,3,4};
    vector<int> result_1={24,12,8,6};

   assert(s.productExceptSelf(nums_1)==result_1);

    vector<int> nums_2={-1,1,0,-3,3};
    vector<int>result_2={0,0,9,0,0};
  
    assert(s.productExceptSelf(nums_2)==result_2);


    return EXIT_SUCCESS;
}
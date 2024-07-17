#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>
#include <cassert>

using namespace std;

bool AreSame(double a, double b)
{
    std::cout << "comparsion of " <<a <<" and " <<b <<std::endl;
    return fabs(a - b) < DBL_EPSILON;
}


class Solution {
public:
    vector<int> Merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result_vector;
        result_vector.resize(nums1.size()+nums2.size());
        size_t first_ptr=0;
        size_t second_ptr=0;
        for(size_t i=0;i<nums1.size()+nums2.size();i++) {
            if(first_ptr<nums1.size() && second_ptr<nums2.size()) {
                if(nums1[first_ptr]<=nums2[second_ptr]) {
                    result_vector[i]=nums1[first_ptr];
                    first_ptr++;
                }
                else {
                    result_vector[i]=nums2[second_ptr];
                    second_ptr++;
                }
            }
            else if(first_ptr>=nums1.size() && second_ptr<nums2.size()) {
                result_vector[i]=nums2[second_ptr];
                second_ptr++;
            }
            else if(first_ptr<nums1.size() && second_ptr>=nums2.size()) {
                result_vector[i]=nums1[first_ptr];
                first_ptr++;
            }
        }
        return result_vector;
    }
    double brute_force_merging(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result_vector=Merge(nums1,nums2);
        if(result_vector.size()%2==1) {
            return result_vector[(nums1.size()+nums2.size())/2];
        }
        else {
            return (result_vector[(nums1.size()+nums2.size())/2]+result_vector[(nums1.size()+nums2.size())/2-1])/2.0;
        }

    }
    double simple_particular_merging(vector<int>& nums1, vector<int>& nums2) {
        if((nums1.size()+nums2.size())%2==1) {
            size_t first_ptr=0;
            size_t second_ptr=0;
            double number=0;
            for(size_t i=0;i<nums1.size()+nums2.size();i++) {
                if(first_ptr<nums1.size() && second_ptr<nums2.size()) {
                    if(nums1[first_ptr]<=nums2[second_ptr]) {
                        number=nums1[first_ptr];
                        first_ptr++;
                    }
                    else {
                        number=nums2[second_ptr];
                        second_ptr++;
                    }
                }
                else if(first_ptr>=nums1.size() && second_ptr<nums2.size()) {
                    number=nums2[second_ptr];
                    second_ptr++;
                }
                else if(first_ptr<nums1.size() && second_ptr>=nums2.size()) {
                    number=nums1[first_ptr];
                    first_ptr++;
                }
                if(i==(nums1.size()+nums2.size())/2) {
                    return number;
                }
            }
        }
        else {
            size_t first_ptr=0;
            size_t second_ptr=0;
            double number=0;
            double prev_number=0;
            for(size_t i=0;i<nums1.size()+nums2.size();i++) {
                if(first_ptr<nums1.size() && second_ptr<nums2.size()) {
                    if(nums1[first_ptr]<=nums2[second_ptr]) {
                        number=nums1[first_ptr];
                        first_ptr++;
                    }
                    else {
                        number=nums2[second_ptr];
                        second_ptr++;
                    }
                }
                else if(first_ptr>=nums1.size() && second_ptr<nums2.size()) {
                    number=nums2[second_ptr];
                    second_ptr++;
                }
                else if(first_ptr<nums1.size() && second_ptr>=nums2.size()) {
                    number=nums1[first_ptr];
                    first_ptr++;
                }
                if(i==(nums1.size()+nums2.size())/2) {
                    return (number+prev_number)/2.0;
                }

                prev_number=number;
            }
        }
        return 0.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return simple_particular_merging(nums1,nums2);

    }
};


int main(void) {
    Solution sol;
    vector<int> first_1={1,3};
    vector<int> first_2={2};
    assert(AreSame(sol.findMedianSortedArrays(first_1,first_2),2.0));

    vector<int> second_1={1,2};
    vector<int> second_2={3,4};
    assert(AreSame(sol.findMedianSortedArrays(second_1,second_2),2.5));

    return EXIT_SUCCESS;
}
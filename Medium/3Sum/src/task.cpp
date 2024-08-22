#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <tuple>

using namespace std;

class Solution {
public:
    void print_vector_of_vectors(const vector<vector<int>> & v) {
        cout << "Vector of vectors" << endl;
        for (int i = 0; i < (int)v.size(); i++) {
            std::cout <<i<<". vector" <<std::endl;
            for (int j = 0; j < (int)v[i].size(); j++) {
                std::cout <<v[i][j]<<" ";
            }
            std::cout << std::endl;
        }
    }
    void print_vector(const vector<int> & v) {
        cout << "Vector of ints" << std::endl;
        for (int i = 0; i < (int)v.size(); i++) {
            std::cout <<v[i] <<" ";
        }
        std::cout <<std::endl;
    }
    std::vector<int> delete_duplicates(vector<int> & v) {
        int count=0;
        if(v.empty()) {
            return std::vector<int>();
        }
        std::vector<int> result;
        int number=v[0];
        for(int i=0;i<(int)v.size();i++) {
            if(v[i]==number) {
                count++;
                if(count<=3) {
                    result.push_back(number);
                }
            }
            else {
                number=v[i];
                count=1;
                result.push_back(number);
            }
        }
        return result;
    }
    vector<vector<int>> threeSum(vector<int>& numbers) {
        std::set<int> visited;
        std::set<tuple<int, int, int>> sums;
        std::vector<std::vector<int>> result;
        std::vector<int> nums_dup=numbers;
        sort(nums_dup.begin(), nums_dup.end());
        std::vector<int> nums=delete_duplicates(nums_dup);

       // print_vector(nums);
        for(int i = 0; i < (int)nums.size(); i++) {


            int current_sum=nums[i];
            for(int z=0; z < (int)nums.size(); z++) {
                if(z==i) {
                    continue;
                }
                current_sum=nums[i]+nums[z];



                    auto it=std::lower_bound(nums.begin(), nums.end(), 0-current_sum);
                    if(it==nums.end() || (*it)+current_sum!=0) {

                        continue;
                    }

                    int distance=(int)std::distance(nums.begin(), it);
                if( distance==i || distance==z ) {
                    distance++;
                    if(distance==i || distance==z || distance>=(int)nums.size()) {
                        distance++;
                        if(distance==i || distance==z || distance>=(int)nums.size()) {
                            continue;
                        }
                        else {
                            if(current_sum+nums[distance]!=0) {
                                continue;
                            }
                        }
                    }
                    else {
                      if(current_sum+nums[distance]!=0) {
                          continue;
                      }
                    }

                }
                    std::vector<int>three={nums[z],nums[distance],nums[i]};
                    sort(three.begin(), three.end());
                    int first=three[0];
                    int third=three[2];
                    int second=three[1];

                    if(sums.find(std::make_tuple(first,second,third))!=sums.end()) {
                        continue;
                    }
                    else{

                        result.push_back({first,second,third});
                        sums.insert(std::make_tuple(first,second,third));



                    }


            }
        }
        //print_vector_of_vectors(result);
        sort(result.begin(),result.end());
        return result;
    }
};


int main() {
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = {{-1,-1,2},{-1,0,1}};
    assert(s.threeSum(nums) == result);

    nums={0,1,1};
    result={};
    assert(s.threeSum(nums) == result);

    nums={0,0,0};
    result={{0,0,0}};
    assert(s.threeSum(nums) == result);

    nums={11,4,9,-7,-7,4,-6,13,12,-1,-5,-15,-2,-4,7,14,14,13,-2,-11,-9,-3,-15,6,-4,14,-7,-15,2,2,7,-10,13,-6,-1,14,5,8,12,3,14,-15,3,-10,-4,-12,-11,-4,-14,-6,-8,14,6,-15,5,10,14,13,10,-6,-8,-6,-1,-9,3,13,-10,-6,-1,9,4,-2,9,14,3,-9,-13,-1,-6,10,8,-7,9,-8,-7,-1,9,-15,-3,4,-6,5,13,8,3,-6,-1,8,-5,13,2,14,-12,-11,13,-1,-13,8,13,-4,3,-1,-4,-2,-2,5,12,-8,5,-13,3,14};
    result={{-15,2,13},{-15,3,12},{-15,4,11},{-15,5,10},{-15,6,9},{-15,7,8},{-14,2,12},{-14,3,11},{-14,4,10},{-14,5,9},{-14,6,8},{-14,7,7},{-13,-1,14},{-13,2,11},{-13,3,10},{-13,4,9},{-13,5,8},{-13,6,7},{-12,-2,14},{-12,-1,13},{-12,2,10},{-12,3,9},{-12,4,8},{-12,5,7},{-12,6,6},{-11,-3,14},{-11,-2,13},{-11,-1,12},{-11,2,9},{-11,3,8},{-11,4,7},{-11,5,6},{-10,-4,14},{-10,-3,13},{-10,-2,12},{-10,-1,11},{-10,2,8},{-10,3,7},{-10,4,6},{-10,5,5},{-9,-5,14},{-9,-4,13},{-9,-3,12},{-9,-2,11},{-9,-1,10},{-9,2,7},{-9,3,6},{-9,4,5},{-8,-6,14},{-8,-5,13},{-8,-4,12},{-8,-3,11},{-8,-2,10},{-8,-1,9},{-8,2,6},{-8,3,5},{-8,4,4},{-7,-7,14},{-7,-6,13},{-7,-5,12},{-7,-4,11},{-7,-3,10},{-7,-2,9},{-7,-1,8},{-7,2,5},{-7,3,4},{-6,-6,12},{-6,-5,11},{-6,-4,10},{-6,-3,9},{-6,-2,8},{-6,-1,7},{-6,2,4},{-6,3,3},{-5,-5,10},{-5,-4,9},{-5,-3,8},{-5,-2,7},{-5,-1,6},{-5,2,3},{-4,-4,8},{-4,-3,7},{-4,-2,6},{-4,-1,5},{-4,2,2},{-3,-3,6},{-3,-2,5},{-3,-1,4},{-2,-2,4},{-2,-1,3},{-1,-1,2}};
    assert(s.threeSum(nums) == result);
    return EXIT_SUCCESS;
}
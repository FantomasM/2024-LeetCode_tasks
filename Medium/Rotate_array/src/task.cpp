#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
                                            //true=left, false=right
    void rotate_one_time(vector<int> & nums,bool direction) {
        int stored_element;
        //Right direction
        if(!direction) {
            stored_element=nums[0];
            nums[0]=nums[nums.size()-1];
            for(size_t i=1;i<nums.size();i++) {
                int tmp=nums[i];
                nums[i]=stored_element;
                stored_element=tmp;

            }
        }
        //Left direction
        else {
            if(nums.size()>=2) {
                stored_element=nums[nums.size()-1];
                nums[nums.size()-1]=nums[0];
                for(int i=(int)nums.size()-2;i>=0;i--) {
                    int tmp=nums[i];
                    nums[i]=stored_element;
                    stored_element=tmp;
                }
            }
        }

    }
    int gcd(int a, int b) {
        if(a==b) {
            return a;

        }
        if(b>a) {
            return gcd(b,a);
        }
        else {
            if(a%b==0) {
                return b;
            }
            else {
                return gcd(a%b,b);
            }
        }
    }
    int only_pos_modulo(int k, size_t modulo) {
        if(k%modulo<0) {
            return (int)modulo+k;
        }
        return k%(int)modulo;
    }
    void faster_solution(vector<int> & nums,int & rot) {
        int stored_element=nums[0];
        int index=rot;
        int gcd_res=gcd((int)nums.size(),rot);
        if(gcd_res!=1) {
            for(int z=0;z<gcd_res;z++) {
                stored_element=nums[z];
                index=rot+z;
                for(size_t i=0;i<nums.size()/gcd_res;i++) {
                    int tmp=nums[index];
                    nums[index]=stored_element;
                    stored_element=tmp;


                    index=only_pos_modulo(index+rot,nums.size());
                }

            }

        }
        else {
            for(size_t i=0;i<nums.size();i++) {
                int tmp=nums[index];
                nums[index]=stored_element;
                stored_element=tmp;


                index=only_pos_modulo(index+rot,nums.size());
            }
        }
    }
    void rotate(vector<int>& nums, int k) {
        if(k==0) {
            return;
        }
        int rot=k%(int)nums.size();
        if(nums.size()!=1 && rot!=0) {
            faster_solution(nums,rot);
            return;
        }
        else {
            return;
        }



    }
    void print_vector(vector<int> & nums) {
        for(int num : nums) {
            std::cout <<" " <<num;
        }
        std::cout <<std::endl;
    }
};

int main(void) {

    Solution sol;

    vector<int> test_1={1,2,3,4,5,6,7};
    int k=4;
    vector<int> result_1={4,5,6,7,1,2,3};
    sol.rotate(test_1,k);
    sol.print_vector(test_1);
    assert(test_1.size()==7);
    for(int i=0;i<7;i++) {
        assert(test_1[i]==result_1[i]);
    }

    vector<int> test_4={1,2,3,4,5,6};
    k=4;
    sol.rotate(test_4,k);
    sol.print_vector(test_4);

    k=2;
    vector<int>test_2={-1,-100,3,99};
    vector<int>result_2={3,99,-1,-100};
    sol.rotate(test_2,k);
    sol.print_vector(test_2);
    assert(test_2.size()==4);
    for(int i=0;i<4;i++) {
        assert(test_2[i]==result_2[i]);
    }

    vector<int> test_3={1,2};
    sol.rotate(test_3,2);
    return EXIT_SUCCESS;
}
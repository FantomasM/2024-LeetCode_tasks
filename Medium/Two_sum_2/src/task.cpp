#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
            for(int i=0;i<(int)numbers.size();i++) {
                int to_find=target - numbers[i];
                auto element=lower_bound(numbers.begin(),numbers.end(),to_find);

                if(element==numbers.end() || *element!=to_find) {
                    continue;
                }
                else {
                    std::vector<int> result;
                    result.push_back(i+1);
                    int index=(int)std::distance(numbers.begin(),element);
                    if(index==i) {
                        index++;
                        if(numbers[index]!=to_find) {
                            continue;
                        }
                    }
                    result.push_back(index+1);
                    return result;
                }
            }
        return vector<int>();
    }
};

int main(void) {

    Solution s;

    vector<int> v = {2,7,11,15};
    int target=9;
    vector<int> result = {1,2};
    assert(s.twoSum(v,target)==result);

    v={2,3,4};
    target=6;
    result={1,3};
    assert(s.twoSum(v,target)==result);

    v={-1,0};
    target=-1;
    result={1,2};
    assert(s.twoSum(v,target)==result);

    v={0,0,3,4};
    target=0;
    result={1,2};
    assert(s.twoSum(v,target)==result);



    return EXIT_SUCCESS;
}


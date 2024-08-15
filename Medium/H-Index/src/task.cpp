#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    void print_vector(const vector<int> & citations) {
        std::cout <<" vector :";
        for(auto element : citations) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(),std::greater<int>());
       
        int res=0;
        int index=citations.size()-1;
        for(size_t i=citations.size();i>=1;i--) {
            if(citations[index--]>=(int)i) {
                res=i;

                return res;
            }
        }

        return res;
    };
};
int main(void) {
    Solution sol;
    vector<int>citations_1={3,0,6,1,5};
    assert(sol.hIndex(citations_1)==3);

    vector<int>citations_2={1,3,1};
    assert(sol.hIndex(citations_2)==1);

    return EXIT_SUCCESS;
}
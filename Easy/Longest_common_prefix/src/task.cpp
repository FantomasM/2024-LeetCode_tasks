#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix="";
        sort(strs.begin(),strs.end());
        int n = (int)strs.size();
        string first=strs[0],last=strs[n-1];
        for(int i=0;i<min((int)first.size(),(int)last.size());i++) {
            if(first[i]!=last[i]) {
                return prefix;
            }
            prefix+=first[i];
        }
        return prefix;
    }
};

int main(void) {
        Solution s;
        vector<string> strs = {"flower","flow","flight"};
        assert(s.longestCommonPrefix(strs)=="fl");

        vector<string> strs_1={"dog","racecar","car"};
        assert(s.longestCommonPrefix(strs_1)=="");



    return EXIT_SUCCESS;
}
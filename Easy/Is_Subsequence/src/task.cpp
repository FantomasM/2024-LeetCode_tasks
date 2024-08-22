#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool try_subsequence(const string & to_find, const string & to_look,int starting_index) {
        int to_find_index=1;
        if(to_find_index==(int)to_find.size()) {
            return true;
        }
        for(int i=starting_index+1;i<(int)to_look.size();i++) {
            if(to_find[to_find_index]==to_look[i]) {
                to_find_index++;
                if(to_find_index==(int)to_find.size()) {
                    return true;
                }
            }
        }
        return false;

    }
    bool isSubsequence(string s, string t) {
        if(s.size()<1) {
            return true;
        }
        for(size_t i=0;i<t.size();i++) {
            if(s[0]==t[i]) {
                if(try_subsequence(s,t,(int)i)) {
                    return true;
                }
            }

        }
        return false;
    }
};

int main(void) {

    Solution s;

    assert(s.isSubsequence("abc","ahbgdc"));

    assert(!s.isSubsequence("axc","ahbgdc"));



    return EXIT_SUCCESS;
}
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
            int needle_ptr_index=0;
        int start_result_index=-1;
        for (int i = 0; i < (int)haystack.size(); i++) {
            if(haystack[i]==needle[needle_ptr_index]) {
                //New comparsion started
                if(start_result_index==-1) {
                    start_result_index=i;
                }

                needle_ptr_index++;
                //Full needle is found
                if(needle_ptr_index==(int)needle.size()) {
                    return start_result_index;
                }
            }
            else {
                if(start_result_index==-1) {
                    needle_ptr_index=0;
                    continue;
                }
                else {
                    i=start_result_index;
                    start_result_index=-1;
                    needle_ptr_index=0;
                }
            }
        }
        return -1;
    }
};

int main() {

    Solution s;

    assert(s.strStr("sadbutsad", "sad") == 0);
    assert(s.strStr("leetcode", "leeto") == -1);
    assert(s.strStr("butsad", "sad") == 3);
    assert(s.strStr("sad", "sad") == 0);
    assert(s.strStr("mississippi", "issip") == 4);


    return EXIT_SUCCESS;
}
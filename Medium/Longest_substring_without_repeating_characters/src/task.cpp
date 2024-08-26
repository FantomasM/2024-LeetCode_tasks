#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
public:
    void left_part_fix(const string & s, int & left_index, int & right_index, int & current_length, std::unordered_map<char, int> & occurrences){
        for(int i=left_index;i<right_index;i++) {
            occurrences[s[i]]--;
            left_index++;
            current_length--;
            if(occurrences[s[right_index]]==1) {
                return;
            }
        }
    }
    int lengthOfLongestSubstring(const string & s) {
        if(s.empty()) {
            return 0;
        }
        int left_index=0;
        int right_index=0;
        int max_length=1;
        int current_length=1;
        std::unordered_map<char,int> map_chars;
        map_chars.insert({s[0],1});
        for(int i=1;i<(int)s.size();i++) {
            if(map_chars.find(s[i])==map_chars.end() || map_chars[s[i]]==0) {
                map_chars[s[i]]=1;
                right_index++;
                current_length++;
                if(current_length>max_length) {
                    max_length=current_length;
                }
            }
            else {
                map_chars[s[i]]++;
                right_index++;
                current_length++;
                left_part_fix(s, left_index, right_index, current_length,map_chars);
                if(current_length>max_length) {
                    max_length=current_length;
                }
            }
        }
        return max_length;
    }
};

int main() {

    Solution s;

    assert(s.lengthOfLongestSubstring("abcabcbb") == 3);

    assert(s.lengthOfLongestSubstring("bbbbb") == 1);

    assert(s.lengthOfLongestSubstring("pwwkew") == 3);




    return EXIT_SUCCESS;
}
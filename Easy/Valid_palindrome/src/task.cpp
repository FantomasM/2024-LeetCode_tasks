#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    string convert_to_canonical(const string & s) {
        string result;
        for (const auto &c : s) {
            char tmp;
            if(isalnum(c)) {
                tmp=(char)tolower(c);
                result.push_back(tmp);
            }
        }
        return result;
    }
    bool isPalindrome(const string & s) {
        string canonical = convert_to_canonical(s);
        //Special case, empty string is palindrome
        if(canonical.size()==0) {
            return true;
        }
        int first_index=0;
        int last_index=(int)canonical.length()-1;
        while (first_index<=last_index) {
            if(canonical[first_index]!=canonical[last_index]) {
                return false;
            }
            first_index++;
            last_index--;
        }
        return true;
    }
};

int main() {
    Solution s;

    assert(s.isPalindrome("A man, a plan, a canal: Panama"));

    assert(!s.isPalindrome("race a car"));

    assert(s.isPalindrome(" "));


    return EXIT_SUCCESS;
}
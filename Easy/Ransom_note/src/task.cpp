#include <iostream>
#include <vector>
#include <array>
#include <cassert>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        std::array<int,26> letterscount={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(auto letter : magazine) {
            if((int)letter<97 || (int)letter>122) {
                throw std::invalid_argument("canConstruct: invalid character");
            }
            letterscount[(int)letter-97]++;

        }
        for(auto letter : ransomNote) {
            if(letterscount[(int)letter-97]<=0) {
                return false;
            }
            else {
                letterscount[(int)letter-97]--;

            }
        }
        return true;
    }
};

int main() {
    Solution s;

    assert(s.canConstruct("a", "b")==false);
    assert(s.canConstruct("b", "c")==false);
    assert(s.canConstruct("aa", "ab")==false);
    assert(s.canConstruct("aa", "aab")==true);



    return EXIT_SUCCESS;
}
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cassert>
#include <ctype.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string tmp;
        for(auto el : s) {
            if(isalpha(el) ||el=='.' ||el==',') {
                tmp.push_back(el);
            }
        }
        std::cout <<tmp <<std::endl;
        return tmp;
    }
};

int main(void) {
    Solution sol;
    string first="PAYPALISHIRING";
    assert(sol.convert(first,3)=="PAHNAPLSIIGYIR");

    string second="PAYPALISHIRING";
    assert(sol.convert(second,4)=="PINALSIGYAHRPI");

}
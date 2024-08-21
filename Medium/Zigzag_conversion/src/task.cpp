#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    int row_distribution(int index, int num_rows) {
        int possibilities = num_rows+num_rows-2;
        int new_index=index%possibilities;
        if(new_index<num_rows) {
            return new_index;
        }
        else {
            return (new_index-possibilities)*-1;
        }
    }
    string convert(const string & s, int numRows) {
        if(numRows==1) {
            return s;
        }
        std::vector<string> tmp(numRows);
        for(int i = 0; i < (int)s.size(); i++) {
            tmp[row_distribution(i, numRows)].push_back(s[i]);
        }
        string result = "";
        for(int i = 0; i < (int)tmp.size(); i++) {
            result += tmp[i];
        }
        return result;

    }
};

int main(void) {
    Solution sol;
    string first="PAYPALISHIRING";
    assert(sol.row_distribution(0,4)==0);
    assert(sol.row_distribution(1,4)==1);
    assert(sol.row_distribution(2,4)==2);
    assert(sol.row_distribution(3,4)==3);
    assert(sol.row_distribution(4,4)==2);
    assert(sol.row_distribution(5,4)==1);

    assert(sol.row_distribution(0,3)==0);
    assert(sol.row_distribution(1,3)==1);
    assert(sol.row_distribution(2,3)==2);
    assert(sol.row_distribution(3,3)==1);

    assert(sol.convert(first,3)=="PAHNAPLSIIGYIR");

    string second="PAYPALISHIRING";
    assert(sol.convert(second,4)=="PINALSIGYAHRPI");

}
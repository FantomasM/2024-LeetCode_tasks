#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int,int> tmp;
        //Lines
        for(int i=0;i<9;i++) {
            for(int z=0;z<9;z++) {
                if(board[i][z]=='.') {
                    continue;
                }
                if(tmp.find(board[i][z]) != tmp.end()) {
                    return false;
                }
                else{tmp[board[i][z]] = 1;}
            }
            tmp.clear();
        }
        //Rows
        for(int i=0;i<9;i++) {
            for(int z=0;z<9;z++) {
                if(board[z][i]=='.') {
                    continue;
                }
                if(tmp.find(board[z][i]) != tmp.end()) {
                    return false;
                }
                else{tmp[board[z][i]] = 1;}
            }
            tmp.clear();
        }
        //Blocks
        auto delim=(size_t)sqrt(9);
        for (size_t row_start = 0; row_start < 9; row_start += delim) { //Going through blocks
            for (size_t col_start = 0; col_start < 9; col_start += delim) {

                for (size_t i = row_start; i < row_start + delim; i++) {
                    for (size_t j = col_start; j < col_start + delim; j++) {

                        if(board[i][j]=='.') {
                            continue;
                        }
                        if(tmp.find(board[i][j]) != tmp.end()) {
                            return false;
                        }
                        else {
                            tmp.insert({board[i][j],1});
                        }


                    }
                }
                tmp.clear();
              
            }
        }
        return true;
    }
};

int main(void){

    Solution s;
    std::vector<vector<char>> board={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    assert(s.isValidSudoku(board));

    board={{'8','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}};

    assert(!s.isValidSudoku(board));



    return EXIT_SUCCESS;
}
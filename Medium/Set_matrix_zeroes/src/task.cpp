#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    void print_matrix(const vector<vector<int>> & matrix) {
        std::cout <<" Matrix: " << std::endl;
        for (int i = 0; i < (int)matrix.size(); i++) {
            for (int j = 0; j < (int)matrix[0].size(); j++) {
                cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }

    }
                                                //row =true , col=false
    void fill_zeros(vector<vector<int>> & matrix, int index, bool row_col ) {
        if(row_col) {
            for(int i=0;i<(int)matrix.size();i++) {
                matrix[i][index]=0;
            }
        }
        else {
            if(matrix[index].begin()==matrix[index].end()) {
                matrix[index][0]=0;
            }
            else {
                fill(matrix[index].begin(), matrix[index].end(), 0);
            }
            }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int top_left_corner=matrix[matrix.size()-1][0], bottom_right_corner=matrix[0][matrix[0].size()-1],top_right_corner=matrix[matrix.size()-1][matrix[0].size()-1],bottom_left_corner=matrix[0][0];
        bool first_row=false, last_row=false, first_col=false, last_col=false;
        if(top_left_corner==0) {
            first_row=true;
            first_col=true;
        }
        if(bottom_right_corner==0) {
            last_row=true;
            last_col=true;
        }
        if(top_right_corner==0) {
            last_row=true;
            first_col=true;
        }
        if(bottom_left_corner==0) {
            first_row=true;
            last_col=true;
        }
        for(int i=0;i<(int)matrix.size();i++) {
            for(int j=0;j<(int)matrix[0].size();j++) {
                if((i==0 && j==0) || (i==(int)matrix.size()-1 && j==0) || (i==0 && j==(int)matrix[0].size()-1) || (i==(int)matrix.size()-1 && j==(int)matrix[0].size()-1)) {
                    continue;
                }
                else {
                    if(matrix[i][j] == 0) {
                        if(i==0){
                         last_col=true;
                        }
                        else if(i==(int)matrix.size()-1){
                        first_col=true;
                        }
                        else {
                            matrix[i][0]=0;
                        }
                        if(j==0) {
                           first_row=true;
                        }
                        else if(j==(int)matrix[0].size()-1) {
                            last_row=true;
                        }
                        else {
                            matrix[0][j]=0;
                        }
                    }
                }
            }
        }
        for(int i=1;i<(int)matrix.size()-1;i++) {
            if(matrix[i][0]==0) {
                fill_zeros(matrix, i, false);
            }
        }
        for(int i=1;i<(int)matrix[0].size()-1;i++) {
            if(matrix[0][i]==0) {
                fill_zeros(matrix, i, true);
            }
        }
        if(first_row) {
            fill_zeros(matrix, 0, true);
        }
        if(last_col) {
            fill_zeros(matrix,0,false);
        }
        if(first_col) {
            fill_zeros(matrix, (int)matrix.size()-1, false);
        }
        if(last_row) {
            fill_zeros(matrix, (int)matrix[0].size()-1, true);
        }


        print_matrix(matrix);
    }
};


int main() {
    Solution s;

    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> result = {{1,0,1},{0,0,0},{1,0,1}};

    s.setZeroes(matrix);
    assert(matrix == result);

    matrix={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    result={{0,0,0,0},{0,4,5,0},{0,3,1,0}};

    s.setZeroes(matrix);

    assert(matrix == result);

    matrix={{1,0,3}};
    result={{0,0,0}};

    s.setZeroes(matrix);

    assert(matrix == result);

    matrix={{1},{0},{3}};
    result={{0},{0},{0}};

    s.setZeroes(matrix);

    assert(matrix == result);

    matrix={{9,-6,-1,-2,5},{-1,3,2147483647,-4,0},{-3,-4,0,4,-2147483648}};
    result={{9,-6,0,-2,0},{0,0,0,0,0},{0,0,0,0,0}};

    s.setZeroes(matrix);

    assert(matrix == result);
    return EXIT_SUCCESS;
}
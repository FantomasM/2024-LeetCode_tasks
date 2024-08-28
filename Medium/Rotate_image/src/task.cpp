#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    void print_vector(const vector<vector<int>> & v) {
        std::cout <<" result: " <<std::endl;
        for(int i=0;i<(int)v.size();i++) {
            for(int j=0;j<(int)v[i].size();j++) {
                std::cout << v[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    std::pair<int,int> next_coordinates(const std::pair<int,int> & coordinates, int down,int top,int left, int right, int n) {
        std::pair<int,int> result;
        if(coordinates.first==top ) {
             if(coordinates.second==left) {
                result.first=down;
                result.second=n-coordinates.first;
            }
            else {
                result.second=left;
                result.first=coordinates.second;
            }
        }
        else if(coordinates.first==down) {
            if(coordinates.second==right) {
                result.first=top;
                result.second=right;
            }
            else {
                result.first=coordinates.second;
                result.second=right;
            }
        }
        else if(coordinates.second==left ) {
            if(coordinates.first==down) {
                result.second=n-coordinates.first;
                result.first=down;
            }
            else {
                result.first=down;
                result.second=n-coordinates.first;
            }
        }
        else if(coordinates.second==right ) {
            if(coordinates.first==top) {
                result.first=top;
                result.second=left;
            }
            else {
                result.first=top;
                result.second=n-coordinates.first;
            }
        }
        else {
            throw std::invalid_argument("invalid coordinates");
        }
        return result;
    }
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 1) return;
        for(int i=0;i<(int)matrix.size();i++) {


            for(int j=0;j<(int)matrix.size()-(i*2)-1;j++) {
                int remember=matrix[i][i+j];
                std::pair<int,int> coordinates={i,i+j};
                for(int k=0;k<4;k++) {
                    int tmp;
                    std::pair<int,int> next=next_coordinates(coordinates,0+i,(int)matrix.size()-1-i,0+i,(int)matrix.size()-1-i,(int)matrix.size()-1);
                    tmp=matrix[next.first][next.second];
                    matrix[next.first][next.second]=remember;
                    remember=tmp;
                    coordinates=next;
                }
                
            }
        }
      //  print_vector(matrix);
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> result={{7,4,1},{8,5,2},{9,6,3}};

    s.rotate(matrix);
    assert(matrix==result);

    matrix={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    result={{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}};
    s.rotate(matrix);


    assert(matrix==result);

    matrix={{1,2},{3,4}};
    result={{3,1},{4,2}};

    s.rotate(matrix);
    assert(matrix==result);
    return EXIT_SUCCESS;
}
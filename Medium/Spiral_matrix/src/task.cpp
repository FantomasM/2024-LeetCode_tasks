#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

enum state {UP,RIGHT,LEFT,DOWN};

class Solution {
public:
    void print_vector(const vector<int> & v) {
        std::cout << "vector :" << std::endl;
        for (auto it = v.begin(); it != v.end(); ++it) {
            std::cout << *it<<" ";
        }
        std::cout << std::endl;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        state status = UP;
        if(matrix[0].size()==1) {
            status = RIGHT;
        }
        int waited_count=(int)(matrix.size()*matrix[0].size());
        int top_border=0,left_border=0,right_border=(int)matrix[0].size()-1,down_border=(int)matrix.size()-1;
        std::pair<int,int> current_x_y={0,0};
        vector<int> result;
        for(int i=0;i<waited_count;i++) {
            switch (status) {
                case UP:
                    result.push_back(matrix[current_x_y.first][current_x_y.second]);
                    if(current_x_y.second+1==right_border) {
                        status=RIGHT;
                        top_border++;
                    }
                current_x_y.second++;
                    break;
                case RIGHT:
                    result.push_back(matrix[current_x_y.first][current_x_y.second]);
                if(current_x_y.first+1==down_border) {
                    status=DOWN;
                    right_border--;
                }
                current_x_y.first++;
                    break;
                case LEFT:
                    result.push_back(matrix[current_x_y.first][current_x_y.second]);
                if(current_x_y.first-1==top_border) {
                    status=UP;
                    left_border++;
                }
                current_x_y.first--;
                    break;
                case DOWN:
                    result.push_back(matrix[current_x_y.first][current_x_y.second]);
                if(current_x_y.second-1==left_border) {
                    status=LEFT;
                    down_border--;
                }
                current_x_y.second--;
                    break;
            }
        }
        print_vector(result);
        return result;
    }
};

int main() {
    Solution s;

    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result={1,2,3,6,9,8,7,4,5};
    assert(s.spiralOrder(matrix)==result);

    matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    result={1,2,3,4,8,12,11,10,9,5,6,7};
    assert(s.spiralOrder(matrix)==result);

    matrix={{3,2}};
    result={3,2};
    assert(s.spiralOrder(matrix)==result);

    matrix={{3},{2}};
    assert(s.spiralOrder(matrix)==result);
    return EXIT_SUCCESS;
}
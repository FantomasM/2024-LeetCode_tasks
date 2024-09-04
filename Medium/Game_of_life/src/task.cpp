#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


class Solution {
public:
    void print_board(const vector<vector<int>>& board) {
        std::cout <<" board : " <<std::endl;

        for (int i = 0; i < (int)board.size(); ++i) {
            for (int j = 0; j < (int)board[i].size(); ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    int neighbours_count(const vector<vector<int>>& board, int y, int x) {
        int count=0;
        int limit=x+1;
        if(x==(int)board[0].size()-1) {
            limit=x;
        }
        int tmp_x=x;
        //down three cells
        if(y!=(int)board.size()-1) {
            if(x==0) {
                x=1;
            }

            for(int i=x-1;i<=limit;i++) {
                if(board[y+1][i]==1 || board[y+1][i]==-1) {

                    count++;
                }
            }
        }
        //middle cells
        x=tmp_x;
        if(x==0) {
            if(x==(int)board[0].size()-1) {

            }
            else {
                if(board[y][x+1]==1 || board[y][x+1]==-1) {

                    count++;
                }
            }
        }
        else {
            if(x==(int)board[0].size()-1) {
                if(board[y][x-1]==1 || board[y][x-1]==-1) {

                    count++;
                }
            }
            else {
                if(board[y][x-1]==1 || board[y][x-1]==-1) {

                    count++;
                }
                if(board[y][x+1]==1 || board[y][x+1]==-1) {

                    count++;
                }
            }
        }
        //upper cells
        if(y!=0) {
            if(x==0) {
                x=1;
            }

            for(int i=x-1;i<=limit;i++) {
                if(board[y-1][i]==1 || board[y-1][i]==-1) {

                    count++;
                }
            }
        }

        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<(int)board.size();i++) {
            for(int j=0;j<(int)board[0].size();j++) {
                int count = neighbours_count(board,i,j);
                int value=board[i][j];
                if(value==1 && (count <2 || count >3)) {
                    board[i][j]=-1;
                }
                else if(value==1 && count==3) {
                    board[i][j]=1;
                }

                else if(value==0 && count==3) {
                    board[i][j]=2;
                }

            }
        }

        for(int i=0;i<(int)board.size();i++) {
            for(int j=0;j<(int)board[0].size();j++) {
                if(board[i][j]==-1) {
                    board[i][j]=0;
                }
                else if(board[i][j]==2) {
                    board[i][j]=1;
                }
            }
        }
        //print_board(board);
    }
};

int main(void) {
    Solution s;


    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};

    vector<vector<int>> result={{0,0,0},{1,0,1},{0,1,1},{0,1,0}};
    assert(s.neighbours_count(board,0,0)==1);
    assert(s.neighbours_count(board,0,1)==1);
    assert(s.neighbours_count(board,0,2)==2);
    assert(s.neighbours_count(board,1,0)==3);
    assert(s.neighbours_count(board,1,1)==5);
    assert(s.neighbours_count(board,1,2)==3);
    assert(s.neighbours_count(board,2,0)==1);
    assert(s.neighbours_count(board,2,1)==3);
    assert(s.neighbours_count(board,2,2)==2);
    assert(s.neighbours_count(board,3,0)==2);
    assert(s.neighbours_count(board,3,1)==3);
    assert(s.neighbours_count(board,3,2)==2);


    s.gameOfLife(board);
    assert(board==result);

    board={{1,1},{1,0}};
    result={{1,1},{1,1}};

    s.gameOfLife(board);
    assert(board==result);

    return EXIT_SUCCESS;
}
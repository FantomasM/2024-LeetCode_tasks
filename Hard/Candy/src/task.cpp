#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    size_t find_longest_not_growing_piece(const vector<int> & ratings,vector<int> & result, size_t starting_index,int & total) {
        size_t index=starting_index;
        while(index<ratings.size()-1) {
            if(ratings[index]>=ratings[index+1]) {
                index++;
            }
            else {
                 break;
            }
        }
        int current_value=1;
        for(int i=(int)index;i>=(int)starting_index;i--) {
            if(i==(int)index) {
                if(i!=0 && i==(int)starting_index && ratings[i]>ratings[i-1] && current_value<=result[i-1]) {
                    current_value=result[i-1]+1;
                }
                result[index]=current_value;
                total+=current_value;
            }
            else {
                if(ratings[i]>ratings[i+1]) {
                    current_value++;
                }
                if(ratings[i]==ratings[i+1]) {
                    current_value=1;
                }
                if(i!=0 && i==(int)starting_index && ratings[i]>ratings[i-1] && current_value<=result[i-1]) {
                    current_value=result[i-1]+1;
                }
                result[i]=current_value;
                total+=current_value;
            }
        }
        return index;
    }
    void print_result_vector(const vector<int> & result) {
        std::cout <<"result: ";
        for(size_t i=0;i<result.size();i++) {
            std::cout << result[i] << " ";
        }
        std::cout << std::endl;
    }
    int candy(vector<int>& ratings) {
        int total=0;
        vector<int> result(ratings.size());
        for(size_t i=0;i<ratings.size();i++) {
            size_t new_index=find_longest_not_growing_piece(ratings,result,i,total);
            i=new_index;
        }
       // print_result_vector(result);
        return total;
    }
};

int main(void) {

    Solution s;
    vector<int> ratings_1={1,0,2};
    assert(s.candy(ratings_1)==5);

    vector<int> ratings_2={1,2,2};
    assert(s.candy(ratings_2)==4);

    vector<int> ratings_3={1,3,2,2,1};
    assert(s.candy(ratings_3)==7);

    return EXIT_SUCCESS;
}
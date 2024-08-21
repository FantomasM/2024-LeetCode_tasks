#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    void push_word_to_string(const string & src, string & dst,const int & first_index, const int & last_index) {
        for(int i=first_index;i<=last_index;i++) {
            dst.push_back(src[i]);
        }
        dst.push_back(' ');
    }
    string reverseWords(const string & s) {
        string result;
        int last_word_index=-1;
        int first_word_index=-1;
        bool prev_was_space=false;
        for(int i=(int)s.size()-1;i>=0;i--) {
            if(!isspace(s[i]) && (prev_was_space || i==(int)s.size()-1)) {
                last_word_index=i;
                first_word_index=i;
                prev_was_space=false;
            }
            else if(!isspace(s[i]) && !prev_was_space) {
                first_word_index=i;
                prev_was_space=false;
            }
            else {
                if(!prev_was_space && first_word_index!=-1 && last_word_index!=-1) {
                    push_word_to_string(s,result,first_word_index,last_word_index);
                    first_word_index=-1;
                    last_word_index=-1;

                }
                prev_was_space=true;
            }
        }
        if(last_word_index!=-1 && first_word_index!=-1) {
            push_word_to_string(s,result,first_word_index,last_word_index);
        }
        result.pop_back();
       // std::cout <<"result: "<<result<<std::endl;
        return result;

    }
};

int main(void) {
    Solution s;

    assert(s.reverseWords("ab") == "ab");

    assert(s.reverseWords("the sky is blue") == "blue is sky the");

    assert(s.reverseWords("  hello world ") == "world hello");

    assert(s.reverseWords("a good   example") == "example good a");




    return EXIT_SUCCESS;
}
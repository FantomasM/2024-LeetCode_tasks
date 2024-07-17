#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    bool is_palindrome(const string & s, size_t from, size_t to){

        for(size_t i=0;i<(to-from+1)/2;i++) {
            if(s[from+i]!=s[to-i]) {
                return false;
            }
        }
        return true;
    }
    string construct_string(const string & s, size_t from, size_t to) {
        string tmp;
        tmp.resize(to-from+1);
        size_t ptr=0;
        for(size_t i=from;i<=to;i++) {
            tmp[ptr]=s[i];
            ptr++;
        }
        //std::cout << tmp <<std::endl;
        return tmp;
    }
    string Brute_force(const string & s) {
        size_t maxlen=1;
        size_t from=0;
        size_t to=0;
        for(size_t i=0;i<s.size();i++) {
            for(size_t z=s.size()-1;z>i;z--) {
                if(s[i]==s[z] && is_palindrome(s,i,z)) {
                    if(z-i+1>maxlen) {
                        maxlen=z-i+1;
                        from=i;
                        to=z;
                    }
                }
            }
        }
        return construct_string(s,from,to);
    }
    string longestPalindrome(string s) {
       vector<size_t> longest_palindrom;
        vector<vector<bool>> palindrom_from_x_to_y;
        palindrom_from_x_to_y.resize(s.size());
        for(size_t i=0;i<s.size();i++) {
            palindrom_from_x_to_y[i].resize(s.size(),false);
        }

        size_t maxlen=1;
        size_t from=0;
        size_t to=0;
        longest_palindrom.resize(s.size(),1);
        for(ssize_t z=static_cast<ssize_t>(s.size())-1;z>=0;z--){
            for(ssize_t i=z;i<static_cast<ssize_t>(s.size());i++){
              //  std::cout <<"trying palindrome from index: "<<z <<" element: " <<s[z] <<" to index: " <<i <<" element: " <<s[i] <<std::endl;
                if(s[i]==s[z] && ((i!=z && (palindrom_from_x_to_y[z+1][i-1]==true||(z+1==i) ) ) || (i==z && is_palindrome(s,i,z)))) {
                    longest_palindrom[z]=static_cast<size_t>(i-z+1);
                    palindrom_from_x_to_y[z][i]=true;
                    if(longest_palindrom[z]>maxlen) {
                        maxlen=longest_palindrom[z];
                        from=static_cast<size_t>(z);
                        to=static_cast<size_t>(i);
                    }

                }
            }
        }
        return construct_string(s,from,to);

    }
};

int main(void) {
    Solution sol;

    assert(sol.is_palindrome("bab",0,2));
    assert(!sol.is_palindrome("bab",0,1));

    assert(sol.is_palindrome("123321",0,5));
    assert(!sol.is_palindrome("1234321",0,5));
    assert(sol.longestPalindrome("babad")=="bab" || sol.longestPalindrome("babad")=="aba");

    assert(sol.longestPalindrome("cbbd")=="bb");
    assert(sol.longestPalindrome("bb")=="bb");
    assert(sol.longestPalindrome("ccc")=="ccc");
    assert(sol.longestPalindrome("aacabdkacaa")=="aca");
}
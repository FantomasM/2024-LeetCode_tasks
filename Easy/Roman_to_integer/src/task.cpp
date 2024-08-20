#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;

//static char Roman[]={'I','V','X','L','C','D','M'};


class Solution {
public:
    Solution() {
        Romans['I']=1;
        Romans['V']=5;
        Romans['X']=10;
        Romans['L']=50;
        Romans['C']=100;
        Romans['D']=500;
        Romans['M']=1000;
    }
    bool find_bigger_roman(const string & s, const size_t & index,int value) {

        int cur_index=(int)index;
        while(cur_index<(int)s.size()) {
            if(value==1 &&( Romans[s[cur_index]]==5 || Romans[s[cur_index]]==10)) {
                return true;
            }
            else if(value==1 &&Romans[s[cur_index]]<=1) {
                cur_index++;
                continue;
            }

            if(value==10 &&( Romans[s[cur_index]]==50 || Romans[s[cur_index]]==100)) {
                return true;
            }
            else if(value==10 &&Romans[s[cur_index]]<=10) {
                cur_index++;
                continue;
            }

            if(value==100 &&( Romans[s[cur_index]]==500 || Romans[s[cur_index]]==1000)) {
                return true;
            }
            else if(value==100 &&Romans[s[cur_index]]<=100) {
                cur_index++;
                continue;
            }


        }
        return false;
    }
    int try_to_convert(const string & s, const size_t & index) {
        int tmp=Romans[s[index]];

        int value=0;
         if(tmp==5 || tmp==50 || tmp==500 || tmp==1000){
            return tmp;
        }
        else {
            if(find_bigger_roman(s, index+1,tmp)) {
                value-=tmp;
            }
            else {
                value+=tmp;
            }
        }
        return value;
    }
    int romanToInt(string s) {
        int total=0;
        for(size_t i=0;i<s.size();i++) {
            total+=try_to_convert(s,i);
        }
        //std::cout <<"total is " << total << std::endl;
        return total;
    }
    std::unordered_map<char,int> Romans;
};

int main(void) {

    Solution s;

    std::string task_1="III";
    assert(s.romanToInt(task_1) == 3);

    std::string task_2="LVIII";
    assert(s.romanToInt(task_2) == 58);

    std::string task_3="MCMXCIV";
    assert(s.romanToInt(task_3) == 1994);

    std::string task_4="MCMLXXXIX";
    assert(s.romanToInt(task_4) == 1989);

    std::string task_5="LXXVIII";
    assert(s.romanToInt(task_5) == 78);


    std::string task_7="MMXXIII";
    assert(s.romanToInt(task_7) == 2023);

    std::string task_8="MCMXII";
    assert(s.romanToInt(task_8) == 1912);
    return EXIT_SUCCESS;
}
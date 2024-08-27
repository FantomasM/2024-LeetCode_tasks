#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
public:
    void fill_occurences(std::unordered_map<char, int>& occurrences, const string & t) {
        for (const auto & c : t) {

            if(occurrences.find(c) == occurrences.end()) {
                occurrences[c] = 1;
            }
            else {
                occurrences[c]++;
            }
        }
    }
    string minWindow(const string & s, const string & t) {
        std::unordered_map<char, int> occurrences_needed;
        std::unordered_map<char,int> occurrences;
        fill_occurences(occurrences_needed, t);

        int total_occurences = (int)t.size();
        int current_minimum=INT32_MAX;
        int index_of_minimum_start=-1;
        int index_of_minimum_end=-1;
        int current_without_dups=0;
        int current=0;
        int first_index=0;
        int last_index=-1;

        for(int i=0;i<(int)s.size();i++) {
            last_index++;
            current++;
           if(occurrences_needed.find(s[i])!=occurrences_needed.end()) {

                if(occurrences.find(s[i]) == occurrences.end()) {
                   occurrences[s[i]] = 1;
                }
               else if(occurrences.find(s[i]) != occurrences.end()) {
                   occurrences[s[i]]++;
               }

               if(occurrences[s[i]]<=occurrences_needed[s[i]]) {
                   current_without_dups++;
               }


               while(current_without_dups==total_occurences) {

                   if(current<current_minimum) {
                       current_minimum=current;
                       index_of_minimum_start=first_index;
                       index_of_minimum_end=last_index;
                   }
                   current--;
                   if(occurrences_needed.find(s[first_index])==occurrences_needed.end() ) {
                       first_index++;
                   }
                   else if(occurrences[s[first_index]]-1>=occurrences_needed[s[first_index]] ) {

                       occurrences[s[first_index]]--;

                       first_index++;
                   }
                   else if(occurrences[s[first_index]]-1<occurrences_needed[s[first_index]] ) {

                       current++;
                       break;
                   }

               }
               if(current_without_dups==total_occurences && current<current_minimum) {
                   current_minimum=current;
                   index_of_minimum_start=first_index;
                   index_of_minimum_end=last_index;
               }
           }
            else {

                    while(current_without_dups==total_occurences) {
                        if(current<current_minimum) {
                            current_minimum=current;
                            index_of_minimum_start=first_index;
                            index_of_minimum_end=last_index;
                        }
                        current--;

                        if(occurrences_needed.find(s[first_index])==occurrences_needed.end() ) {
                            first_index++;
                        }
                        else if(occurrences[s[first_index]]-1>=occurrences_needed[s[first_index]] ) {

                            occurrences[s[first_index]]--;

                            first_index++;
                        }
                        else if(occurrences[s[first_index]]-1<occurrences_needed[s[first_index]] ) {

                            current++;
                            break;
                        }
                    }
                if(current_without_dups==total_occurences && current<current_minimum) {
                    current_minimum=current;
                    index_of_minimum_start=first_index;
                    index_of_minimum_end=last_index;
                }


            }
        }
        if(index_of_minimum_end==-1) {
         //   std::cout <<"result is an empty string " <<std::endl;
            return string{};
        }
        else {
           // std::cout <<" result is " << s.substr(index_of_minimum_start,index_of_minimum_end-index_of_minimum_start+1) << std::endl;
            return s.substr(index_of_minimum_start,index_of_minimum_end-index_of_minimum_start+1);
        }

        

    }
};

int main() {

    Solution s;

    string soul="ADOBECODEBANC", t = "ABC";
    assert(s.minWindow(soul, t)=="BANC");

    soul="a", t = "a";
    assert(s.minWindow(soul, t)=="a");

    soul="a", t = "aa";
    assert(s.minWindow(soul, t)=="");

    soul="cabwefgewcwaefgcf", t="cae";
    assert(s.minWindow(soul, t)=="cwae");


    return EXIT_SUCCESS;
}
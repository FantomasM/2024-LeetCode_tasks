#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:



    void fill_spaces(string & to_fill, int count) {
        for (int i = 0; i < count; i++) {
            to_fill.push_back(' ');
        }
    }
    void fill_the_line(bool last,bool custom_spaces,int count_of_spaces,string & to_fill, const vector<string> & words_to_take) {
        if(!custom_spaces) {
            for(int i = 0; i < (int)words_to_take.size(); i++) {
                to_fill+=words_to_take[i];
                if(i!=(int)words_to_take.size()-1) {
                    to_fill+=' ';
                }
            }




            return;
        }
        else {
            if(last) {





                for(int i = 0; i < (int)words_to_take.size(); i++) {
                    to_fill+=words_to_take[i];
                    if(i!=(int)words_to_take.size()-1) {
                        fill_spaces(to_fill,1);
                        count_of_spaces--;
                    }
                    else {
                        fill_spaces(to_fill,count_of_spaces);
                    }
                }


            }
            else {
                int delimeter=0;
                bool tmp_delimiter=false;
                if(words_to_take.size()>1) {
                    delimeter=count_of_spaces/((int)words_to_take.size()-1);
                    if(count_of_spaces%((int)words_to_take.size()-1)!=0) {
                        delimeter++;
                        tmp_delimiter=true;

                    }
                } else {
                    delimeter=count_of_spaces;
                }


                for(int i = 0; i < (int)words_to_take.size(); i++) {
                    to_fill+=words_to_take[i];
                    if(tmp_delimiter) {
                        if( ((delimeter!=1 && count_of_spaces%(delimeter-1)!=0) || (delimeter-1==1 && count_of_spaces-((delimeter-1)*((int)words_to_take.size()-1-i))!=0))) {
                            fill_spaces(to_fill,delimeter);
                            count_of_spaces-=delimeter;
                        }
                        else if((( delimeter!=1 && count_of_spaces%(delimeter-1)==0 ) || (delimeter-1==1 && count_of_spaces-((delimeter-1)*((int)words_to_take.size()-i))==0)) ) {
                            delimeter--;
                            tmp_delimiter=false;
                            fill_spaces(to_fill,delimeter);
                            count_of_spaces-=delimeter;
                        }
                    }
                    else if(i!=(int)words_to_take.size()-1 || (i==0 && i==(int)words_to_take.size()-1)){
                        fill_spaces(to_fill,delimeter);
                    }
                }
            }

        }

    }
    void print_vector_of_strings(const vector<string> & result) {
        std::cout<<"result is : " <<std::endl;
        for(unsigned int i = 0; i < result.size(); i++) {
            cout<<">"<<result[i]<<"<"<<std::endl;
        }

    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        string current_line = "";
        vector<string> tmp_words;
        vector<string> result;
        int only_words_len=0;

        size_t current_len=0;
        for(size_t i = 0; i < words.size(); i++) {
            if(tmp_words.size() ==0) {
                tmp_words.push_back(words[i]);
                current_len=words[i].length();
                only_words_len+=(int)current_len;
            }
            else if(current_len+words[i].size()+1 <= (size_t)maxWidth) {
                tmp_words.push_back(words[i]);
                current_len += words[i].size()+1;
                only_words_len+=words[i].size();
                //Special case, words can be combined with one space between them
                if((int)current_len==maxWidth) {
                    fill_the_line(false,false,0,current_line,tmp_words);
                    result.push_back(current_line);
                    current_line="";
                    tmp_words.clear();
                    current_len=0;
                    only_words_len=0;
                }
                else if(i==words.size()-1) {
                    int spaces=maxWidth-only_words_len;
                    fill_the_line(true,true,spaces,current_line,tmp_words);
                    result.push_back(current_line);
                    current_line="";
                    tmp_words.clear();
                    current_len=0;
                    only_words_len=0;
                }
            }
            else if((int)current_len+(int)words[i].size()+1 > maxWidth) {
                i--;
                int spaces=maxWidth-only_words_len;
                fill_the_line(false,true,spaces,current_line,tmp_words);
                result.push_back(current_line);
                current_line="";
                tmp_words.clear();
                current_len=0;
                only_words_len=0;
            }

        }
        if(tmp_words.size()>0) {
            int spaces=maxWidth-only_words_len;
            fill_the_line(true,true,spaces,current_line,tmp_words);
            result.push_back(current_line);
            current_line="";
            tmp_words.clear();
            current_len=0;
            only_words_len=0;
        }
       // print_vector_of_strings(result);
        return result;
    }
};

int main() {

    Solution s;

    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> result = {
        "This    is    an",
        "example  of text",
        "justification.  "};
 
    assert(s.fullJustify(words,16)==result);

    vector<string> words_1 = {"What","must","be","acknowledgment","shall","be"};
    vector<string> result_1 = {"What   must   be",
  "acknowledgment  ",
  "shall be        "};

    assert(s.fullJustify(words_1,16)==result_1);


    vector<string> words_2 = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> result_2 = {"Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "};
    assert(s.fullJustify(words_2,20)==result_2);


    vector<string> words_3 = {"The","important","thing","is","not","to","stop","questioning.","Curiosity","has","its","own","reason","for","existing."};
    vector<string> result_3 = {"The     important","thing  is  not to","stop questioning.","Curiosity has its","own   reason  for","existing.        "};

    assert(s.fullJustify(words_3,17)==result_3);


    vector<string> words_4 = {"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
    vector<string> result_4 = {"ask   not   what","your country can","do  for  you ask","what  you can do","for your country"};

    assert(s.fullJustify(words_4,16)==result_4);

    return EXIT_SUCCESS;
}
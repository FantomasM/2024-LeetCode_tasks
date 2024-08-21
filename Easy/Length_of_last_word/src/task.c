#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

int lengthOfLastWord(const char* s) {
    int len = (int)strlen(s);

    int first_letter_index=-1;
    int last_letter_index=-1;
    bool prev_was_space=false;
    for(int i=0;i<len;i++) {
        if(!isspace(s[i]) && (prev_was_space || i==0)) {
            first_letter_index=i;
            last_letter_index=i;
            prev_was_space=false;
        }
        else if(!isspace(s[i]) && (!prev_was_space)) {
            last_letter_index=i;
            prev_was_space=false;
        }
        else {
            prev_was_space=true;
        }
    }
    printf("length of the string = %d\n", last_letter_index-first_letter_index+1);
    return last_letter_index-first_letter_index+1;
}

int main(void) {
    assert(lengthOfLastWord("Hello World")==5);

    assert(lengthOfLastWord("   fly me   to   the moon  ")==4);

    assert(lengthOfLastWord("luffy is still joyboy")==6);



    return EXIT_SUCCESS;
}
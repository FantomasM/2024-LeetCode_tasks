#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <strings.h>

#define romans_size 13
char romans[][3]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int romans_dig[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};

typedef struct string_custom_t {
    char * str;
    size_t len;
    size_t capacity;
}STRING_CUSTOM;

void init(STRING_CUSTOM * str) {
    str->len=0;
    str->capacity=2;
    str->str = (char*)malloc(str->capacity);
    if(str->str==NULL) {
        exit(EXIT_FAILURE);
    }
}
void realloc_custom(STRING_CUSTOM * str) {
    str->capacity *= 2;
    str->str = realloc(str->str, str->capacity);
    if(str->str==NULL) {
        exit(EXIT_FAILURE);
    }
}
void dealloc(STRING_CUSTOM * str) {
    free(str->str);
    str->str=NULL;
    str->capacity=0;
    str->len=0;
}
void print_string_custom(STRING_CUSTOM * str) {
    printf("string: ");
    for(size_t i=0; i<str->len; i++) {
        printf("%c", str->str[i]);
    }
    printf("\n");
}
char* intToRoman(int num) {
    STRING_CUSTOM string_main;
    init(&string_main);
    int tmp_num=num;
    int index=0;
    while(tmp_num!=0 && index<romans_size) {
        if(tmp_num-romans_dig[index]>=0) {
            tmp_num-=romans_dig[index];
            if(string_main.capacity==string_main.len) {
                realloc_custom(&string_main);

            }
            if(strlen(romans[index])==1) {
                string_main.str[string_main.len++]=romans[index][0];
            }
            else {
                string_main.str[string_main.len++]=romans[index][0];
                if(string_main.capacity==string_main.len) {
                    realloc_custom(&string_main);

                }
                string_main.str[string_main.len++]=romans[index][1];
            }
        }
        else {
            index++;
        }
    }
   // print_string_custom(&string_main);
    if(string_main.capacity==string_main.len) {
        realloc_custom(&string_main);

    }
    string_main.str[string_main.len]='\0';
    return string_main.str;
}

int main(void) {
    char * str=intToRoman(3749);
    assert(strncmp(str,"MMMDCCXLIX",10)==0);
    free(str);
    str=intToRoman(58);
    assert(strncmp(str,"LVIII",5)==0);
    free(str);
    str=intToRoman(1994);
    assert(strncmp(str,"MCMXCIV",7)==0);
    free(str);

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void shift_elements(int **array,int from, int numsSize){
    for(int i=from;i<numsSize-1;i++){
        (*array)[i]=(*array)[i+1];
    }
}
void print_array(int * array,int numsSize){
    for(int i=0;i<numsSize;i++){
        printf("%d ",array[i]);

    }
    printf("\n");
}
int removeElement(int* nums, int numsSize, int val) {
    int count_of_normies=0;
    int counter=0;
    for(int i=0;i<numsSize;i++){
        if(nums[counter]!=val){
            count_of_normies++;
            counter++;
        }
        else{
            shift_elements(&nums,counter,numsSize);
            
        }
    }

    return count_of_normies;
}

int main(void){
    int nums_1[]={3,2,2,3};
    int value=3;
    int res=removeElement(nums_1,4,value);
    int nums_1_expected[]={2,2};
    print_array(nums_1,4);
    assert(res==2);
    for(int i=0;i<2;i++){
        assert(nums_1[i]==nums_1_expected[i]);
    }
    

     int nums_2[]={0,1,2,2,3,0,4,2};
     value=2;
    res=removeElement(nums_2,8,value);
    int nums_2_expected[]={0,1,3,0,4};
    print_array(nums_2,8);
    assert(res==5);
    for(int i=0;i<5;i++){
        assert(nums_2[i]==nums_2_expected[i]);
    }
   
    return EXIT_SUCCESS;
}

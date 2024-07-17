#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_array(int * array,int numsSize){
    for(int i=0;i<numsSize;i++){
        printf("%d ",array[i]);

    }
    printf("\n");
}
int removeDuplicates(int* nums, int numsSize) {
    int count_of_normies=1;
    int counter=1;
    int real_size=numsSize;
    for(int i=1;i<numsSize;i++){
        if(counter>real_size){
            return count_of_normies;
        }
        if(nums[i]!=nums[i-1]){
            count_of_normies++;
            nums[counter]=nums[i];
            counter++;
        }
        else{
            
           
            real_size--;
            
        }
    }

    return count_of_normies;
}

int main(void){

     int nums_1[]={1,1,2};
 
    int res=removeDuplicates(nums_1,3);
    int nums_1_expected[]={1,2};
    print_array(nums_1,3);
    assert(res==2);
    for(int i=0;i<2;i++){
        assert(nums_1[i]==nums_1_expected[i]);
    }
    

     int nums_2[]={0,0,1,1,1,2,2,3,3,4};
     
    res=removeDuplicates(nums_2,10);
    int nums_2_expected[]={0,1,2,3,4};
    print_array(nums_2,10);
    assert(res==5);
    for(int i=0;i<5;i++){
        assert(nums_2[i]==nums_2_expected[i]);
    }
    int nums_3[]={1,2,2};
    int nums_3_expected[]={1,2};
    res=removeDuplicates(nums_3,3);
     print_array(nums_3,3);
    assert(res==2);
    for(int i=0;i<2;i++){
        assert(nums_3[i]==nums_3_expected[i]);
    }

    return EXIT_SUCCESS;


}
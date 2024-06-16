#include <stdio.h>
#include <stdlib.h>


int searchInsert(int* nums, int numsSize, int target);


int main(){
    int nums[2]= {1,3};
    int target = 3;
    printf("Middle:%d\n", searchInsert(nums, 2, target));
    return 0;
}

int searchInsert(int* nums, int numsSize, int target){
    int right, left, mid;
    right = numsSize-1;
    left = 0;
    while(left < right){   
        mid = left + (right - left)/2;
        if (target < nums[mid]){     
            right = mid; 
        }
        else if (target > nums[mid]){ 
            left = mid+1; 
        } 
        else {
            return mid;
        }
    }
    if (left == right){ 
        if (target < nums[left]){                
            mid= left;
        } 
        else if (target > nums[left]){  
            mid= left+1;    
        } 
        else {
            mid = left;
            return mid;
        }
    }
    return mid;
}
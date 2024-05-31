/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int i, j;
    // init return array
    int* results = (int*)malloc(2 * sizeof(int));
    // i could not iterated to n-1, since every element is compared.
    for (i=0; i< numsSize-1; i++){ 
        for (j = i+1; j < numsSize; j++){ 
            if(nums[i] + nums[j] == target){
                results[0] = i;
                results[1] = j;
                *returnSize = 2;
                return results;
            }        
        }
    }
    // If no solution is found
    free(results); // Free the allocated memory before returning
    *returnSize = 0;
    return NULL;
}
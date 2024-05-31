/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 // Define hash 
int hash(int key, int size){
    return abs(key) % size;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    // Define hash table structure.
    typedef struct{
        int key;
        int value;
        bool hasData;
    } twosum;

    int hashtableSize = numsSize * 2; // 8
    twosum* hashtable = (twosum*)calloc(hashtableSize, sizeof(twosum));

    // Initialize return array
    int* results = (int*)malloc(2 * sizeof(int)); 
    if (!results) return NULL; // Return NULL if memory allocation fails
    
    // init hash table
    for(int i=0;i<hashtableSize;i++){   
        hashtable[i].key=0;
        hashtable[i].value=0;
        hashtable[i].hasData = false;
    }
       
    // insert key to certain index.
    for (int i=0; i < numsSize; i++){
        // only needs to insert the complement number
        int complement = target - nums[i]; //  0 90= -90 

        int index = hash(complement, hashtableSize); // hash(90,8) = 2
        
        // Linear probing for searching empty slot
        while(hashtable[index].hasData ){
            // find target
            if ( hashtable[index].key == complement){
                results[0] = hashtable[index].value;
                results[1] = i;
                *returnSize = 2;
                free(hashtable);
                return results;
            }
            // try to find empty index.
            index = hash(index+1, hashtableSize); // hash(5,8 ) = 5 
        }


        // insert current number
        index = hash(nums[i], hashtableSize);    // hash(90,8) = hash(90, 8)= 2
        while (hashtable[index].hasData) {
            index = hash(index+1, hashtableSize);
        }
        hashtable[index].key = nums[i]; 
        hashtable[index].value = i;
        hashtable[index].hasData = true;
        
    }

    free(hashtable);
    free(results);
    *returnSize = 0;
    return NULL;

}
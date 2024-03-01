//
//  main.c
//  1
//
//  Created by Hyman on 2024/3/1.
//


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j;
    for (i=0;i<numsSize;i++){
        for (j=i+1;j<numsSize;j++){
            if (nums[i] + nums[j] == target){
                int*result = malloc(sizeof(int)*2);
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main(int argc, const char * argv[]) {
    int nums[4] = {2,7,11,15};
    int target = 9;
    int *returnSize = (int*)malloc(sizeof(int));
    int *sum = twoSum(nums, 4, target, returnSize);
    for (int i=0;i<*returnSize;i++)
        printf("%d\n",nums[i]);
    return 0;
}

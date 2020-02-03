#include "stdio.h"
#include "stdlib.h"
#include "uthash.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* my_twoSum(int* nums, int numsSize, int target, int* returnSize){
#define RESULT_SIZE 2
	int i, j, want;
	int * result = (int *)malloc(sizeof(int) * RESULT_SIZE);

	if (numsSize < RESULT_SIZE) {
		goto ERROR;
	}

	if (NULL == result) {
		return NULL;
	}
	
	memset(result,0,sizeof(int)* RESULT_SIZE);
	want = 0;
	for (i = 0; i < numsSize; i++) {
		result[0] = i;
		want = target - nums[i];
		for (j = i + 1; j < numsSize; j++) {
			if (nums[j] == want) {
				result[1] = j;
				*returnSize = RESULT_SIZE;
				return result;
			}
		}
	}

ERROR:
	*returnSize = 0;
	if (result != NULL) {
		free(result);
		result = NULL;
	}
	return NULL;
}


struct hash_table {
    int ikey;
    int value;
    UT_hash_handle hh;
};

struct hash_table* find_hash(struct hash_table *table, int ikey)
{
    struct hash_table* s;

    if (table == NULL)
        return NULL;

    HASH_FIND_INT(table, &ikey, s);
    return s;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    struct hash_table *hash_entry;
    struct hash_table *hash_head = NULL;
    int *result = NULL;
    int i;

    *returnSize = 0;
    if ((nums == NULL) || (numsSize == 0))
        return NULL;

    for (i = 0; i < numsSize; i++) {
        hash_entry = find_hash(hash_head, target - *(nums + i));
        if (hash_entry == NULL) {
            hash_entry = malloc(sizeof(struct hash_table));
            if (hash_entry == NULL)
                return NULL;
            hash_entry->ikey = *(nums + i);
            hash_entry->value = i;
            HASH_ADD_INT(hash_head, ikey, hash_entry);
        } else {
            result = malloc(2 * sizeof(int));
            result[0] = i;
            result[1] = hash_entry->value;
            *returnSize = 2;
            return result;
        }
    }

    return NULL;
}

/*
 * 利用哈希表的特性处理此问题
 */
void main()
{
	printf("leetcode-1.twoSum code ...\n");
	return 0;
}
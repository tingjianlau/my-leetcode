/*************************************************************************
	> File Name: 1_two_sum.c
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/17
 ************************************************************************/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct HashNode {
    int key;
    int val;
} HashNode;

typedef struct HashMap {
    int size;
    HashNode** storage;
} HashMap;

HashMap* hash_create(int size);
void hash_destroy(HashMap* hashMap);
void hash_set(HashMap* hashMap, int key, int value);
HashNode* hash_get(HashMap* hashMap, int key);

HashMap* hash_create(int size){
    HashMap* hashMap = malloc(sizeof(HashMap));
    hashMap->size = size;
    hashMap->storage = calloc(size, sizeof(HashNode*));
    return hashMap;
}

void hash_destroy(HashMap* hashMap) {
    for(int i; i < hashMap->size; i++) {
        HashNode *node;
        if((node = hashMap->storage[i])) {
            free(node);
        }
    }
    free(hashMap->storage);
    free(hashMap);
}

void hash_set(HashMap *hashMap, int key, int value) {
    int hash = abs(key) % hashMap->size;
    HashNode* node;
    while ((node = hashMap->storage[hash])) {
        if (hash < hashMap->size - 1) {
            hash++;
        } else {
            hash = 0;
        }
    }
    node = malloc(sizeof(HashNode));
    node->key = key;
    node->val = value;
    hashMap->storage[hash] = node;
}

HashNode* hash_get(HashMap *hashMap, int key) {
    int hash = abs(key) % hashMap->size;
    HashNode* node;
    while ((node = hashMap->storage[hash])) {
        if (node->key == key) {
            return node;
        }

        if (hash < hashMap->size - 1) {
            hash++;
        } else {
            hash = 0;
        }
    }

    return NULL;
}
int* twoSum(int* nums, int numsSize, int target) {
    HashMap* hashMap;
    HashNode* node;
    int rest, i;
    int* result = malloc(sizeof(int)*2);

    // make the hashMap 2x size of the numsSize
    hashMap = hash_create(numsSize * 2);
    for(i = 0; i < numsSize; i++) {
        rest = target - nums[i];
        node = hash_get(hashMap, rest);
        if (node) {
            result[0] = node->val;
            result[1] = i;
            hash_destroy(hashMap);
            break;
        } else {
            hash_set(hashMap, nums[i], i);
        }
    }
    
    return result;
}


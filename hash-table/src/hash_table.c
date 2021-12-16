#include "hash_table.h"

/**
 * Size of the hashtable.
 */
int TABLE_SIZE = 100000;

/**
 * Creates a new hashtable of the defined size TABLE_SIZE.
 * @return Pointer to an empty hashtable
 */
HashTable *new_hash_table() {
    HashTable *hash_table = malloc(1 * sizeof(HashTable));
    hash_table->pairs = malloc(TABLE_SIZE * sizeof(Pair*));
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hash_table->pairs[i] = NULL;
    }
    return hash_table;
}

/**
 * Creates a new key-value pair with given key and value.
 * @param key Key of the pair
 * @param value Value of the pair
 * @return Pointer to the initialized key-value pair
 */
Pair *new_pair(char *key, int value) {
    Pair *pair = malloc(sizeof(Pair));
    strcpy(pair->key, key);
    pair->val = value;
    pair->next = NULL;
    return pair;
}

/**
 * Frees the allocated memory of a key-value pair and all pairs linked to it.
 * @param pair Pointer to the key-value pair to free
 */
void free_pair(Pair *pair) {
    Pair *tmp;
    while (pair != NULL) {
        tmp = pair;
        pair = pair->next;
        free(tmp);
    }
}

/**
 * Frees the allocated memory of a hashtable and all key-value pairs stored in it.
 * @param table Pointer to the hashtable to free
 */
void free_hash_table(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (table->pairs[i] != NULL) {
            free_pair(table->pairs[i]);
        }
    }
    free(table->pairs);
    free(table);
}

/**
 * Calculates the hash of a given string.
 * @param str String to be hashed
 * @return Hash-value of the given string
 */
unsigned int hash(char *str) {
    unsigned long int value = 0;
    unsigned int str_len = strlen(str);
    for (int i = 0; i < str_len; ++i) {
        value = value * 37 + str[i];
    }
    return value % TABLE_SIZE;
}

/**
 * Adds a key-value pair to a given hashtable.
 * @param table Pointer to the hashtable in which the pair should be added
 * @param key Key of the pair
 * @param value Value of the pair
 */
void add_value(HashTable *table, char *key, int value) {
    unsigned int idx = hash(key);
    Pair *pair = table->pairs[idx];
    // slot is still free
    if (pair == NULL) {
        table->pairs[idx] = new_pair(key, value);
        return;
    }
    // slot is not free
    Pair *prev;
    while (pair != NULL) {
        // this is the current key so we replace with the new value
        if (!strcmp(key, pair->key)) {
            pair->val = value;
            return;
        }
        prev = pair;
        pair = pair->next;
    }
    // end of loop reached so we need to add a new pair to the list stored at the slot
    prev->next = new_pair(key, value);
}

/**
 * Retrieves the value stored in a given hashtable associated with a given key.
 * @param table Pointer to the hashtable in which to look for the value
 * @param key Key from which the value should be retrieved
 * @return Value associated with the given key
 */
int get_value(HashTable *table, char *key) {
    unsigned int idx = hash(key);
    // no entry found at this hashkey
    if (table->pairs[idx] == NULL) {
        return 0;
    }
    Pair *pair = table->pairs[idx];
    while (pair != NULL) {
        // this is the current key so return the value
        if (!strcmp(key, pair->key)) {
            return pair->val;
        }
        pair = pair->next;
    }
    // slot is not empty but the key is not stored there
    return 0;
}

/**
 * Prints a given hashtable.
 * @param table Pointer to the hashtable to be printed
 */
void print_hash_table(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Pair *pair = table->pairs[i];
        if (pair == NULL) {
            continue;
        }
        printf("slot %4d: ", i);
        while (pair != NULL) {
            printf("key:%s; val:%d || ", pair->key, pair->val);
            pair = pair->next;
        }
        printf("\n");
    }
}

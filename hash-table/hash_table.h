// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2023 Felix Zailskas <felixzailskas@gmail.com>

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Size of the hashtable.
 */
int TABLE_SIZE = 100000;

/**
 * Structure representing a key-value pair.
 * It contains
 *  the key
 *  the value
 *  a link to the next pair in the same slot
 */
typedef struct Pair {
  char key[50];
  int val;
  struct Pair *next;
} Pair;

/**
 * Structure representing a hashtable.
 * It contains
 *  an array of Pair pointers
 */
typedef struct HashTable {
  Pair **pairs;
} HashTable;

/**
 * Creates a new hashtable of the defined size TABLE_SIZE.
 * @return Pointer to an empty hashtable
 */
HashTable *new_hash_table();

/**
 * Creates a new key-value pair with given key and value.
 * @param key Key of the pair
 * @param value Value of the pair
 * @return Pointer to the initialized key-value pair
 */
Pair *new_pair(char *key, int value);

/**
 * Frees the allocated memory of a key-value pair and all pairs linked to it.
 * @param pair Pointer to the key-value pair to free
 */
void free_pair(Pair *pair);

/**
 * Frees the allocated memory of a hashtable and all key-value pairs stored in
 * it.
 * @param table Pointer to the hashtable to free
 */
void free_hash_table(HashTable *table);

/**
 * Calculates the hash of a given string.
 * @param str String to be hashed
 * @return Hash-value of the given string
 */
unsigned int hash(char *str);

/**
 * Adds a key-value pair to a given hashtable.
 * @param table Pointer to the hashtable in which the pair should be added
 * @param key Key of the pair
 * @param value Value of the pair
 */
void add_value(HashTable *table, char *key, int value);

/**
 * Retrieves the value stored in a given hashtable associated with a given key.
 * @param table Pointer to the hashtable in which to look for the value
 * @param key Key from which the value should be retrieved
 * @return Value associated with the given key
 */
int get_value(HashTable *table, char *key);

/**
 * Prints a given hashtable.
 * @param table Pointer to the hashtable to be printed
 */
void print_hash_table(HashTable *table);

#endif

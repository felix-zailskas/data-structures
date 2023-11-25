// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2023 Felix Zailskas <felixzailskas@gmail.com>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode *List;

typedef struct ListNode {
  int item;
  List next;
} ListNode;

/**
 * Creates a new empty list
 * @return Emtpy List
 */
List new_empty_list();

/**
 * Checks whether a list is empty
 * @param li List checked
 * @return 1 if list is empty, 0 otherwise
 */
int is_empty_list(List li);

/**
 * Called when an operation is invalidly called on an empty list
 * Aborts the program
 */
void list_empty_error();

/**
 * Called when an operation is invalidly called on a list that is too short
 * Aborts the program
 */
void list_too_short_error();

/**
 * Adds an item to the front of the list
 * @param li List in which to add
 * @param n Item to be added
 * @return List with new item at the front
 */
List add_item_front(List li, int n);

/**
 * Adds an item to the back of the list
 * @param li List in which to add
 * @param n Item to be added
 * @return List with new item at the back
 */
List add_item_back(List li, int n);

/**
 * Adds an item to a given position in the list if the list is long enough
 * (recursively)
 * @param li List in which to add
 * @param n Item to be added
 * @param p Position at which to add
 * @return List with new item at the position
 */
List add_item_at_pos_rec(List li, int n, int p);

/**
 * Adds an item to a given position in the list if the list is long enough
 * (iteratively)
 * @param li List in which to add
 * @param n Item to be added
 * @param p Position at which to add
 * @return List with new item at the position
 */
List add_item_at_pos_it(List li, int n, int p);

/**
 * Returns the first item of a list
 * @param li List
 * @return First item
 */
int first_item(List li);

/**
 * Returns the item of a list at a given position
 * @param li List
 * @param p Position
 * @return Item at position
 */
int item_at_pos_it(List li, int p);

/**
 * Returns the item of a list at a given position (recursively)
 * @param li List
 * @param p Position
 * @return Item at position
 */
int item_at_pos_rec(List li, int p);

/**
 * Removes the first node of a list
 * @param li List
 * @return Tail of the list
 */
List remove_first_node(List li);

/**
 * Removes the first occurrence of an item in a list (recursively)
 * @param li List
 * @param n Item to remove
 * @return List without the first occurrence of the item
 */
List remove_first_of_item_rec(List li, int n);

/**
 * Removes the first occurrence of an item in a list (iteratively)
 * @param li List
 * @param n Item to remove
 * @return List without the first occurrence of the item
 */
List remove_first_of_item_it(List li, int n);

/**
 * Removes all occurrences of an item in a list (recursively)
 * @param li List
 * @param n Item to remove
 * @return List without any occurrence of the item
 */
List remove_all_of_item_rec(List li, int n);

/**
 * Removes all occurrences of an item in a list (iteratively)
 * @param li List
 * @param n Item to remove
 * @return List without any occurrence of the item
 */
List remove_all_of_item_it(List li, int n);

/**
 * Removes the item at a given position in a list (recursively)
 * @param li List
 * @param p Position at which to remove
 * @return List without the item at the position
 */
List remove_item_at_pos_rec(List li, int p);

/**
 * Removes the item at a given position in a list (iteratively)
 * @param li List
 * @param p Position at which to remove
 * @return List without the item at the position
 */
List remove_item_at_pos_it(List li, int p);

/**
 * Visit a node by printing the item
 * @param li List node to visit
 */
void visit(List li);

/**
 * Visit a list by printing all items (recursively)
 * @param li List to visit
 */
void visit_list_rec(List li);

/**
 * Visit a list by printing all items (iteratively)
 * @param li List to visit
 */
void visit_list_it(List li);

/**
 * Reverse the order of a list
 * @param li List to reverse the order of
 * @return A list with reversed order
 */
List reverse_list(List li);

/**
 * Determines the length of a list
 * @param li List
 * @return Length of the list
 */
int list_length(List li);

/**
 * Frees all memory allocated by a list
 * @param li List to free
 */
void free_list(List li);

#endif

//
// Created by Felix Zailskas on 30.07.21.
//

#include "linked_list.h"
#include "assert.h"

/**
 * Creates a new empty list
 * @return Emtpy List
 */
List new_empty_list() {
    return NULL;
}

/**
 * Checks whether a list is empty
 * @param li List checked
 * @return 1 if list is empty, 0 otherwise
 */
int is_empty_list(List li) {
    return (li == NULL);
}

/**
 * Called when an operation is invalidly called on an empty list
 * Aborts the program
 */
void list_empty_error() {
    printf("Operation requires a non-emtpy list! Abort program!\n");
    abort();
}

/**
 * Called when an operation is invalidly called on a list that is too short
 * Aborts the program
 */
void list_too_short_error() {
    printf("Operation requires a longer list! Abort program!\n");
    abort();
}

/**
 * Adds an item to the front of the list
 * @param li List in which to add
 * @param n Item to be added
 * @return List with new item at the front
 */
List add_item_front(List li, int n) {
    List l = malloc(sizeof(ListNode));
    l->item = n;
    l->next = li;
    return l;
}

/**
 * Adds an item to the back of the list
 * @param li List in which to add
 * @param n Item to be added
 * @return List with new item at the back
 */
List add_item_back(List li, int n) {
    List l = malloc(sizeof(ListNode));
    l->item = n;
    l->next = NULL;
    if (is_empty_list(li)) {
        return l;
    }
    List temp = li;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = l;
    return li;
}

/**
 * Adds an item to a given position in the list if the list is long enough (recursively)
 * @param li List in which to add
 * @param n Item to be added
 * @param p Position at which to add
 * @return List with new item at the position
 */
List add_item_at_pos_rec(List li, int n, int p) {
    if (p == 0) {
        return add_item_front(li, n);
    }
    if (is_empty_list(li)) {
        list_too_short_error();
    }
    li->next = add_item_at_pos_rec(li->next, n, p-1);
    return li;
}

/**
 * Adds an item to a given position in the list if the list is long enough (iteratively)
 * @param li List in which to add
 * @param n Item to be added
 * @param p Position at which to add
 * @return List with new item at the position
 */
List add_item_at_pos_it(List li, int n, int p) {
    if (p == 0) {
        return add_item_front(li, n);
    }
    List temp = li;
    while (temp != NULL && p > 1) {
        temp = temp->next;
        p--;
    }
    if (is_empty_list(temp)) {
        list_too_short_error();
    }
    temp->next = add_item_front(temp->next, n);
    return li;
}

/**
 * Returns the first item of a list
 * @param li List
 * @return First item
 */
int first_item(List li) {
    if (is_empty_list(li)) {
        list_empty_error();
    }
    return li->item;
}

/**
 * Returns the item of a list at a given position (iteratively)
 * @param li List
 * @param p Position
 * @return Item at position
 */
int item_at_pos_it(List li, int p) {
    if (is_empty_list(li)) {
        list_empty_error();
    }
    while (p > 0) {
        li = li->next;
        p--;
    }
    if (is_empty_list(li)) {
        list_too_short_error();
    }
    return li->item;
}

/**
 * Returns the item of a list at a given position (recursively)
 * @param li List
 * @param p Position
 * @return Item at position
 */
int item_at_pos_rec(List li, int p) {
    if (is_empty_list(li)) {
        list_empty_error();
    }
    if (p == 0) {
        return li->item;
    }
    return item_at_pos_rec(li->next, p - 1);
}

/**
 * Removes the first node of a list
 * @param li List
 * @return Tail of the list
 */
List remove_first_node(List li) {
    if (is_empty_list(li)) {
        list_empty_error();
    }
    List temp = li->next;
    free(li);
    return temp;
}

/**
 * Removes the first occurrence of an item in a list (recursively)
 * @param li List
 * @param n Item to remove
 * @return List without the first occurrence of the item
 */
List remove_first_of_item_rec(List li, int n) {
    if (is_empty_list(li)) {
        return li;
    }
    if (li->item == n) {
        return remove_first_node(li);
    }
    li->next = remove_first_of_item_rec(li->next, n);
    return li;
}

/**
 * Removes the first occurrence of an item in a list (iteratively)
 * @param li List
 * @param n Item to remove
 * @return List without the first occurrence of the item
 */
List remove_first_of_item_it(List li, int n) {
    if (is_empty_list(li)) {
        return li;
    }
    List temp = li;
    while (temp->item != n && !is_empty_list(temp)) {
        temp = temp->next;
    }
    if (is_empty_list(temp)) {
        return li;
    }
    remove_first_node(temp);
    return li;
}

/**
 * Removes all occurrences of an item in a list (recursively)
 * @param li List
 * @param n Item to remove
 * @return List without any occurrence of the item
 */
List remove_all_of_item_rec(List li, int n) {
    if (is_empty_list(li)) {
        return li;
    }
    if (li->item == n) {
        li = remove_first_node(li);
    }
    li->next = remove_first_of_item_rec(li->next, n);
    return li;
}

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

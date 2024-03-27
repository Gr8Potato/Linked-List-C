// DISCLAIMER: I DO NOT SUPPORT PEOPLE PLAGIARIZING MY CODE. I DO NOT TAKE RESPONSIBILITY FOR THE UNLAWFUL ACTIONS OF OTHERS.

/**
 * @date 11/2/2023
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * @brief A struct representing a node in the linked list
 */
typedef struct Node
{
    int data;          /** The data contained in the node */
    struct Node *next; /** Pointer to the next node in the list */
} Node;

/**
 * @brief Pointer to the first node in the linked list
 */
extern Node *head;

/**
 * @brief Adds content to the end of the linked list
 *
 * @param head The pointer to the head of the linked list
 * @param data The data to be added to the end of the list
 */
void append(Node **head_ref, int data);

/**
 * @brief Adds content to the linked list at the specified position
 *
 * @param head_ref The pointer to the head of the linked list
 * @param data The data to be added
 * @param pos The position (starting from 0) to add the data
 */
void add(Node **head_ref, int data, int pos);

/**
 * @brief Removes content from the linked list at the specified position
 *
 * @param head_ref The pointer to the head of the linked list
 * @param pos The position (starting from 0) to remove the node from
 */
void delete(Node **head_ref, int pos);

/**
 * @brief Removes content from the linked list based on data
 *
 * @param head_ref The pointer to the head of the linked list
 * @param data The data value to be removed
 */
void delete_value(Node **head_ref, int data);

/**
 * @brief Views the value of the the linklist at the specified position
 *
 * @param head_ref The pointer to the head of the linked list
 * @param pos The position (starting from 0) to see the node from
 */
void view(Node *head, int pos);

/**
 * @brief Traverses the entire linked list
 *
 * @param head The head of the linked list
 */
void traverse(Node *head);

/**
 * @brief Makes a new node.
 *
 * @param data Data to be used for nod
 */
Node *make_node(int data);

#endif

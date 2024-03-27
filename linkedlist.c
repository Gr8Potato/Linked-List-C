// DISCLAIMER: I DO NOT SUPPORT PEOPLE PLAGIARIZING MY CODE. I DO NOT TAKE RESPONSIBILITY FOR THE UNLAWFUL ACTIONS OF OTHERS.

/**
 * @date 11/2/2023
 */

/**
 * Error List:
 * 1: Fail to allocate memory
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Node *head = NULL;

// linkedlist.h impl
void append(Node **head_ref, int data)
{
    Node *new = make_node(data);

    if (*head_ref == NULL) // if head points to no node
    {
        *head_ref = new; // make head point to new node
        printf("------------\n%d appended to linked list.\n", data);
        return;
    }

    Node *iter = *head_ref;
    while (iter->next != NULL) // will break out of loop once end of list has been hit (next is NULL)
    {
        iter = iter->next;
    }
    iter->next = new;
    printf("------------\n%d appended to linked list.\n", data);
    return;
}

void add(Node **head_ref, int data, int pos)
{
    Node *new = make_node(data);

    if (pos == 0)
    {
        new->next = *head_ref;
        *head_ref = new;
        printf("------------\n%d added to linked list at position %d.\n", data, pos);
        return;
    }

    Node *iter = *head_ref;
    for (int i = 1; i < pos; i++)
    {
        if (iter->next == NULL)
        {
            printf("------------\nPos is out of bounds. No changes made to linked list.\n");
            return;
        }
        iter = iter->next;
    }
    new->next = iter->next;
    iter->next = new;
    printf("------------\n%d added to linked list at position %d.\n", data, pos);

    return;
}

void delete(Node **head_ref, int pos)
{
    if (*head_ref == NULL)
    {
        printf("------------\nLinked list is empty. No changes have been made.\n");
        return;
    }

    Node *iter = *head_ref;

    if (pos == 0)
    {
        printf("------------\n%d deleted from linked list at position %d.\n", (*head_ref)->data, pos);
        *head_ref = iter->next;
        free(iter);
        return;
    }

    for (int i = 1; i < pos; i++)
    {
        if (iter->next == NULL)
        {
            printf("------------\nPos is out of bounds. No changes made to linked list.\n");
            return;
        }
        iter = iter->next;
    }

    if (iter->next == NULL)
    {
        printf("------------\nPos is out of bounds. No changes made to linked list.\n");
        return;
    }
    Node *next = iter->next;
    printf("------------\n%d deleted from linked list at position %d.\n", next->data, pos);
    if (next != NULL)
    {
        iter->next = next->next;
    }
    free(next);
    return;
}

void delete_value(Node **head_ref, int data)
{
    if (*head_ref == NULL)
    {
        printf("------------\nLinked list is empty. No nodes detected in linked list.\n");
        return;
    }
    int pos = 0;
    char found = 0;
    Node *iter = *head_ref;
    while (iter != NULL)
    {
        if (iter->data == data)
        {
            found++;
            break;
        }
        iter = iter->next;
        pos++;
    }
    if (found)
    {
        delete (head_ref, pos);
    }
    else
    {
        printf("\n------------\nItem was not found. No changes have been made.\n");
    }
    return;
}

void view(Node *head, int pos)
{
    if (head == NULL)
    {
        printf("------------\nLinked list is empty. No nodes detected in linked list.\n");
        return;
    }
    Node *iter = head;
    for (int i = 0; i < pos; i++)
    {
        if (iter->next == NULL)
        {
            printf("------------\nPos is out of bounds.\n");
            return;
        }
        iter = iter->next;
    }
    printf("------------\nContents of node %d: %d\n", pos, iter->data);
    return;
}

void traverse(Node *head)
{
    Node *current = head;
    printf("------------\nCurrent List\n------------\nHEAD -> ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node *make_node(int data)
{
    Node *foo = (Node *)malloc(sizeof(Node));
    if (foo == NULL)
    {
        printf("Failed to allocate memory for a new node.\n");
        exit(1);
    }
    foo->data = data;
    foo->next = NULL;
    return foo;
}

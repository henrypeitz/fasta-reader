#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data[4096];
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    int size;
} LinkedList;

void list_create(LinkedList *list);
Node *ll_push_back(LinkedList *list, const char *buffer);
void ll_print(LinkedList *list);
void ll_free(LinkedList *list);
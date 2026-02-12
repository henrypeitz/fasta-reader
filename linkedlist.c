#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>

void list_create(LinkedList *list)
{
    list->head = NULL;
    list->size = 0;
}

Node *ll_push_back(LinkedList *list, const char *buffer)
{

    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        return NULL;
    }

    strncpy(newNode->data, buffer, 4096);
    newNode->data[4095] = '\0';
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        Node *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    list->size++;

    return newNode;
}

void ll_print(LinkedList *list)
{
    Node *current = list->head;
    int count = 1;
    while (current != NULL)
    {
        printf("GENE %d:\n%s\n\n", count, current->data);
        current = current->next;
        count++;
    }
    printf("--------- YOUR ANALYSIS ENDED HERE ---------\n");
}

void ll_free(LinkedList *list)
{
    Node *current = list->head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    list->head = NULL;
    list->size = 0;

    printf("Freeing some space... \n");
}
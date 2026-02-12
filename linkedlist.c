#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>
#include "func_utils.c"

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
        int len = strlen(current->data);
        printf("ANÁLISE %d:\n", count);

        for (int i = 0; i <= len - 3; i += 3)
        {
            char codon[4];
            codon[0] = current->data[i];
            codon[1] = current->data[i + 1];
            codon[2] = current->data[i + 2];

            codon[3] = '\0';

            const char *name = get_amino_acid(codon);

            printf("%s ", name);
        }
        current = current->next;
        count++;
        printf("\n\n");
    }
    printf("\n");
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

void ll_stats(LinkedList *list)
{
    Node *current = list->head;
    int node_count = 1;

    while (current != NULL)
    {
        long len = strlen(current->data);
        long gc_count = 0;
        long a_count = 0;
        long t_count = 0;
        long others = 0;

        for (int i = 0; i < len; i++)
        {
            char base = current->data[i];

            if (base >= 'a' && base <= 'z')
                base -= 32;

            if (base == 'G' || base == 'C')
                gc_count++;
            else if (base == 'A')
                a_count++;
            else if (base == 'T')
                t_count++;
            else
                others++;
        }

        double gc_percent = (len > 0) ? ((double)gc_count / len) * 100.0 : 0.0;

        printf("--- Stats Node %d ---\n", node_count);
        printf("Length: %ld bp\n", len);
        printf("GC Content: %.2f%%\n", gc_percent);
        printf("Bases: A:%ld C:%ld G:%ld T:%ld N/Other:%ld\n\n",
               a_count, (gc_count - (gc_count / 2)), (gc_count / 2), t_count, others);

        current = current->next;
        node_count++;
    }
}

void ll_complement(LinkedList *list)

{

    Node *current = list->head;
    int count = 0;

    while (current != NULL)
    {
        int len = strlen(current->data);
        printf("ANÁLISE %d:\n", count);

        for (int i = 0; i <= len - 3; i += 3)
        {
            char codon[4];
            codon[0] = get_complement(current->data[i]);
            codon[1] = get_complement(current->data[i + 1]);
            codon[2] = get_complement(current->data[i + 2]);

            codon[3] = '\0';

            printf("%c%c%c ", codon[0], codon[1], codon[2]);
        }
        current = current->next;
        count++;
        printf("\n\n");
    }
    printf("\n");
    printf("--------- YOUR ANALYSIS ENDED HERE ---------\n");
}

void ll_reverse_complement(LinkedList *list)
{
    Node *current = list->head;
    int count = 1;

    while (current != NULL)
    {

        int len = strlen(current->data);
        printf("ANÁLISE %d (Reverse Complement):\n", count);

        int printed_chars = 0;

        for (int i = len - 1; i >= 0; i--)
        {
            char original = current->data[i];
            char rev_comp = get_complement(original);

            printf("%c", rev_comp);
            printed_chars++;

            if (printed_chars % 3 == 0)
            {
                printf(" ");
            }
        }

        printf("\n\n");
        current = current->next;
        count++;
    }
    printf("--------- YOUR ANALYSIS ENDED HERE ---------\n");
}
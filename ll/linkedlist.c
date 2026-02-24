#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>
#include "../utils/func_utils.h"

void list_create(LinkedList *list)
{
    list->head = NULL;
    list->size = 0;
}

Node *ll_push_back(LinkedList *list, const char *buffer, const char *header)
{

    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        return NULL;
    }

    strncpy(newNode->header, header, sizeof(newNode->header) - 1);
    newNode->header[sizeof(newNode->header) - 1] = '\0';

    newNode->data[0] = '\0'; // sequência começa vazia
    newNode->next = NULL;

    if (list->head == NULL)
    {

        // The past solution was something like O(n^2) cuz i did not notice using tail would be more efficient

        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;

    return newNode;
}

void ll_print(LinkedList *list)
{
    printf("\n--------- YOUR ANALYSIS START HERE ---------\n");
    Node *current = list->head;
    int count = 1;
    while (current != NULL)
    {
        int len = strlen(current->data);
        printf("%s\n", current->header);
        printf("ANALYSIS %d:\n", count);

        for (int i = 0; i + 2 < len; i += 3)
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

    printf("The allocated memory was successfully freed. \n");
}

void ll_stats(LinkedList *list)
{
    printf("\n--------- YOUR ANALYSIS START HERE ---------\n");

    Node *current = list->head;
    int node_count = 1;

    while (current != NULL)
    {
        long len = strlen(current->data);
        long g_count = 0;
        long c_count = 0;
        long a_count = 0;
        long t_count = 0;
        long others = 0;

        for (int i = 0; i < len; i++)
        {
            char base = current->data[i];

            if (base >= 'a' && base <= 'z')
                base -= 32;

            if (base == 'G')
                g_count++;
            else if (base == 'C')
                c_count++;
            else if (base == 'A')
                a_count++;
            else if (base == 'T')
                t_count++;
            else
                others++;
        }

        // G and C must be counted in different variables.

        double gc_percent = (len > 0) ? ((double)(g_count + c_count) / len) * 100.0 : 0.0;

        printf("%s\n", current->header);
        printf("--- Stats Node %d ---\n", node_count);
        printf("Length: %ld bp\n", len);
        printf("GC Content: %.2f%%\n", gc_percent);
        printf("Bases: A:%ld C:%ld G:%ld T:%ld N/Other:%ld\n\n",
               a_count, c_count, g_count, t_count, others);

        current = current->next;
        node_count++;
    }

    printf("\n--------- YOUR ANALYSIS END HERE ---------\n");
}

void ll_complement(LinkedList *list)

{
    printf("\n--------- YOUR ANALYSIS START HERE ---------\n");

    Node *current = list->head;
    int count = 0;

    while (current != NULL)
    {
        int len = strlen(current->data);
        printf("%s\n", current->header);
        printf("ANALYSIS %d:\n", count);

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
    printf("\n--------- YOUR ANALYSIS START HERE ---------\n");

    Node *current = list->head;
    int count = 1;

    while (current != NULL)
    {

        int len = strlen(current->data);
        printf("%s\n", current->header);
        printf("ANALYSIS %d (Reverse Complement):\n", count);

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
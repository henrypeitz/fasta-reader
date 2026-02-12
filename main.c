#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.c"

int main()
{
    LinkedList list;
    list_create(&list);

    FILE *p = fopen("teste.fasta", "r");

    if (p == NULL)

    {
        printf("Error opening file\n");
        return 1;
    }

    char buffer[4096];
    unsigned short int read_sequences = 0;
    Node *node = NULL;

    while (fgets(buffer, sizeof(buffer), p) != NULL)
    {

        buffer[strcspn(buffer, "\n")] = '\0';

        if (buffer[0] == '>')
        {
            node = ll_push_back(&list, "");
            read_sequences++;
        }
        else if (node != NULL)
        {
            size_t current_len = strlen(node->data);
            size_t available = 4096 - current_len - 1;

            strncat(node->data, buffer, available);
        }
    }

    // ll_print(&list);
    // ll_stats(&list);
    // ll_complement(&list);
    // ll_reverse_complement(&list);

    ll_free(&list);
    fclose(p);

    return 0;
}
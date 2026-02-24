#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ll/linkedlist.h"

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Error! Wrong usage of the command.");
        printf("Correct Usage: %s example.fasta \n", argv[0]);
        getchar();
        return 1;
    }

    LinkedList list;
    list_create(&list);

    FILE *p = fopen(argv[1], "r");

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
            printf("%s", buffer);
            node = ll_push_back(&list, "", buffer);
            read_sequences++;
        }
        else if (node != NULL)
        {
            size_t current_len = strlen(node->data);
            size_t available = 4096 - current_len - 1;

            strncat(node->data, buffer, available);
        }
    }

    int answer = 1;

    while (answer != 0)
    {
        printf("\n\n\n----------------------------------------------------\n");
        printf("Your file is processed. What you want to do with it?\n");
        printf("1 - Translate the sequence into aminoacids\n");
        printf("2 - Get basic statistcs from the sequences.\n");
        printf("3 - Print the complement of the sequences (A <-> T) and (G <-> C).\n");
        printf("4 - Print the reverse complement of the sequences.\n");
        printf("0 - Exit the program.\n\n");

        scanf("%d", &answer);
        getchar();

        system(CLEAR_SCREEN);

        switch (answer)
        {
        case 1:
            ll_print(&list);
            printf("Press ENTER to return to menu.");
            getchar();
            system(CLEAR_SCREEN);
            break;
        case 2:
            ll_stats(&list);
            printf("Press ENTER to return to menu.");
            getchar();
            system(CLEAR_SCREEN);
            break;
        case 3:
            ll_complement(&list);
            printf("Press ENTER to return to menu.");
            getchar();
            system(CLEAR_SCREEN);
            break;
        case 4:
            ll_reverse_complement(&list);
            printf("Press ENTER to return to menu.");
            getchar();
            system(CLEAR_SCREEN);

            break;
        case 0:
            printf("\nLeaving... \n");
            system(CLEAR_SCREEN);

            break;
        default:
            printf("Please, use only the provided options.");
            system(CLEAR_SCREEN);

            break;
        }
    }

    ll_free(&list);
    fclose(p);

    return 0;
}
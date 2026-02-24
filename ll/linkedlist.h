#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Structs

typedef struct Node
{
    char header[256];
    char data[4096];
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    size_t size;
} LinkedList;

// Functions

/**
 * @brief Creates a new linkedlist.
 *
 * Inputs the initial data inside the LinkedList, setting head to null and size to 0.
 * @param list Pointer to the list that is going to be initialized.
 */
void list_create(LinkedList *list);

/**
 * @brief Inserts a new node in the end of the list.
 *
 * Allocates memory to a new node, copying the buffer content to the data field and adding to the list.
 *
 * @param list Pointer to the list.
 * @param buffer String containing the sequence to be saved.
 *
 * @return Pointer to the new created node
 *         Returns NULL if there is any error during memory allocation.
 */
Node *ll_push_back(LinkedList *list, const char *buffer, const char *header);

/**
 * @brief Translate sequences organized in codons.
 *
 * Runs through every node in the list, dividing the sequence
 * in sets of three and printing the correspondent aminoacid using
 * the get_amino_acid() function.
 *
 * @param list Pointer to the list.
 */
void ll_print(LinkedList *list);

/**
 * @brief Free the allocated memory.
 *
 * Runs through every node freeing the dynamically allocated memory. In the end, defines head as NULL and size as 0.
 *
 * @param list Pointer to the list.
 *
 */
void ll_free(LinkedList *list);

/**
 * @brief Calculate basic statistics of the sequences.
 *
 * For each node, it calculates:
 *  - Sequence length
 *  - GC Content (%)
 *  - Frequency of each base (A, T, G, C)
 *
 * @param list Pointer to the list.
 */
void ll_stats(LinkedList *list);

/**
 * @brief Prints the complement of the sequences.
 *
 * For each saved sequence, it calculates the complement of each
 * base (A <-> T, C<->G) using the get_complement function.
 *
 * @param list Pointer to the list.
 */
void ll_complement(LinkedList *list);

/**
 * @brief Prints the reverse complement of the sequences
 *
 * Runs each sentence from the end to the beggining, printing the complement of each base.
 *
 * @param list Pointer to the list.
 */
void ll_reverse_complement(LinkedList *list);

#endif
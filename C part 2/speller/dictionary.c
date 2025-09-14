// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
// Global variable
unsigned int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char word_copy[LENGTH + 1];
    strcpy(word_copy, word);

    for (int i = 0; word_copy[i]; i++)
    {
        word_copy[i] = tolower(word_copy[i]);
    }

    int index = hash(word_copy);
    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        // check if the word in the node is the same as the word you're looking for
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
    } // end of for loop
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    int length = strlen(word);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value *= 37;
        hash_value += word[i];
    }
    hash_value = hash_value % N;

    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';
    return hash_value;
} // end of hash function

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the dictionary file.
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("failed to open file.");
        return 1;
    }

    // Read words from the dictionary one at a time.
    // You can use the fscanf function for this.
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF) // End Of File
    {
        // For each word, allocate memory for a new node.
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("failed to allocate memeory LINE 69 - 72");
            return false;
        }
        // Copy the word into the node.
        strcpy(new_node->word, word);
        // Hash the word to obtain a hash value.
        int hash_value = hash(word);

        // Insert the node into the hash table
        // at the position indicated by the hash value.
        new_node->next = table[hash_value];
        table[hash_value] = new_node;
        word_count++;

    } // end of load function

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        // node *table(N)
        //  Access the linked list at (node)table[i]
        while (table[i] != NULL)
        {
            node *temp = table[i]->next;
            free(table[i]);
            table[i] = temp;
        }
    }
    // TODO
    return true;
}

// Saves popular dog names in a trie
// https://www.dailypaws.com/dogs-puppies/dog-names/common-dog-names

// #include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ALPHABET 26
#define MAXCHAR 20

typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABET]; // 26
} node;

// Function prototypes
bool check(char *word);
bool unload(void);
void unloader(node *current);

// Root of trie
node *root;

// Buffer to read dog names into
char name[MAXCHAR]; // 20

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./trie infile\n");
        return 1;
    }

    // File with names
    FILE *infile = fopen(argv[1], "r");
    if (!infile)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Allocate root of trie
    root = malloc(sizeof(node));

    if (root == NULL)
    {
        return 1;
    }

    root->is_word = false;
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        root->children[i] = NULL;
    }

    // Add words to the trie
    while (fscanf(infile, "%s", name) == 1)
    {
        node *cursor = root;

        for (int i = 0, n = strlen(name); i < n; i++)
        {
            int index = tolower(name[i]) - 'a';
            if (cursor->children[index] == NULL)
            {

                // Make node
                node *new = malloc(sizeof(node));
                new->is_word = false;
                for (int j = 0; j < SIZE_OF_ALPHABET; j++)
                {
                    new->children[j] = NULL;
                }
                cursor->children[index] = new;
            }

            // Go to node which we may have just been made
            cursor = cursor->children[index];
        }

        // if we are at the end of the word, mark it as being a word
        cursor->is_word = true;
    }

    char word[MAXCHAR + 1];
    printf("Check word: ");
    fgets(word, MAXCHAR + 1, stdin);

    if (check(word))
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found.\n");
    }
    if (!unload())
    {
        printf("Problem freeing memory!");
        return 1;
    }

    fclose(infile);
}

// TODO: Complete the check function, return true if found, false if not found
bool check(char *word)
{

    node *temp = root; // start at the root
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (!isalpha(word[i]))
        {
            continue;
        }

        // navigate to the child node that corresponds to the character
        int index = tolower(word[i]) - 'a';
        temp = temp->children[index];

        if (temp == NULL)
        {
            // the word is not in the trie
            return false;
        }
    }
    // after iterating over the word, check if it's a valid word
    if (temp->is_word == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Unload trie from memory
bool unload(void)
{

    // The recursive function handles all of the freeing
    unloader(root);

    return true;
}

void unloader(node *current)
{

    // Iterate over all the children to see if they point to anything and go
    // there if they do point
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        if (current->children[i] != NULL)
        {
            unloader(current->children[i]);
        }
    }

    // After we check all the children point to null we can get rid of the node
    // and return to the previous iteration of this function.
    free(current);
}

/*
Imagine you just rescued a dog and you’re deciding on a name.
 You found a file online with a list of about 150
 of the most popular dog names!
 You are curious as to whether or not the names you
 are considering are on this list.
 Since trie’s are great for data lookups,
 we’ve given you some (almost!) complete code in trie.c.
There is one function,
check,
 which is not yet implemented.
Your job is to complete this function.


Notice that the trie itself is implemented through the creative use of several structs called node.
 Each node in a trie has an array of (potential) children,
 with size 26—one potential child for each letter of the alphabet!
 Adding words to this trie, notice that—for every letter in
 a word—we create a new node child whose parent is either
 the root node (for the first letter) or the previous letter
  (if not the first letter). On the very last letter,
  we set the is_word attribute of the child node to true.
  Now, checking if a word is in our trie is as easy as following each letter
  of that word through our trie.
  If we get to the final letter and see that is_word is true,
  well, that name is in our trie!

Hints
You probably want to start by setting a node pointer, cursor to the root of the trie.
Iterate through every letter in the argument word and, as you do, determine the array index that
corresponds to that letter. You can use the index for a letter to check if children[index] is a NULL
pointer, meaning the word does not exist in the trie. If children[index] is in fact a node, you can
reset cursor to this node and check for the next letter in its children nodes. Remember that the
lookup should be case-insensitive. For instance, A and a should correspond to 0, B and b corresponds
to 1, etc. When might you want to use a trie as a data structure? When might you not?
*/

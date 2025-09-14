#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

typedef struct node
{
    char *phrase;
    struct node *next;
}
node;
node *table[26]; //a-z

int hash(char *phrase);
bool unload(node *list);
void visualizer(node *list);


int main(void)
{
    //Add items
    for(int i = 0; i < 3; i++)
    {
        char phrase[100]; //or any size you want
        printf("enter a new phrase: ");
        fgets(phrase,sizeof(phrase),stdin);

        //find phrase bucket
        int bucket = hash(phrase);
        printf("%s hash to %i\n", phrase, bucket);

    }

}


//TDOD return the correct bucket for a given phrase
int hash(char *phrase)
{

    return toupper(phrase[0]) - 'A';
    //return tolower(phrase[0]) -'a';
}

bool unload(node *list)
{
    node *ptr = list;
    while(ptr != NULL)
    {
        ptr = list->next;
        free(list);
        list = ptr;
    }
    return true;
}

void visualizer(node *list)
{
    printf("\n+-- List Visualizer --+\n\n");
    while (list != NULL)
    {
        printf("Location %p\nPhrase: \"%s\"\nNext: %p\n\n", list, list->phrase, list->next);
        list = list->next;
    }
    printf("+---------------------+\n\n");
}

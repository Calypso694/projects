// simulate genetic inheritance or blood type
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generations);
void free_family(person *p);
char random_allele();

int main(void)
{
    // seed random number generator
    srand(time(0));

    // create a new family with 3 generations
    person *p = create_family(GENERATIONS);

    // print family tree of blood types
    print_family(p, 0);

    // free memory
    free_family(p);
}

// create a new individual with 'generations'
person *create_family(int generations)
{
    // TODO Allocate memeory for new person
    person *new_person = malloc(sizeof(person));

    if (new_person == NULL)
    {
        printf("Trouble with malloc of new person LINE 39\n");
        return NULL;
    }

    // if there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // TODO Set parent pointers for current person
        new_person->parents[0] = parent0;
        new_person->parents[1] = parent1;

        // TODO Randomly assighn curent persons alleles based on alleles of their parents
        new_person->alleles[0] = parent0->alleles[rand() % 2];
        new_person->alleles[1] = parent1->alleles[rand() % 2];
    }

    // If there are no generations left to create
    else
    {
        // TODOD Set parents pointers to NULL
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;
        // TODOD Randomly assign alleles
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }
    // TODO Return newly created person
    return new_person;
}

// print family member and their alleles
void print_family(person *p, int generations)
{
    // handle base case
    if (p->parents[0] || p->parents[1] == NULL)
    {
        return;
    }

    // print indentation
    for (int i = 0; i < generations * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // print person
    if (generations == 0)
    {
        printf("Child(Generations %i): blood type %c%c\n", generations, p->alleles[0],
               p->alleles[1]);
    }
    else if (generations == 1)
    {
        printf("Parent(Generations %i): blood type %c%c\n", generations, p->alleles[0],
               p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generations - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparents(Generations %i): blood type %c%c\n", generations, p->alleles[0],
               p->alleles[1]);
    }

    // print parents of current generation
    print_family(p->parents[0], generations + 1);
    print_family(p->parents[1], generations + 1);
}


// free p and all ancestors of p
void free_family(person *p)
{
    // TODO handle base case
    if (p == NULL)
    {
        return;
    }
    // TODO  free parents recursivly

    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // free children
    //  Free the person themselves
    free(p);
}


// randomly chooses a bloodtype
char random_allele()
{
    int r = rand() & 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return '0';
    }
}

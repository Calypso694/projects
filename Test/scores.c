#include<stdio.h>

const int N = 3;

float average(int length, int array[]);

int main(void)
{
    printf("Enter 3 Scores to get the Average.\n"); 
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        int scores[i];
        printf("Scores: "); 
        scanf("%i",scores); 
        }
    printf ("Average:%f\n ",average(N,scores)/3.0);
}


float average(int length, int array[])
{
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum = sum + array[i];
    }
    return sum / (float)N;
}



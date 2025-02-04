#include<stdio.h>

int main(void)
{
    int a = 0; 
    int b = 1; 

for (int i = 0; i < 13; i++)
{
    printf("%i",a); 
    int temp_a = a; 
    a = b; 
    b = temp_a + b; 
}
    return 0; 
}

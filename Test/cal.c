#include<stdio.h>

int main(void)
{
    long x;
    printf("x: ");
    scanf("%li",&x); 
    long y;
    printf("y: ");
    scanf("%li",&y); 

    double z = (double)x / (double)y; //type casting

     printf("%.20f\n",z); //floating point imprs
     return 0; 
}

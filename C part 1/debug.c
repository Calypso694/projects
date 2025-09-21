// Become familiar wih C syntax
// Learn to debug buggy code
#include<stdio.h>
#include<stdlib.h> 

int main(void)
{
    // Ask for your name and where live, then print it out
   char name[50]; 
   char location[50];

   printf("What is your name?\n"); 
   printf("input your name: "); 
   scanf("%s",name); 
   printf("What is your location?\n"); 
   printf("input your location: "); 
   scanf("%s",location); 


   printf("Hello, %s welcome to %s !",name, location);
}
   

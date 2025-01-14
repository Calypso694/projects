#include<cs50.h>
#include<stdio.h>

int main(int argc, string argv[])
{
   //printf("What is your name: ");

   // char *name
   //printf("hello, %s\n", name);



   if(argc != 2)
   {
      printf("Missing Command Line Argument\n");
      return 1;
   }
   else
   {
      printf("hello, %s\n", argv[1]);
      return 0;
   }


}

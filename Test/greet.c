#include<stdio.h>

int main(int argc,char *argv[])
{
   printf("What is your name: ");
   char name[20]; 
   scanf("%19s",name);

   if(argc != 2)
   {
      printf("Missing Command Line Argument\n");
      return 1;
   }
   else
   {
      printf("hello,d%s\n", name);
      return 0;
   }
}

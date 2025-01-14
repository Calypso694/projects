// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

string replace(string user_string);

int main(int argc, string argv[])
{
/*

Your program must accept a single command-line argument,
which will be the word that you want to convert.

If your program is executed without any command-line arguments
or with more than one command-line argument,
 your program should print an error message of your choice (with printf)
 and return from main a value of 1 (which tends to signify an error) immediately.

Your program must contain a function called REPLACE
which takes a string input and returns a string output.

This function will change the following vowels to numbers:
a becomes 6, e becomes 3, i becomes 1, o becomes 0 and u does not change.

The input parameter for the replace function will be argv[1]
and the return value is the converted word.

The main function will then print the converted word, followed by \n.
You may want to try using the switch statement in your replace function.
*/
if( argc != 2) //echo $?
{
    printf("Usage ./no-vowels word.\n");
}

    printf("%s\n",replace(argv[1]));
    return 0;


}

string replace(string user_string)
{
     int length = strlen(user_string);
    for(int i = 0; i <length; i++)
    {
      switch(user_string[i]) //string length[i]
      {
        case 'a': user_string[i] = 54; //ASCII 6 HEX;
        break;

        case 'e': user_string[i] = 51; //ASCII 3 HEX;
        break;

        case 'i': user_string[i] = 49; //ASCII 1 HEX
        break;

        case 'o': user_string[i] = 48; //ASCII 0 NULL HEX
        break;
      }
    }
    return user_string;

}





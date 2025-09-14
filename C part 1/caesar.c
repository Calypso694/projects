//#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

//run ./caesar 1(or whatever number you would like) after you type your Key, ENTER, then your password and a final enter.
//program does not include shifting numbers. That is in Password.c in Practice. 

// Make sure program was run with just one command-line argument

// Make sure every character in argv[1] is a digit

// Convert argv[1] from a `string` to an `int`

// Prompt user for plaintext

// For each character in the plaintext:

// Rotate the character if it's a letter

bool only_digits(char *s);

int cipher_formula(int k, char *s);

int main(int argc, char *argv[])
{
    if (argc != 2) // echo $?
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (!only_digits(argv[1]))
    {
        return 1;
    }
    else
        (only_digits(argv[1]));
    {
        int k = atoi(argv[1]);
        char Plaintext[100]; // or however large you need
        fgets(Plaintext, sizeof(Plaintext), stdin);
        cipher_formula(k, Plaintext);
    }
    return 0;
}
/*


Your program must accept a single command-line argument,
a non-negative integer.
Let’s call it K for the sake of discussion.

If your program is executed without any command-line arguments
or with more than one command-line argument,
your program should print an error message of your choice
(with printf) and return from main a value of 1
(which tends to signify an error) immediately.

If any of the characters of the command-line argument
is not a decimal digit,
your program should print the message
Usage: ./caesar key and return from main a value of 1.

Do not assume that K
will be less than or equal to 26.
Your program should work for all non-negative integral values of K
less than 2(31) - 26.

In other words,
you don’t need to worry if your program eventually breaks
if the user chooses a value for K
that’s too big or almost too big to fit in an int.

(Recall that an int can overflow.)

But, even if K is greater than 26
alphabetical characters in your program’s
input should remain alphabetical characters in your program’s output.
For instance, if K is 27
'A' should not become B even though B is 27
 positions away from A in ASCII,
 per asciitable.com;

 A should become B, since B is 27 positions away from A,
 provided you wrap around from Z to A.

Your program must output plaintext:
(with two spaces but without a newline)
and then prompt the user for a string of plaintext
(using get_string).

Your program must output ciphertext:
(with one space but without a newline)
followed by the plaintext’s corresponding ciphertext,
with each alphabetical character in the plaintext
“rotated” by k positions;
non-alphabetical characters should be outputted unchanged.

Your program must preserve case:
capitalized letters, though rotated,
must remain capitalized letters;
lowercase letters, though rotated,
 must remain lowercase letters.

After outputting ciphertext,
you should print a newline.
Your program should then exit by returning 0 from main.
*/

bool only_digits(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
        {
            printf("Key must be a digit.\n");
            return 0;
            // Handle non-digit character
        }
    }
    return 1;
}

int cipher_formula(int k, char *s)
{
    for (int i = 0, n = strlen(s); i < n; i++) // your plaintext
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                // apply the formula for uppercase letters
                s[i] = (s[i] - 'A' + k) % 26 + 'A';
            }
            else
            {
                // apply the formula for lowercase letters
                s[i] = (s[i] - 'a' + k) % 26 + 'a';
            }
        }
    }
    printf("ciphertext: %s\n", s);
    return 0;
}

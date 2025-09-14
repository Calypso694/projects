// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

//#include<cs50.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>


bool valid(char *password);


struct counters
{
 int digit_counter;
 int case_counter;
 int spec_counter;
};


int main(void)
{
    char password[100]; // or however large you would like
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(char password)
{

struct counters counters;
counters.digit_counter = 0;
counters.case_counter = 0;
counters.spec_counter = 0;

for (int i = 0; i < strlen(password); i++)
{
    if (isdigit(password[i]))
    {
        counters.digit_counter++; // increment counter when a digit is found
    }

      if(isupper(password[i]) || islower(password[i]))
    {
        counters.case_counter++;
    }
   if (strchr("!@#$^&*?", password[i]))
{
    counters.spec_counter++;
}

}

 if (counters.digit_counter >= 1 && counters.case_counter >= 1 && counters.spec_counter >=1)
{
    return true;
}
else
{
    return false;
}
}











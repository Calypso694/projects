#include<cs50.h>
#include<string.h>
#include<stdio.h>

void draw(int n);
string findBinary(int decimal, string result);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);

    int value = get_int("Value: ");
    draw(value);

    string binary =  findBinary(233,"");

    return 0;
}

void draw(int n)
{
    if(n <= 0)
    {
        return;
    }
    draw(n-1); //print pyramid of n - 1

    //print one more row
    for(int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");

}


string findBinary(int decimal, string result)
{
    if(decimal == 0)
    {
        return result;
    }
    result = decimal % 2 + result;
    return findBinary(decimal/2,result);
}

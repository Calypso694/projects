#include<cs50.h>
#include<stdio.h>

 void set_array(int array[4]);
 void set_int(int x);

int main(void)
    {
      //arrays can not change

   //instantiation syntax, dont need  to declare size of array.
  //  bool truthtable[3](true,false,false);
    //individiual element syntax

  //  bool truthtable[3];
  //  truthtable[0];
  //  truthtable[1];
  //  truthtable[3];

   // int foo[5](1,2,3,4,5);
  //  int bar[5];
  //  for(int j = 0; j < 5; j++)
   // {
    //    bar[j] = foo[j];
  //  }



    int x = 10;
    int b[4] = {0,1,2,3};
    set_int(a);
    set_array(b);
    printf("%d %d", a, b[0]);

    }

    void set_array(int array[4])
    {
        array[0]=22;
    }
    void set_int(int x)
    {
        int x = 22;
    }
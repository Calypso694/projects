#include<cs50.h>
#include<stdio.h>


int get_size(void);
void print_grid(int size);


int main(void)
{
    int height = get_size();
    print_grid(height);

}



//size
 int get_size(void)
  {
     int height;
   do
   {
        height = get_int("size: ");
   }
   while(height < 1);
   return height;
  }


    //grid row,colum,end
  void print_grid(int size)
  {//row
    for(int row = 0; row < size; row++)
    { //column
        for(int column = 0; column < row; column++)
      {
        printf("#");
      }
      //end
      printf("#\n");
    }
  }

#include<stdio.h>

/*
Find the middle item of the array.
If the middle item is the target value, return the index.
If the target value is less than the middle item,
repeat the search with the left half of the array.
If the target value is greater than the middle item,
repeat the search with the right half of the array.
If the array does not contain the target value,
return -1 or some other value that indicates failure.
*/

//middle = low +(high-low) / 2;


//function that does binary search.
int binary_search(int arr[],int left, int right, int center);

int main(void)
{
    int arr[] = {0,1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int center = 4;

    int result = binary_search(arr, 0, n - 1, center);
    (result == -1) ? printf("Element is not present in array.\n")
                   : printf("Element is present at index[%d]\n",result);




    return 0;
}

//iterative binary search function
int binary_search(int arr[],int left, int right, int center)
{
 while(left <= right)
 {
    //algorithm
    int middle = left +(right - left) / 2;

    //check if left is present at center.
    if(arr[middle] == center)
    return middle;

    //if center is greater ignore left half.
    if(arr[middle] < left)
    left = middle + 1;

    //if center is smaller, ignore right half.
    else
    right = middle - 1;
 }
 //if we reach here element was not present.
 return -1;

}

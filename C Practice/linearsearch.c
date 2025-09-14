#include <stdio.h>
// Program to implement Linear Search

// Liear Search function that search the key in arr
int linear_search(int *arr, int size, int key);

int main(void)
{
    int arr[10] = {3, 2, 6, 5, 9, 10, 7, 4, 8, 1}; // 0 indexed 3 == 0, 2 == 1 etc.
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 4;

    // calling linear search
    int index = linear_search(arr, size, key);

    // printing result bases of value returned by linear_search()
    if (index == -1)
    {
        printf("The element is not present in arr.\n");
    }
    else
    {
        printf("The element is present at[%d].\n", index);
    }
    return 0;
}

// Liear Search function that search the key in arr
int linear_search(int *arr, int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

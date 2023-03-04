#include <stdio.h>
#include <stdlib.h>

/**
 * @brief binary search using recursion
 * @author Obaydur Rahman (213902018) <obayed.opu@gmail.com>
 * @date 2022-06-28 (21:53)
 *
 * @returns int
 */

int binary_search(int *array, int size, int value);

int main()
{
    int size, value, *array;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    array = (int *)calloc(sizeof(int), size);
    printf("Enter the values of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter the value to search: ");
    scanf("%d", &value);
    int result = binary_search(array, size, value);
    if (result == -1)
    {
        printf("Value not found\n");
    }
    else
    {
        printf("Value found at index %d\n", result);
    }
    return 0;
}

int binary_search(int *array, int size, int value)
{
    int mid = size / 2;
    if (size == 0)
    {
        return -1;
    }
    else if (array[mid] == value)
    {
        return mid;
    }
    else if (array[mid] > value)
    {
        return binary_search(array, mid, value);
    }
    else
    {
        return binary_search(array + mid + 1, size - mid - 1, value);
    }
}
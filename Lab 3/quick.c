#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Quick sort
 * @author Obaydur Rahman (213902018) <obayed.opu@gmail.com>
 * @date 2022-07-24 (21:13)
 *
 * @returns int
 */

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int low, int high)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    while (1)
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i >= j)
        {
            return j;
        }
        swap(&a[i], &a[j]);
    }
}

int quickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(a, low, high);
        quickSort(a, low, pivot);
        quickSort(a, pivot + 1, high);
    }
}

int main()
{
    int i, j, k, n, temp, pivot;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quickSort(a, 0, n - 1);
    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
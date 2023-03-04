#include <stdio.h>
#include <stdlib.h>
#define ENTRIES 10

/**
 * @brief insert, remove, and search an element in an array
 * @author Obaydur Rahman (213902018) <obayed.opu@gmail.com>
 * @date 2022-06-21 (12:32)
 *
 * @compiler GNU GCC 9.3.0
 * @build gcc main.c -o main
 *
 * @returns int
 */

void print_array(int *array, int size);

int main()
{
    int option, position, value;
    // allocate memory for array (1 more than the number of entries)
    int *array = (int *)calloc(sizeof(int) * (ENTRIES + 1), (ENTRIES + 1)); // 84 bytes

    // insert values into array (0 to ENTRIES)
    for (int i = 0; i <= ENTRIES; i++)
    {
        array[i] = i;
    }

    printf("Choose an option:\n");
    printf("1. Insert\n");
    printf("2. Replace\n");
    printf("3. Remove by index\n");
    printf("4. Remove by value\n");
    printf("5. Search\n");

    printf("\nEnter your option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("\nEnter the index: ");
        scanf("%d", &position);
        printf("Enter the value: ");
        scanf("%d", &value);

        printf("Old: ");
        print_array(array, ENTRIES);

        // shift array to the right
        for (int i = ENTRIES; i >= position; i--)
        {
            array[i + 1] = array[i];
        }

        // insert value at position
        array[position] = value;

        printf("New: ");
        print_array(array, ENTRIES + 1);

        break;
    case 2:
        printf("\nEnter the index: ");
        scanf("%d", &position);
        printf("Enter the value: ");
        scanf("%d", &value);

        printf("Old: ");
        print_array(array, ENTRIES);

        // replace value at position
        array[position] = value;

        printf("New: ");
        print_array(array, ENTRIES);

        break;
    case 3:
        printf("\nEnter index to remove: ");
        scanf("%d", &position);

        printf("Old: ");
        print_array(array, ENTRIES);

        // shift array to the left
        for (int i = position; i < ENTRIES; i++)
        {
            array[i] = array[i + 1];
        }

        printf("New: ");
        print_array(array, ENTRIES - 1);

        break;
    case 4:
        printf("\nEnter value to remove: ");
        scanf("%d", &value);

        printf("Old: ");
        print_array(array, ENTRIES);

        // remove value from array
        for (int i = 0; i < ENTRIES; i++)
        {
            if (array[i] == value)
            {
                for (int j = i; j < ENTRIES; j++)
                {
                    array[j] = array[j + 1];
                }
                break;
            }
        }

        printf("New: ");
        print_array(array, ENTRIES - 1);
        break;
    case 5:
        printf("\nEnter value to search: ");
        scanf("%d", &value);

        printf("Array:  ");
        print_array(array, ENTRIES);

        // search value in array
        for (int i = 0; i < ENTRIES; i++)
        {
            if (array[i] == value)
            {
                printf("Result: [ %d => %d ]\n", i, value);
                break;
            }
            else if (i == ENTRIES - 1)
            {
                printf("Value not found\n");
            }
        }
        break;
    default:
        printf("Invalid option\n");
        break;
    }

    return 0;
}

void print_array(int *array, int size)
{
    // in this format [ 0 => 1, 1 => 2 ]
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d => %d", i, array[i]);
        // add comma if not last element
        if (i != size - 1)
        {
            printf(", ");
        }
        else
        {
            printf(" ");
        }
    }
    printf("]\n");
}
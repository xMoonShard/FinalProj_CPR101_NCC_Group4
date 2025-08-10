#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fundamentals.h"

#define SIZE 256

int findIndex(const char *str, char target)
{
    if (!str)
        return -1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == target)
            return i;
    }
    return -1;
}

int measureLength(const char *str)
/*Added NULL pointer checks to prevent crashes when the function receives invalid inputs.
Also tested with long strings to ensure proper length calculation without overflow. */
{
    // Check for NULL pointer before processing
    if (str == NULL)
        return 0;

    int count = 0;
    while (str[count] != '\0')
        count++;

    return count;
}

void copyString(char *dest, const char *src, int max)
{
    if (!dest || !src || max <= 0)
        return;
    int i = 0;
    while (src[i] && i < max - 1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void fundamentals(void)
{
    char str1[SIZE];
    char str2[SIZE];
    char result[SIZE];
    int index;
    char choice[SIZE];

    do
    {
        printf("\n=== Fundamentals Menu ===\n");
        printf("1. Measure String Length\n");
        printf("2. Index Character in String\n");
        printf("3. Copy String\n");
        printf("0. Quit fundamentals\n\n");
        printf("Enter your choice: ");
        fgets(choice, SIZE, stdin);
        choice[strcspn(choice, "\n")] = '\0';

        if (strcmp(choice, "1") == 0)
        {
            printf("\n--- Measuring String ---\n");
            while (1)
            {
                printf("Enter a word (0 to return to menu): ");
                fgets(str1, SIZE, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                if (strcmp(str1, "0") == 0)
                    break;

                printf("Length: %d\n", measureLength(str1));
            }
        }
        else if (strcmp(choice, "2") == 0)
        {
            printf("\n--- Indexing String ---\n");
            while (1)
            {
                printf("Enter a word (0 to return to menu): ");
                fgets(str2, SIZE, stdin);
                str2[strcspn(str2, "\n")] = '\0';
                if (strcmp(str2, "0") == 0)
                    break;

                printf("Enter an index: ");
                char idx[SIZE];
                fgets(idx, SIZE, stdin);
                index = atoi(idx);

                if (index >= 0 && index < measureLength(str2))
                {
                    printf("Char at %d is '%c'\n", index, str2[index]);
                }
                else
                {
                    printf("Index out of range.\n");
                }
            }
        }
        else if (strcmp(choice, "3") == 0)
        {
            printf("\n--- Copying String ---\n");
            while (1)
            {
                printf("Enter a string to copy (0 to return to menu): ");
                fgets(str1, SIZE, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                if (strcmp(str1, "0") == 0)
                    break;

                copyString(result, str1, SIZE);
                printf("Copied: %s\n", result);
            }
        }
        else if (strcmp(choice, "0") != 0)
        {
            printf("Invalid choice. Try again.\n");
        }

    } while (strcmp(choice, "0") != 0);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manipulating.h"
#include "fundamentals.h"

#define SIZE 256

void concatenate(char *dest, const char *src, int max)
{
    int i = 0;
    while (dest[i] && i < max - 1)
        i++;
    int j = 0;
    while (src[j] && i < max - 1)
    {
        dest[i++] = src[j++];
    }
    dest[i] = '\0';
}

int compareStrings(const char *str1, const char *str2)
{
    // Check if either string is NULL
    if (str1 == NULL && str2 == NULL)
        return 0; // Both are NULL, so treat as equal
    else if (str1 == NULL)
        return -1; // If first is NULL, say it's smaller
    else if (str2 == NULL)
        return 1; // If second is NULL, say first is bigger

    // Compare characters one by one
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    // Return difference of the first unmatched character
    return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

int searchSubstring(const char *haystack, const char *needle)
{
    int len1 = measureLength(haystack);
    int len2 = measureLength(needle);
    for (int i = 0; i <= len1 - len2; i++)
    {
        int match = 1;
        for (int j = 0; j < len2; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                match = 0;
                break;
            }
        }
        if (match)
            return i;
    }
    return -1;
}

void manipulating(void)
{
    char word1[SIZE];
    char word2[SIZE];
    char result[SIZE * 2];
    char choice[SIZE];

    do
    {
        printf("\n=== Manipulating Menu ===\n");
        printf("1. Concatenate strings\n");
        printf("2. Compare strings\n");
        printf("3. Search substring\n");
        printf("0. Quit manipulating\n\n");
        printf("Enter your choice: ");
        fgets(choice, SIZE, stdin);
        choice[strcspn(choice, "\n")] = '\0';

        if (strcmp(choice, "1") == 0)
        {
            printf("\n--- Concatenating Strings ---\n");
            while (1)
            {
                result[0] = '\0';
                printf("Enter first string (0 to return to menu): ");
                fgets(word1, SIZE, stdin);
                word1[strcspn(word1, "\n")] = '\0';
                if (strcmp(word1, "0") == 0)
                    break;

                printf("Enter second string: ");
                fgets(word2, SIZE, stdin);
                word2[strcspn(word2, "\n")] = '\0';

                copyString(result, word1, SIZE * 2);
                concatenate(result, word2, SIZE * 2);
                printf("Combined: %s\n", result);
            }
        }
        else if (strcmp(choice, "2") == 0)
        {
            printf("\n--- Comparing Strings ---\n");
            while (1)
            {
                printf("Enter first string (0 to return to menu): ");
                fgets(word1, SIZE, stdin);
                word1[strcspn(word1, "\n")] = '\0';
                if (strcmp(word1, "0") == 0)
                    break;

                printf("Enter second string: ");
                fgets(word2, SIZE, stdin);
                word2[strcspn(word2, "\n")] = '\0';

                int res = compareStrings(word1, word2);
                if (res == 0)
                    printf("They are the same.\n");
                else if (res < 0)
                    printf("'%s' comes before '%s'\n", word1, word2);
                else
                    printf("'%s' comes after '%s'\n", word1, word2);
            }
        }
        else if (strcmp(choice, "3") == 0)
        {
            printf("\n--- Searching Substring ---\n");
            while (1)
            {
                printf("Enter main string (0 to return to menu): ");
                fgets(word1, SIZE, stdin);
                word1[strcspn(word1, "\n")] = '\0';
                if (strcmp(word1, "0") == 0)
                    break;

                printf("Enter word to find: ");
                fgets(word2, SIZE, stdin);
                word2[strcspn(word2, "\n")] = '\0';

                int pos = searchSubstring(word1, word2);
                if (pos >= 0)
                    printf("Found at index %d\n", pos);
                else
                    printf("Not found.\n");
            }
        }
        else if (strcmp(choice, "0") != 0)
        {
            printf("Invalid choice. Try again.\n");
        }

    } while (strcmp(choice, "0") != 0);
}
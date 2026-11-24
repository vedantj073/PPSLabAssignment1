#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100], temp[200];
    int choice;

    printf("Enter first string (no spaces): ");
    scanf("%s", s1);
    printf("Enter second string (no spaces): ");
    scanf("%s", s2);

    do {
        printf("\n===== STRING OPERATIONS MENU =====\n");
        printf("1. Length (strlen)\n");
        printf("2. Copy (strcpy)\n");
        printf("3. Concatenate (strcat)\n");
        printf("4. Compare (strcmp)\n");
        printf("5. Find a character (strchr)\n");
        printf("6. Find a substring (strstr)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Length of '%s' = %lu\n", s1, strlen(s1));
                break;

            case 2:
                strcpy(temp, s1);
                printf("Copied string: %s\n", temp);
                break;

            case 3:
                strcpy(temp, s1);
                strcat(temp, s2);
                printf("Concatenated string: %s\n", temp);
                break;

            case 4:
                if (strcmp(s1, s2) == 0)
                    printf("Strings are equal\n");
                else
                    printf("Strings are NOT equal\n");
                break;

            case 5: {
                char ch;
                printf("Enter character to find: ");
                scanf(" %c", &ch);
                char *p = strchr(s1, ch);
                if (p != NULL)
                    printf("'%c' found at position %ld\n", ch, p - s1);
                else
                    printf("'%c' not found\n", ch);
                break;
            }

            case 6:
                if (strstr(s1, s2) != NULL)
                    printf("'%s' is present in '%s'\n", s2, s1);
                else
                    printf("'%s' is NOT present in '%s'\n", s2, s1);
                break;

            case 0:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 0);

    return 0;
}
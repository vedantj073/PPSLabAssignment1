#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *src, *dest;
    char srcName[100], destName[100];
    int ch;

    printf("Enter source file name: ");
    scanf("%s", srcName);

    printf("Enter destination file name: ");
    scanf("%s", destName);

    /* Open source file for reading */
    src = fopen(srcName, "r");
    if (src == NULL)
    {
        printf("Error: Cannot open source file %s\n", srcName);
        exit(1);
    }

    /* Open destination file for writing */
    dest = fopen(destName, "w");
    if (dest == NULL)
    {
        printf("Error: Cannot open destination file %s\n", destName);
        fclose(src);
        exit(1);
    }

    /* Copy character by character until EOF */
    while ((ch = fgetc(src)) != EOF)
    {
        fputc(ch, dest);
    }

    printf("File copied successfully.\n");

    fclose(src);
    fclose(dest);

    return 0;
}
#include <stdio.h>

/* Receives the ADDRESSES of two variables (call by reference) */
void swap(int *a, int *b)
{
    int temp;
    temp = *a;   /* save value stored at address a */
    *a = *b;     /* put value of b into a's location */
    *b = temp;   /* put saved value into b's location */
}

int main()
{
    int x, y;

    printf("Enter the first number: ");
    scanf("%d", &x);
    printf("Enter the second number: ");
    scanf("%d", &y);

    printf("\nBefore Swapping:\n");
    printf("First number=%d, Second number=%d\n", x, y);

    swap(&x, &y);   /* pass addresses using & */

    printf("\nAfter Swapping:\n");
    printf("First number=%d, Second number=%d\n", x, y);

    return 0;
}
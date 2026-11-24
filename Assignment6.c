#include <stdio.h>

// Without recursion (using a loop)
int factIter(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++)
        f = f * i;
    return f;
}

// With recursion (function calls itself)
int factRec(int n) {
    if (n == 0 || n == 1)   // base case
        return 1;
    return n * factRec(n - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factorial (without recursion) = %d\n", factIter(num));
    printf("Factorial (with recursion)    = %d\n", factRec(num));
    return 0;
}
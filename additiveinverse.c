#include <stdio.h>

// Function to find the additive inverse of a number modulo n
int additive_inverse(int a, int n) {
    return (n - a % n) % n;
}

int main() {
    int number, n;

    // Input number and n
    printf("Enter the number: ");
    scanf("%d", &number);

    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Calculate the additive inverse
    int result = additive_inverse(number, n);

    // Output the result
    printf("The additive inverse of %d modulo %d is: %d\n", number, n, result);

    return 0;
}

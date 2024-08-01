#include <stdio.h>

// Function to find the GCD of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Calculate the GCD
    int result = gcd(num1, num2);

    // Output the result
    printf("The GCD of %d and %d is: %d\n", num1, num2, result);

    return 0;
}

#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) return 0; // 0 and 1 are not prime numbers
    if (n <= 3) return 1; // 2 and 3 are prime numbers

    if (n % 2 == 0 || n % 3 == 0) return 0; // Check if divisible by 2 or 3

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0; // Check divisibility
    }

    return 1; // Number is prime
}

int main() {
    int number;

    // Input number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Check if the number is prime
    if (is_prime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}

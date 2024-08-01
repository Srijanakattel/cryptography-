#include <stdio.h>

// Function to compute Euler's Totient Function
int euler_totient(int n) {
    int result = n; // Initialize result as n
    for (int p = 2; p * p <= n; p++) {
        // Check if p is a prime factor of n
        if (n % p == 0) {
            // If yes, then update n and result
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    // If n has a prime factor greater than sqrt(n)
    // (There can be at most one such prime factor)
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

int main() {
    int n;

    // Input an integer n
    printf("Enter an integer n: ");
    scanf("%d", &n);

    // Calculate the Euler's Totient Function value
    int result = euler_totient(n);

    // Output the result
    printf("Euler's Totient Function φ(%d) is: %d\n", n, result);

    return 0;
}

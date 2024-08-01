#include <stdio.h>
#include <stdbool.h>

// Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute (base^exp) % mod using modular exponentiation
int power_mod(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to check if 'g' is a primitive root modulo 'n'
bool is_primitive_root(int g, int n) {
    int phi = n - 1; // For prime n, phi(n) = n-1
    bool used[n];
    for (int i = 0; i < n; i++) {
        used[i] = false;
    }

    for (int i = 0; i < phi; i++) {
        int val = power_mod(g, i, n);
        if (used[val]) {
            return false; // If val is repeated, g is not a primitive root
        }
        used[val] = true;
    }
    return true;
}

// Function to find a primitive root modulo n
int find_primitive_root(int n) {
    for (int g = 2; g < n; g++) {
        if (is_primitive_root(g, n)) {
            return g; // Return the first primitive root found
        }
    }
    return -1; // No primitive root found
}

int main() {
    int n;

    // Input the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Check if n is a prime number
    bool is_prime = true;
    if (n < 2) {
        is_prime = false;
    } else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                is_prime = false;
                break;
            }
        }
    }

    if (!is_prime) {
        printf("%d is not a prime number. Primitive roots are only defined for prime numbers in this program.\n", n);
    } else {
        // Find and print the primitive root modulo n
        int primitive_root = find_primitive_root(n);
        if (primitive_root != -1) {
            printf("A primitive root modulo %d is: %d\n", n, primitive_root);
        } else {
            printf("No primitive root exists for %d.\n", n);
        }
    }

    return 0;
}

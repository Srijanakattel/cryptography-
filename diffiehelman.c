#include <stdio.h>

// Function to compute (base^exp) % mod using modular exponentiation
int power_mod(int base, int exp, int mod) {
    long long result = 1;
    long long b = base;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * b) % mod;
        }
        exp = exp >> 1;
        b = (b * b) % mod;
    }
    return result;
}

int main() {
    int private_key1, private_key2, public_base, public_modulus;

    // Input private keys, public base, and public modulus
    printf("Enter the first private key: ");
    scanf("%d", &private_key1);

    printf("Enter the second private key: ");
    scanf("%d", &private_key2);

    printf("Enter the public base: ");
    scanf("%d", &public_base);

    printf("Enter the public modulus: ");
    scanf("%d", &public_modulus);

    // Calculate the public values
    int public_value1 = power_mod(public_base, private_key1, public_modulus);
    int public_value2 = power_mod(public_base, private_key2, public_modulus);

    // Calculate the shared secret keys
    int shared_secret1 = power_mod(public_value2, private_key1, public_modulus);
    int shared_secret2 = power_mod(public_value1, private_key2, public_modulus);

    // Output the shared secret keys
    printf("Shared secret key calculated by first party: %d\n", shared_secret1);
    printf("Shared secret key calculated by second party: %d\n", shared_secret2);

    // Check if both shared secret keys are equal
    if (shared_secret1 == shared_secret2) {
        printf("The shared secret key is: %d\n", shared_secret1);
    } else {
        printf("Error: Shared secret keys do not match.\n");
    }

    return 0;
}

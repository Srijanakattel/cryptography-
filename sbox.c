#include <stdio.h>
#include <stdint.h>

// Define S1 S-Box
int S1[4][16] = {
    {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7},
    { 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8},
    { 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0},
    {15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13}
};

int sbox_substitution(int input) {
    int row = ((input & 0x20) >> 4) | (input & 0x01); // Extract the row (bits 1 and 6)
    int col = (input & 0x1E) >> 1; // Extract the column (bits 2 to 5)
    return S1[row][col]; // Perform substitution
}

int main() {
    int input;
    printf("Enter a 6-bit input (0-63): ");
    scanf("%d", &input);
    
    if (input < 0 || input > 63) {
        printf("Invalid input! Please enter a value between 0 and 63.\n");
        return 1;
    }

    int output = sbox_substitution(input);
    printf("S-Box substitution result: %d\n", output);
    
    return 0;
}

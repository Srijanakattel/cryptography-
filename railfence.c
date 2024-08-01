#include <stdio.h>
#include <string.h>
#include <ctype.h>

void railFenceEncrypt(char *plaintext, int rails, char *encrypted) {
    int length = strlen(plaintext);
    char rail[rails][length];
    memset(rail, ' ', sizeof(rail)); // Initialize rail matrix with spaces

    int row = 0, dir = 1; // dir = 1 means moving down, -1 means moving up

    for (int i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            rail[row][i] = plaintext[i];
            row += dir;
            if (row == 0 || row == rails - 1) dir *= -1; // Change direction at the top or bottom rail
        } else {
            encrypted[i] = plaintext[i];
        }
    }

    int k = 0;
    for (int r = 0; r < rails; r++) {
        for (int i = 0; i < length; i++) {
            if (rail[r][i] != ' ') encrypted[k++] = rail[r][i];
        }
    }
    encrypted[k] = '\0'; // Null-terminate the string
}

void railFenceDecrypt(char *encrypted, int rails, char *decrypted) {
    int length = strlen(encrypted);
    char rail[rails][length];
    memset(rail, ' ', sizeof(rail)); // Initialize rail matrix with spaces

    int row = 0, dir = 1; // dir = 1 means moving down, -1 means moving up

    for (int i = 0; i < length; i++) {
        if (isalpha(encrypted[i])) {
            rail[row][i] = '*'; // Mark positions to fill with encrypted characters
            row += dir;
            if (row == 0 || row == rails - 1) dir *= -1; // Change direction at the top or bottom rail
        } else {
            decrypted[i] = encrypted[i];
        }
    }

    int k = 0;
    for (int r = 0; r < rails; r++) {
        for (int i = 0; i < length; i++) {
            if (rail[r][i] == '*') rail[r][i] = encrypted[k++];
        }
    }

    row = 0;
    dir = 1;
    for (int i = 0; i < length; i++) {
        if (isalpha(encrypted[i])) {
            decrypted[i] = rail[row][i];
            row += dir;
            if (row == 0 || row == rails - 1) dir *= -1; // Change direction at the top or bottom rail
        } else {
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[length] = '\0'; // Null-terminate the string
}

int main() {
    char plaintext[100];
    char encrypted[100];
    char decrypted[100];
    int rails;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove trailing newline character

    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    railFenceEncrypt(plaintext, rails, encrypted);
    printf("Encrypted text: %s\n", encrypted);

    railFenceDecrypt(encrypted, rails, decrypted);
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}

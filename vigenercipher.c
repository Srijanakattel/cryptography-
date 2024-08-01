#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenereCipher(char *input, char *key, char *output, int decrypt) {
    int textLength = strlen(input);
    int keyLength = strlen(key);

    for (int i = 0, j = 0; i < textLength; i++) {
        if (isalpha(input[i])) {
            char base = islower(input[i]) ? 'a' : 'A';
            char k = tolower(key[j % keyLength]) - 'a';
            if (decrypt) {
                output[i] = (input[i] - base - k + 26) % 26 + base;
            } else {
                output[i] = (input[i] - base + k) % 26 + base;
            }
            j++;
        } else {
            output[i] = input[i];
        }
    }
    output[textLength] = '\0';
}

int main() {
    char plaintext[100];
    char keyword[100];
    char encrypted_text[100];
    char decrypted_text[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove trailing newline character

    printf("Enter the keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0'; // Remove trailing newline character

    vigenereCipher(plaintext, keyword, encrypted_text, 0);
    printf("Encrypted text: %s\n", encrypted_text);

    vigenereCipher(encrypted_text, keyword, decrypted_text, 1);
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}

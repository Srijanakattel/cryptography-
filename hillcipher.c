#include <stdio.h>
#include <math.h>

#define MOD 26

int mod_inverse(int a, int m) {
  a = a % m;
  for (int x = 1; x < m; x++)
    if ((a * x) % m == 1)
      return x;
  return -1;
}

int determinant(int a, int b, int c, int d) {
  return (a * d - b * c) % MOD;
}

void encrypt(int key[2][2], char *plaintext, char *ciphertext) {
  int len = strlen(plaintext);
  for (int i = 0; i < len; i += 2) {
    int p1 = plaintext[i] - 'A';
    int p2 = (i + 1 < len) ? plaintext[i + 1] - 'A' : 0;

    int c1 = (key[0][0] * p1 + key[0][1] * p2) % MOD;
    int c2 = (key[1][0] * p1 + key[1][1] * p2) % MOD;

    ciphertext[i] = c1 + 'A';
    if (i + 1 < len)
      ciphertext[i + 1] = c2 + 'A';
  }
  ciphertext[len] = '\0';
}

void decrypt(int key[2][2], char *ciphertext, char *plaintext) {
  int det = determinant(key[0][0], key[0][1], key[1][0], key[1][1]);
  int inv_det = mod_inverse(det, MOD);
  if (inv_det == -1) {
    printf("Key matrix is not invertible.\n");
    return;
  }

  int inv_key[2][2];
  inv_key[0][0] = (key[1][1] * inv_det) % MOD;
  inv_key[0][1] = (-key[0][1] * inv_det) % MOD;
  inv_key[1][0] = (-key[1][0] * inv_det) % MOD;
  inv_key[1][1] = (key[0][0] * inv_det) % MOD;

  int len = strlen(ciphertext);
  for (int i = 0; i < len; i += 2) {
    int c1 = ciphertext[i] - 'A';
    int c2 = (i + 1 < len) ? ciphertext[i + 1] - 'A' : 0;

    int p1 = (inv_key[0][0] * c1 + inv_key[0][1] * c2) % MOD;
    int p2 = (inv_key[1][0] * c1 + inv_key[1][1] * c2) % MOD;

    plaintext[i] = p1 + 'A';
    if (i + 1 < len)
      plaintext[i + 1] = p2 + 'A';
  }
  plaintext[len] = '\0';
}

int main() {
  int key[2][2];
  char plaintext[100], ciphertext[100];

  // Input key matrix
  printf("Enter key matrix (4 numbers separated by spaces): ");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &key[i][j]);
    }
  }

  // Input plaintext
  printf("Enter plaintext: ");
  scanf("%s", plaintext);

  encrypt(key, plaintext, ciphertext);
  printf("Encrypted text: %s\n", ciphertext);

  decrypt(key, ciphertext, plaintext);
  printf("Decrypted text: %s\n", plaintext);

  return 0;
}

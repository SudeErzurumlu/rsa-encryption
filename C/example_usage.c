// example_usage.c
// Example usage of the RSA encryption and decryption in C

#include <stdio.h>
#include "rsa.c"

int main() {
    int p = 61, q = 53;  // Example prime numbers
    int e, d, n;
    
    // Generate keys
    rsa_generate_keys(&e, &d, &n, p, q);

    // Display public and private keys
    printf("Public Key (e, n): %d, %d\n", e, n);
    printf("Private Key (d, n): %d, %d\n", d, n);

    // Encrypt and decrypt message
    int message = 65; // Example message (A)
    printf("Original message: %d\n", message);

    int encrypted = rsa_encrypt(message, e, n);
    printf("Encrypted message: %d\n", encrypted);

    int decrypted = rsa_decrypt(encrypted, d, n);
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}

// rsa.c
// RSA encryption and decryption in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int mod_inverse(int e, int phi) {
    int t = 0, new_t = 1;
    int r = phi, new_r = e;

    while (new_r != 0) {
        int quotient = r / new_r;
        int temp = new_t;
        new_t = t - quotient * new_t;
        t = temp;

        temp = new_r;
        new_r = r - quotient * new_r;
        r = temp;
    }

    if (t < 0) t += phi;
    return t;
}

void rsa_generate_keys(int *e, int *d, int *n, int p, int q) {
    *n = p * q;
    int phi = (p - 1) * (q - 1);

    *e = 2;
    while (*e < phi && gcd(*e, phi) != 1) {
        (*e)++;
    }

    *d = mod_inverse(*e, phi);
}

int rsa_encrypt(int message, int e, int n) {
    return mod_exp(message, e, n);
}

int rsa_decrypt(int ciphertext, int d, int n) {
    return mod_exp(ciphertext, d, n);
}

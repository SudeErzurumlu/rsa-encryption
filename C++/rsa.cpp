// rsa.cpp
// Implementation of the RSA encryption and decryption algorithms

#include "rsa.h"
#include <random>
#include <iostream>

RSA::RSA(int keySize) : keySize(keySize) {
    generateKeys();
}

std::pair<long long, long long> RSA::generatePublicKey() {
    return {e, n};
}

void RSA::generateKeys() {
    p = generatePrime();
    q = generatePrime();
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Choose e
    e = 2;
    while (e < phi && gcd(e, phi) != 1) {
        ++e;
    }

    d = modInverse(e, phi);
}

long long RSA::encrypt(long long message, long long e, long long n) {
    return modExp(message, e, n);
}

long long RSA::decrypt(long long cipher, long long d, long long n) {
    return modExp(cipher, d, n);
}

long long RSA::generatePrime() {
    // Simple random prime generator for demonstration
    static std::default_random_engine generator;
    std::uniform_int_distribution<long long> distribution(100, 300);
    long long prime = distribution(generator);
    return prime | 1;  // Ensure it’s odd (not ideal for actual primes)
}

long long RSA::gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long RSA::modInverse(long long e, long long phi) {
    long long m0 = phi, x0 = 0, x1 = 1;
    if (phi == 1) return 0;

    while (e > 1) {
        long long q = e / phi;
        long long t = phi;
        phi = e % phi;
        e = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    return (x1 + m0) % m0;
}

long long RSA::modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

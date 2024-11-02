// rsa.h
// Header file for RSA encryption and decryption

#ifndef RSA_H
#define RSA_H

#include <string>
#include <utility>

class RSA {
public:
    RSA(int keySize = 1024);
    
    std::pair<long long, long long> generatePublicKey();
    long long encrypt(long long message, long long e, long long n);
    long long decrypt(long long cipher, long long d, long long n);

private:
    int keySize;
    long long p, q, n, phi, e, d;
    
    long long generatePrime();
    long long gcd(long long a, long long b);
    long long modInverse(long long e, long long phi);
    long long modExp(long long base, long long exp, long long mod);
    void generateKeys();
};

#endif // RSA_H

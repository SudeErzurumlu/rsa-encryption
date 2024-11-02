# rsa.py
# RSA encryption and decryption using modular arithmetic

import random
from sympy import isprime

class RSA:
    def __init__(self, key_size=16):
        self.key_size = key_size
        self.p, self.q = self.generate_primes()
        self.n = self.p * self.q
        self.phi = (self.p - 1) * (self.q - 1)
        self.e = self.choose_e(self.phi)
        self.d = self.mod_inverse(self.e, self.phi)
    
    def generate_primes(self):
        while True:
            p = random.getrandbits(self.key_size)
            q = random.getrandbits(self.key_size)
            if isprime(p) and isprime(q) and p != q:
                return p, q

    def choose_e(self, phi):
        e = 2
        while e < phi and self.gcd(e, phi) != 1:
            e += 1
        return e

    def gcd(self, a, b):
        while b != 0:
            a, b = b, a % b
        return a

    def mod_inverse(self, a, m):
        m0, x0, x1 = m, 0, 1
        while a > 1:
            q = a // m
            m, a = a % m, m
            x0, x1 = x1 - q * x0, x0
        return x1 + m0 if x1 < 0 else x1

    def mod_exp(self, base, exp, mod):
        result = 1
        while exp > 0:
            if exp % 2 == 1:
                result = (result * base) % mod
            exp >>= 1
            base = (base * base) % mod
        return result

    def encrypt(self, plaintext):
        return [self.mod_exp(ord(char), self.e, self.n) for char in plaintext]

    def decrypt(self, ciphertext):
        return ''.join(chr(self.mod_exp(char, self.d, self.n)) for char in ciphertext)

    def get_public_key(self):
        return (self.e, self.n)

    def get_private_key(self):
        return (self.d, self.n)

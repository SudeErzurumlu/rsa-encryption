// RSA.java
// RSA encryption and decryption using modular arithmetic

import java.math.BigInteger;
import java.security.SecureRandom;

public class RSA {
    private BigInteger p, q, n, phi, e, d;
    private int bitLength;

    public RSA(int bitLength) {
        this.bitLength = bitLength;
        generateKeys();
    }

    private void generateKeys() {
        SecureRandom random = new SecureRandom();
        p = BigInteger.probablePrime(bitLength, random);
        q = BigInteger.probablePrime(bitLength, random);
        n = p.multiply(q);
        phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        e = BigInteger.valueOf(2);

        while (e.compareTo(phi) < 0 && !e.gcd(phi).equals(BigInteger.ONE)) {
            e = e.add(BigInteger.ONE);
        }

        d = e.modInverse(phi);
    }

    public BigInteger[] getPublicKey() {
        return new BigInteger[] { e, n };
    }

    public BigInteger[] getPrivateKey() {
        return new BigInteger[] { d, n };
    }

    public BigInteger encrypt(BigInteger message) {
        return message.modPow(e, n);
    }

    public BigInteger decrypt(BigInteger ciphertext) {
        return ciphertext.modPow(d, n);
    }
}

// ExampleUsage.java
// Example usage of the RSA encryption and decryption

import java.math.BigInteger;

public class ExampleUsage {
    public static void main(String[] args) {
        RSA rsa = new RSA(16);  // 16-bit key size for demonstration

        // Display public and private keys
        BigInteger[] publicKey = rsa.getPublicKey();
        BigInteger[] privateKey = rsa.getPrivateKey();
        System.out.println("Public Key (e, n): " + publicKey[0] + ", " + publicKey[1]);
        System.out.println("Private Key (d, n): " + privateKey[0] + ", " + privateKey[1]);

        // Message to encrypt
        BigInteger message = new BigInteger("12345");
        System.out.println("Original message: " + message);

        // Encrypt the message
        BigInteger encryptedMessage = rsa.encrypt(message);
        System.out.println("Encrypted message: " + encryptedMessage);

        // Decrypt the message
        BigInteger decryptedMessage = rsa.decrypt(encryptedMessage);
        System.out.println("Decrypted message: " + decryptedMessage);
    }
}

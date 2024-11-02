// example_usage.cpp
// Example usage of the RSA encryption and decryption

#include <iostream>
#include "rsa.h"

int main() {
    RSA rsa;
    
    auto publicKey = rsa.generatePublicKey();
    long long message = 12345;

    // Encrypt the message
    long long encryptedMessage = rsa.encrypt(message, publicKey.first, publicKey.second);
    std::cout << "Encrypted message: " << encryptedMessage << std::endl;

    // Decrypt the message
    long long decryptedMessage = rsa.decrypt(encryptedMessage, rsa.generatePrivateKey(), publicKey.second);
    std::cout << "Decrypted message: " << decryptedMessage << std::endl;

    return 0;
}

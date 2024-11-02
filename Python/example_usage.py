# example_usage.py
# Example usage of the RSA encryption and decryption

from rsa import RSA

def main():
    rsa = RSA(key_size=16)  # RSA instance with a 16-bit key size (for demonstration)

    # Display public and private keys
    print("Public Key (e, n):", rsa.get_public_key())
    print("Private Key (d, n):", rsa.get_private_key())

    # Message to encrypt
    message = "Hello RSA!"
    print("Original message:", message)

    # Encrypt the message
    encrypted_message = rsa.encrypt(message)
    print("Encrypted message:", encrypted_message)

    # Decrypt the message
    decrypted_message = rsa.decrypt(encrypted_message)
    print("Decrypted message:", decrypted_message)

if __name__ == "__main__":
    main()

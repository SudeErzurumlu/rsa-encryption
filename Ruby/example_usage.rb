# example_usage.rb
# Example usage of the RSA encryption and decryption

require_relative 'rsa'

rsa = RSA.new(16)  # Create an RSA instance with 16-bit key size for demonstration

# Display public and private keys
puts "Public Key (e, n): #{rsa.public_key}"
puts "Private Key (d, n): #{rsa.private_key}"

# Message to encrypt
message = "Hello RSA!"
puts "Original message: #{message}"

# Encrypt the message
encrypted_message = rsa.encrypt(message)
puts "Encrypted message: #{encrypted_message}"

# Decrypt the message
decrypted_message = rsa.decrypt(encrypted_message)
puts "Decrypted message: #{decrypted_message}"

% example_usage.m
% Example usage of the RSA encryption and decryption in MATLAB

% Prime numbers
p = 61;
q = 53;

% Generate public and private keys
[e, d, n] = rsa_generate_keys(p, q);
fprintf('Public Key (e, n): (%d, %d)\n', e, n);
fprintf('Private Key (d, n): (%d, %d)\n', d, n);

% Message to encrypt
message = 65; % Example message (A)
fprintf('Original message: %d\n', message);

% Encrypt the message
encrypted_message = rsa_encrypt(message, e, n);
fprintf('Encrypted message: %d\n', encrypted_message);

% Decrypt the message
decrypted_message = rsa_decrypt(encrypted_message, d, n);
fprintf('Decrypted message: %d\n', decrypted_message);

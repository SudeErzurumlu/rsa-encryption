% rsa.m
% RSA encryption and decryption in MATLAB

function [e, d, n] = rsa_generate_keys(p, q)
    n = p * q;
    phi = (p - 1) * (q - 1);

    e = 2;
    while e < phi && gcd(e, phi) ~= 1
        e = e + 1;
    end

    d = mod_inverse(e, phi);
end

function y = mod_exp(base, exp, mod)
    y = 1;
    while exp > 0
        if mod(exp, 2) == 1
            y = mod(y * base, mod);
        end
        base = mod(base * base, mod);
        exp = floor(exp / 2);
    end
end

function inv = mod_inverse(a, m)
    [g, x, ~] = gcd(a, m);
    if g ~= 1
        error('No modular inverse exists');
    else
        inv = mod(x, m);
    end
end

function encrypted_message = rsa_encrypt(message, e, n)
    encrypted_message = mod_exp(message, e, n);
end

function decrypted_message = rsa_decrypt(ciphertext, d, n)
    decrypted_message = mod_exp(ciphertext, d, n);
end

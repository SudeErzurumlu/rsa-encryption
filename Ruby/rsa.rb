# rsa.rb
# RSA encryption and decryption using modular arithmetic

require 'prime'

class RSA
  attr_reader :public_key, :private_key

  def initialize(key_size = 16)
    @p = generate_prime(key_size)
    @q = generate_prime(key_size)
    @n = @p * @q
    @phi = (@p - 1) * (@q - 1)
    @e = choose_e(@phi)
    @d = mod_inverse(@e, @phi)
    @public_key = [@e, @n]
    @private_key = [@d, @n]
  end

  def generate_prime(bits)
    loop do
      prime = rand(2**(bits - 1)..2**bits)
      return prime if prime.prime?
    end
  end

  def choose_e(phi)
    e = 2
    e += 1 until e.gcd(phi) == 1
    e
  end

  def mod_inverse(a, m)
    m0, x0, x1 = m, 0, 1
    while a > 1
      q = a / m
      m, a = a % m, m
      x0, x1 = x1 - q * x0, x0
    end
    x1 += m0 if x1 < 0
    x1
  end

  def mod_exp(base, exp, mod)
    result = 1
    while exp > 0
      result = (result * base) % mod if exp.odd?
      base = (base * base) % mod
      exp >>= 1
    end
    result
  end

  def encrypt(plaintext)
    plaintext.each_char.map { |char| mod_exp(char.ord, @e, @n) }
  end

  def decrypt(ciphertext)
    ciphertext.map { |char| mod_exp(char, @d, @n).chr }.join
  end
end

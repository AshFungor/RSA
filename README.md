# RSA

RSA (Rivest-Shamir-Adleman) is a public-key cryptosystem that is widely 
used for secure data transmission. RSA is based on the mathematical problem 
of finding the factors of large semi-prime numbers, which forms the basis of its 
security. RSA encryption uses two keys, 
a public key for encryption and a private key for decryption, making it a 
secure and efficient method for data protection.

## Implementation

Because of hard limit for integer length in CXX this implementation is designed
to use short keys (max 0xFFFF for both), so resulting modulo n will be less than
32-bit number and reversed exponent d will be so. This (and simple data padding)
ensures that operations can be done on 64-bit numbers with zero loss of data.

## Build and test

*build.sh* and *test.sh* are made to build and test RSA on simple plaintext with
defined public and private key. If you want to access CLI, just run
*build/src/RSA* after building executable.

## Attacks

This practical assignment only implements single attack: chosen-ciphertext attack.
It is based on condition that we can decrypt chosen ciphertext while having no
access to private key, which means we are not able to decipher anything directly.

Because RSA uses exponents we can use this property of exponent's multiplication:

```
c = m^e (mod n)
c_m = r^e * m^e (mod n) => c_m = (r * m) ^ e (mod n)
decipher c_m, we have:
m_m = r * m
find inverse of r, r_inv:
r_inv * m_m = r_inv * r * m = m   
```

So, knowing any ciphertext with multiplication with some defined ciphertext
r^e and decrypting this product later we can recover multiplicand (initial plaintext).

Build and run *attack.sh* to test this.
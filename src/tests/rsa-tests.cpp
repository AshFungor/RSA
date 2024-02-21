// gtest
#include <gtest/gtest.h>

// standard
#include <array>
#include <cstdint>

// local
#include "definitions.hpp"
#include "rsa.hpp"

TEST(RSATest, CipherChunkTest) {
    PubKeyPair key {17, 3233};
    ASSERT_EQ(RSA::cipher(65, key), 2790);
}

TEST(RSATest, DecipherChunkTest) {
    PrKey key {413, 3233};
    ASSERT_EQ(RSA::decipher(2790, key), 65);
}
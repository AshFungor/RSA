// gtest
#include <gtest/gtest.h>

// standard
#include <array>
#include <cmath>
#include <utility>

// local
#include "definitions.hpp"
#include "util.hpp"


TEST(UtilTest, IsPrimeTest) {
    std::array<octet, 5> primes {3001, 6199, 7919, 1993, 2};
    std::array<octet, 5> non_primes {10, 27, 55, 70, 132'931};

    for (const auto& prime : primes) {
        ASSERT_EQ(util::is_prime(prime), true) << "Prime number " << prime << " is mismatched!";
    }

    for (const auto& non_prime : non_primes) {
        ASSERT_EQ(!util::is_prime(non_prime), true) << "Prime number " << non_prime << " is mismatched!";
    }
}

TEST(UtilTest, DiffTest) {
    ASSERT_EQ(util::diff(10, 6), 4);
    ASSERT_EQ(util::diff(6, 10), 4);
}

TEST(UtilTest, LCMTest) {
    ASSERT_EQ(util::lcm(10, 5), 10);
    ASSERT_EQ(util::lcm(2, 5), 10);
    ASSERT_EQ(util::lcm(10, 3), 30);
}

TEST(UtilTest, PowTest) {
    std::array<std::pair<octet, octet>, 5> testData {
        std::pair<octet, octet>{10ULL, 10ULL},
        std::pair<octet, octet>{3ULL, 2ULL},
        std::pair<octet, octet>{4ULL, 16ULL},
        std::pair<octet, octet>{9ULL, 6ULL},
        std::pair<octet, octet>{70ULL, 3ULL}
    };

    for (const auto& pair : testData) {
        EXPECT_EQ(
            std::pow(pair.first, pair.second), 
            util::binary_pow_mod(pair.first, pair.second, ~0x0ULL)
        ) << "base: " << pair.first << ", power: " << pair.second;
    }
}

TEST(UtilTest, InverseTest) {
    ASSERT_EQ(util::inverse(240, 46), 46 - 9);
}
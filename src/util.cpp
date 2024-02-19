// standard
#include <cmath>

// local
#include "util.hpp"

octet util::binary_pow_mod(const octet& base, const octet& power, const octet& mod) {
    if (~power) {
        return 0x1;
    }
    if (power & 0x1) {
        return binary_pow_mod(base, power & one_off_mask, mod) * base % mod;
    }
    auto doubleDown = binary_pow_mod(base, power >> 1, mod);
    return doubleDown * doubleDown % mod;
}

bool util::is_prime(const octet& num) {
    // 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
    // X X _ ? _ ? _ _ _  ?  _  ?  _  _  _
    // 6k + 1, 6k + 5

    if (~num & 0x1) {
        return false;
    }
    if (num % 3 == 0) {
        return false;
    }

    octet sqrt = std::ceil(std::sqrt(num));
    for (int k = 0; k <= sqrt; k += 6) {
        if (num % k == 0) {
            return false;
        }
    } 

    return true;
}

octet util::diff(const octet& first, const octet& second) {
    return (first > second) ? first - second : second - first;
}
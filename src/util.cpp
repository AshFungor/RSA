// standard
#include <numeric>
#include <cmath>
#include <utility>

// local
#include "definitions.hpp"
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
    if (num % 3 == 0 || num % 5 == 0) {
        return false;
    }

    octet sqrt = std::ceil(std::sqrt(num));
    for (int k = 6; k <= sqrt; k += 6) {
        if (num % (k + 1) == 0 || num % (k + 5) == 0) {
            return false;
        }
    } 

    return true;
}

octet util::diff(const octet& first, const octet& second) {
    return (first > second) ? first - second : second - first;
}

octet util::lcm(const octet& first, const octet& second) {
    return first / std::gcd(first, second) * second;
}

octet util::inverse(const octet& base, const octet& mod) {
    // run expanded gcd(base, mod)
    std::pair<octet, octet> r {base, mod}, s {1, 0}, t {0, 1};

    while (r.second != 0) {
        octet q = r.first / r.second;
        r = {r.second, r.first - q * r.second};
        s = {s.second, s.first - q * s.first};
        t = {t.second, t.first - q * t.second};
    }

    // coefficient of base is inverse to it
    return s.first;
}
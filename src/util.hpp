#pragma once

#include "definitions.hpp"

namespace util {

    inline constexpr octet one_off_mask = (~0x0ULL) << 1;

    octet binary_pow_mod(const octet& base, const octet& power, const octet& mod);
    bool is_prime(const octet& num);
    octet diff(const octet& first, const octet& second);
}
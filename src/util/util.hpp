#pragma once

#include <string>
#include <functional>

#include "definitions.hpp"

namespace util {

    inline constexpr octet one_off_mask = (~0x0ULL) << 1;

    // fast exponent using binary split
    octet binary_pow_mod(const octet& base, const octet& power, const octet& mod);
    // fast prime-test
    bool is_prime(const octet& num);
    // absolute difference between two non-negative numbers
    octet diff(const octet& first, const octet& second);
    // least common multiple
    octet lcm(const octet& first, const octet& second);
    // find inverse by mod
    octet inverse(const octet& base, const octet& mod);
    octet gcd(octet a, octet b, long long& x, long long& y);
    // file IO
    void process_file(const std::string& file, 
                      const std::string& outfile, 
                      std::function<octet(octet)> process, 
                      std::size_t blockIn = 8,
                      std::size_t blockOut = 8);
}
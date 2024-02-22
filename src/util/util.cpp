// standard
#include <numeric>
#include <cmath>
#include <utility>
#include <ios>
#include <fstream>

// local
#include "definitions.hpp"
#include "util.hpp"

using ll = long long;
using ld = long double;

octet util::binary_pow_mod(const octet& base, const octet& power, const octet& mod) {
    if (!power) {
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

    if (num % 2 == 0) {
        if (num == 2) {
            return true;
        }
        return false;
    }
    if (num % 3 == 0 || num % 5 == 0) {
        if (num == 3 || num == 5) {
            return true;
        }
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
    ll s, t;
    util::gcd(base, mod, s, t);
    return (s + (std::abs(s) / mod + 1) * mod) % mod;
}

octet util::gcd(octet a, octet b, ll& x, ll& y) {
    if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	octet d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

void util::process_file(
    const std::string& file, 
    const std::string& outfile, 
    std::function<octet(octet)> process, 
    std::size_t blockIn, 
    std::size_t blockOut) 
{
    std::ifstream ifs {file, std::ios::binary | std::ios::in};
    std::ofstream ofs {outfile, std::ios::binary | std::ios::out};

    octet block;

    while (ifs.peek() != EOF) {
        block = 0;
        ifs.read(reinterpret_cast<char*>(&block), blockIn);
        block = process(block);
        ofs.write(reinterpret_cast<char*>(&block), blockOut);
    }
}
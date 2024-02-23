#pragma once

#include <vector>
#include <cstdint>
#include <utility>

using octet = std::uint64_t;
using octet_string = char[9]; 
using plaintext = std::vector<std::uint16_t>;

// keys
class PubKey {
public:
    // keygen routine
    inline PubKey(octet e, octet n) : e_(e), n_(n) {}
    inline const octet& e() const { return e_; }
    inline const octet& n() const { return n_; }
private:
    octet e_;
    octet n_;
};

class PrKey {
public:
    inline PrKey(octet d, octet n) : d_(d), n_(n) {}
    inline const octet& d() const { return d_; }
    inline const octet& n() const { return n_; }
private:
    octet d_;
    octet n_;
};

struct KeyContext {
    octet p;
    octet q;
    octet n;
    octet lambda_n;
    octet e;
    octet d;
};
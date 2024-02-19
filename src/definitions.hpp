#pragma once

#include <cstdint>
#include <utility>

using octet = std::uint64_t;
using octet_string = char[9]; 

// keys
class PubKeyPair {
public:
    // keygen routine
    inline PubKeyPair(octet p, octet q) : p_(p), q_(q) {}
    inline const octet& p() { return p_; }
    inline const octet& q() { return q_; }
private:
    octet p_;
    octet q_;
};

class PrKey {
public:
    inline PrKey(octet d) : d_(d) {}
    inline const octet& d() { return d_; }
private:
    octet d_;
};

struct KeyContext {
    octet p;
    octet q;
    octet n;
    octet lambda_n;
    octet e;
    octet d;
};
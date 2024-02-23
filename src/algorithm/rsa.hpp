#pragma once

// standard
#include <cstdint>
#include <memory>
#include <utility>

// local
#include "definitions.hpp"

namespace RSA {

    std::unique_ptr<KeyContext> keygen();
    std::pair<PubKey, PrKey> generate_key_pair();
    octet cipher(const octet& block, const PubKey& key);
    octet decipher(const octet& block, const PrKey& key);
}
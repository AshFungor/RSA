#pragma once

// standard
#include <cstdint>
#include <memory>
#include <utility>

// local
#include "definitions.hpp"

namespace RSA {

    std::unique_ptr<KeyContext> keygen();
    std::pair<PubKeyPair, PrKey> generate_key_pair();
    std::uint16_t cipher(const octet& block, const PubKeyPair& key);
    std::uint16_t decipher(const octet& block, const PrKey& key);
}
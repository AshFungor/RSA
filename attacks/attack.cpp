// standard
#include <cstdint>
#include <fstream>
#include <functional>
#include <ios>
#include <iostream>
#include <string>

// local
#include "definitions.hpp"
#include "util.hpp"
#include "rsa.hpp"

int main() {
    // Generate key pair for initial scenario
    auto keys = RSA::generate_key_pair();
    PubKeyPair pubKey {keys.first};
    PrKey prKey {keys.second};

    util::process_file("plaintext.txt", "target.bin", [&pubKey](octet in) { 
        return RSA::cipher(in, pubKey); 
    }, 2, 8);
    
    octet r = 79, inv_r = util::inverse(r, pubKey.n());
    // Now we need to modify cipher text a little bit
    util::process_file("target.bin", "modified.bin", [&pubKey, &r](octet in) { 
        return RSA::cipher(r, pubKey) * in % pubKey.n(); 
    }, 8, 8);

    // Now we can decipher another cipher text obtained from initial
    util::process_file("modified.bin", "result.txt", [&prKey, &inv_r](octet in) { 
        return RSA::decipher(in, prKey) * inv_r % prKey.n(); 
    }, 8, 2);

    return 0;
}
// standard
#include <cstdint>
#include <fstream>
#include <functional>
#include <ios>
#include <cmath>
#include <iostream>
#include <string>

// local
#include "definitions.hpp"
#include "util.hpp"
#include "rsa.hpp"

int main() {
    std::cout << "This is RSA encryption/decryption program, please select one option:\n"
              << "- encrypt (1)\n" << "- decrypt (2)\n" << "- generate key pair (3)\n";

    int choice; std::cin >> choice;
    if (choice == 1) {
        octet e, n;
        std::cout << "Enter public exponent (e): "; std::cin >> e;
        std::cout << "Enter modulo (n): "; std::cin >> n;
        PubKey key {e, n};
        std::string file;
        std::cout << "Enter filename with plaintext: "; std::cin >> file;
        util::process_file(file, "out.bin", [&key](octet in) { return RSA::cipher(in, key); }, std::floor(std::log2(key.n()) / 8), 8);
        std::cout << "Ciphertext ready: out.bin\n";
        return 0;
    } 
    if (choice == 2) {
        octet d, n;
        std::cout << "Enter private exponent (d): "; std::cin >> d;
        std::cout << "Enter modulo (n): "; std::cin >> n;
        PrKey key {d, n};
        std::string file;
        std::cout << "Enter filename with ciphertext: "; std::cin >> file;
        util::process_file(file, "out.txt", [&key](octet in) { return RSA::decipher(in, key); }, 8, std::floor(std::log2(key.n()) / 8));
        std::cout << "Plaintext ready: out.txt\n";
        return 0;
    }
    if (choice == 3) {
        std::cout << "Generating key...\n";
        auto result = RSA::generate_key_pair();
        std::cout << "Public key: e = " << result.first.e() << ", n = " << result.first.n() << '\n'
                  << "Private key: d = " << result.second.d() << ", n = " << result.second.n() << '\n';
        return 0;
    }
    std::cout << "Unknown option " << choice << ", aborting...\n";
    return 0;
}
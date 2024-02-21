// standard
#include <cstdint>
#include <fstream>
#include <functional>
#include <ios>
#include <iostream>
#include <string>

// local
#include "definitions.hpp"
#include "rsa.hpp"

void process_file(const std::string& file, const std::string& outfile, std::function<octet(octet)> process) {
    std::ifstream ifs {file, std::ios::binary | std::ios::in};
    std::ofstream ofs {outfile, std::ios::binary | std::ios::out};

    octet block;
    while (ifs.peek() != EOF) {
        ifs.read(reinterpret_cast<char*>(&block), 8);
        block = process(block);
        ofs.write(reinterpret_cast<char*>(&block), 8);
    }
}

int main() {
    std::cout << "This is RSA encryption/decryption program, please select one option:\n"
              << "- encrypt (1)\n" << "- decrypt (2)\n" << "- generate key pair (3)\n";

    int choice; std::cin >> choice;
    if (choice == 1) {
        octet e, n;
        std::cout << "Enter public exponent (e): "; std::cin >> e;
        std::cout << "Enter modulo (n): "; std::cin >> n;
        PubKeyPair key {e, n};
        std::string file;
        std::cout << "Enter filename with plaintext: "; std::cin >> file;
        process_file(file, "out.bin", [&key](octet in) { return RSA::cipher(in, key); });
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
        process_file(file, "out.txt", [&key](octet in) { return RSA::decipher(in, key); });
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
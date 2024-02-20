#include <iostream>

#include "rsa.hpp"

int main() {
    auto res = RSA::keygen();
    std::cout << res->p << ' ' << res->q << '\n';

}
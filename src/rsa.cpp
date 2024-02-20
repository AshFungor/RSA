// standard
#include <memory>
#include <random>
#include <cmath>

// local
#include "definitions.hpp"
#include "rsa.hpp"
#include "util.hpp"

std::unique_ptr<KeyContext> RSA::keygen() {
    auto context = std::make_unique<KeyContext>();
    // seed for mt
    std::random_device d;
    std::seed_seq ss {
        d(), d(), d(), d(), d(), d(), d(), d()
    };

    // distribution for key values (must be big enough)
    std::uniform_int_distribution<octet> dist (0x0000FFFF0000ULL, ~0x0ULL);
    std::uniform_int_distribution<octet> eps_dist (0xFF, 0xFFF);
    std::mt19937 rand {ss};

    context->p = dist(rand);
    context->q = dist(rand);
    octet eps = eps_dist(rand);

    while (!util::is_prime(context->p)) {
        context->p = dist(rand);
    }

    regenerate_component:
    while (!util::is_prime(context->q)) {
        context->q = dist(rand);
    }

    if (util::diff(context->p, context->q) < eps) {
        goto regenerate_component;
    }

    context->n = context->p * context->q;
    context->lambda_n = util::lcm(context->p - 1, context->q - 1);

    // effective and secure enough choice
    context->e = 0x1 << 16 | 1;

    context->d = util::inverse(context->e, context->lambda_n);

    return std::move(context);
}
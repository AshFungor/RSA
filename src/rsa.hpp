#pragma once

// standard
#include <memory>

// local
#include "definitions.hpp"

namespace RSA {

    std::unique_ptr<KeyContext> keygen();

}
from conan import ConanFile

class RSA(ConanFile):
    version = "0.0"
    settings = ["os", "compiler", "arch", "build_type"]
    generators = ["CMakeToolchain", "CMakeDeps"]
    requires = ["gtest/1.14.0", "gmp/6.3.0"]
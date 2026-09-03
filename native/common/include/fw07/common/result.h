
#pragma once
#include <string>
namespace cockpit {
template <typename T> struct Result { T value{}; int error{0}; std::string detail; explicit operator bool() const { return error == 0; } };
}

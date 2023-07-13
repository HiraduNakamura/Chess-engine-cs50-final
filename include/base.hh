#ifndef BASEHH
#define BASEHH
#include <vector>
#include <array>
#include <cstdint>
// Enum that represents the color of a piece
enum Color { WHITE=1, BLACK=2};
// Error code for functions (exceptions are bad)
enum ErrCode {
    ERR_OK = 0,
    ERR_INVALID_ARGS = 1,
    ERR_ILLEGAL_MOVE = 2,
};

class Base {};
#endif
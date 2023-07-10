#ifndef BASEHH
#define BASEHH
constexpr int8_t WHITE = 0;
constexpr int8_t BLACK = 1;
#include <vector>
#include <array>
#include <cstdint>
typedef int8_t Color;
enum ErrCode {
    ERR_OK = 0,
    ERR_INVALID_ARGS = 1,
    ERR_ILLEGAL_MOVE = 2,
};

class Base {};
#endif
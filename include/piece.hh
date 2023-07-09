#ifndef PIECEHH
#define PIECEHH
#include "base.hh"
#include "board.hh"
#include <iostream>
#include <vector>
#include <array>
class Piece : public Base {
    private:
        std::vector<std::array<int, 2>> legalMoves;
    public:
        int row;
        int col;
        Color color;
        Piece(int row, int col, Color color);
        virtual bool isLegalMove(int row, int col);
        void updateLegalMoves();
        std::vector<std::array<int,2>> getLegalMoves();
        ErrCode move(int row, int col);
};
#endif

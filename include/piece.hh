#ifndef PIECEHH
#define PIECEHH
#include "base.hh"
#include <iostream>
#include <vector>
#include <array>
/*
This is an abstract class representing a general piece, with the only needed method being isLegalMove().

*/
class Piece : public Base {
    private:
        std::vector<std::array<int, 2>> legalMoves;
    public:
        Piece();
        int row;
        int col;
        Color color;
        Piece(int row, int col, Color color);
        virtual bool isLegalMove(int row, int col);
        // This method differs from isLegalMove() in cases such as the pawn, where allthough the piece can be moved forward, it does not attack forward.
        virtual bool isAttackedSquare(int row, int col);
        void updateLegalMoves();
        std::vector<std::array<int,2>> getLegalMoves();
        ErrCode move(int row, int col);
        ~Piece();

};
#endif

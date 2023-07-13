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
        // Legal moves of a piece
        std::vector<std::array<int, 2>> legalMoves;
        // List of attacked squares of a piece. This may or may not be the same as legalMoves. (see pawn as an example)
        std::vector<std::array<int, 2>> attackedSquares;
    public:
        Piece();
        int row;
        int col;
        Color color;
        Piece(int row, int col, Color color);
        virtual bool isLegalMoveIfNotCheck(int row, int col) = 0;
        // This method differs from isLegalMove() in cases such as the pawn, where although the piece can be moved forward, it does not attack forward.
        virtual bool isAttackedSquareIfNotCheck(int row, int col) = 0;
        bool isAttackedSquare(int row, int col);
        bool isLegalMove(int row, int col);
        void updateAttackedSquares();
        void updateLegalMoves();
        std::vector<std::array<int,2>> getLegalMoves();
        std::vector<std::array<int,2>> getAttackedSquares();
        ErrCode move(int row, int col);
        ~Piece();

};
#endif

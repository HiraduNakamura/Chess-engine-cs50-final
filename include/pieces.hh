#include "piece.hh"
#include "board.hh"
#ifndef PIECES_HH
#define PIECES_HH
class Pawn : public Piece {
    public:
        using Piece::Piece;
        bool isLegalMoveIfNotCheck(int row, int col) override;
        bool isAttackedSquareIfNotCheck(int row, int col) override;
};
#endif
#ifndef boardhh
#define boardhh
#include "base.hh"
#include "piece.hh"
#include <string>
#include <math.h>
/*
A singleton class representing the chess board

*/
class Board : public Base {
    public:
        bool pawnOrCaptureFlag = false;
        bool whiteCanCastleKingside = true;
        bool whiteCanCastleQueenside = true;
        bool blackCanCastleKingside = true;
        bool blackCanCastleQueenside = true;
        int moveCount = 1;
        int halfMoveCountSinceCaptureOrPawnMove = 0;
        int lastMoveRow;
        int lastMoveCol;
        Color playerToMove = Color::WHITE;
        // This is the one place in the entire code I don't specify rows and columns. pieces[i][j] is on row i and column j. DO NOT FORGET.
        std::array<std::array<Piece, 8>, 8> pieces;
        static Board& getInstance(std::string pen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
        void registerMove(int row, int col);
        Piece getPieceAtSquare(int row, int col);
        bool isEmpty(int row, int col);
        bool whiteInCheck();
        bool blackInCheck();
    private:
        Board(std::string pen);
        std::array<std::array<Piece, 8>, 8> loadPEN(std::string pen);
        float moveCountIntermediate;
};
#endif
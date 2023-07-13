
#include "board.hh"
Board::Board(std::string pen) {
    this->pieces = loadPEN(pen);
}
// Gets instance of the singleton board. Pass PEN optionally on intialization.
Board& Board::getInstance(std::string pen) {
    static Board instance(pen);
    return instance;
}
// Registers that a move has been made. This function takes the implict argument of the pawn or capture flag, which must be set by the piece making the move.
void Board::registerMove(int row, int col) {
    this->halfMoveCountSinceCaptureOrPawnMove++;
    this->moveCountIntermediate += 0.5;
    this->moveCount = floor(this->moveCountIntermediate);
    this->lastMoveRow = row;
    this->lastMoveCol = col;
    if (this->pawnOrCaptureFlag) this->halfMoveCountSinceCaptureOrPawnMove = 0;
    this->pawnOrCaptureFlag = false;
}
std::array<std::array<Piece, 8>, 8> Board::loadPEN(std::string pen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1") {
    
}
Piece Board::getPieceAtSquare(int row, int col) {
    return this->pieces[row][col];
}
bool Board::isEmpty(int row, int col) {
    return this->getPieceAtSquare(row, col).row == -1;
}
bool Board::whiteInCheck() {
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece piece = pieces[i][j];
            piece.updateAttackedSquares();
            if (piece.getAttackedSquares())
        }
    }
}
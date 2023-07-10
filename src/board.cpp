
#include "board.hh"
Board::Board(std::string pen) {
    this->pieces = loadPEN(pen);
}
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
    //TODO
}
Piece Board::getPieceAtSquare(int row, int col) {
    return this->pieces[row][col];
}
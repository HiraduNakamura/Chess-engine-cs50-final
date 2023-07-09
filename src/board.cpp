
#include "../include/board.hh"
Board::Board(std::string pen) {
    this->pieces = loadPEN(pen);
}
Board& Board::getInstance(std::string pen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1") {
    static Board instance(pen);
    return instance;
}
void Board::registerMove() {
    this->halfMoveCount++;
    this->moveCount = floor(halfMoveCount / 2) + 1;
}
std::array<std::array<Piece, 8>, 8> Board::loadPEN(std::string pen) {
    //TODO
}

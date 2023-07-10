#include "piece.hh"
#include "board.hh"
/*
Initializes piece with color and type.
*/
Piece::Piece() {
    this->row = -1;
    this->col = -1;
    this->color = -1;
}
Piece::Piece(int row, int col, Color color) {
    this->row = row;
    this->col = col;
    this->color = color;
}
void Piece::updateLegalMoves() {
    this->legalMoves.clear();
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (isLegalMove(i, j)) {
                this->legalMoves.push_back(std::array<int, 2>{i, j});
            }
        }
    }
}
std::vector<std::array<int,2>> Piece::getLegalMoves() {
    return this->legalMoves;
}
//Moves piece to new position.
ErrCode Piece::move(int row, int col) {
    if (isLegalMove(row, col)) {
        this->row = row;
        this->col = col;
        Board::getInstance().registerMove(row, col);
        return ErrCode::ERR_OK;
    }
    return ErrCode::ERR_ILLEGAL_MOVE;
}
// Method to check if move is legal. Override in subclass.
bool Piece::isLegalMove(int row, int col) {
    return false;
}

Piece::~Piece() {}
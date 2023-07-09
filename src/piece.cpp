#include "../include/piece.hh"
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

ErrCode Piece::move(int row, int col) {
    if (isLegalMove(row, col)) {
        this->row = row;
        this->col = col;
        Board::getInstance().lastMoveRow = row;
        Board::getInstance().lastMoveCol = col;
        Board::getInstance().registerMove();
        return ErrCode::ERR_OK;
    }
    return ErrCode::ERR_ILLEGAL_MOVE;
}
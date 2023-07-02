#pragma once
#define WHITE 1
#define BLACK 0
#include <iostream>
#include <vector>
#include <array>
#include "board.cpp"
#include "base.cpp"
typedef int8_t Color;
class Piece : public Base {
    private:
        std::vector<std::array<int, 2>> legalMoves;
    public:
        int row;
        int col;
        Color color;
        Piece(int row, int col, Color color) {
            this->row = row;
            this->col = col;
            this->color = color;
        }
        virtual bool isLegalMove(int row, int col) = 0;
        void updateLegalMoves() {
            this->legalMoves.clear();
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (isLegalMove(i, j)) {
                        this->legalMoves.push_back(std::array<int, 2>{i, j});
                    }
                }
            }
        }
        std::vector<std::array<int,2>> getLegalMoves() {
            return this->legalMoves;
        }
        ErrCode move(int row, int col) {
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
};

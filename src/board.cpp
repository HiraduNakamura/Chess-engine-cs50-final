#include "base.cpp"
#include "piece.cpp"
#include <string>
#include <math.h>
/*
Singleton

*/
class Board : public Base {
    public:
        bool whiteCanCastleKingside = true;
        bool whiteCanCastleQueenside = true;
        bool blackCanCastleKingside = true;
        bool blackCanCastleQueenside = true;
        int moveCount = 1;
        int halfMoveCount = 0;
        int lastMoveRow;
        int lastMoveCol;
        // This is the one place in the entire code I don't specify rows and columns. piece[i][j] is on row i and column j. DO NOT FORGET.
        std::array<std::array<Piece, 8>, 8> pieces;
        static Board& getInstance(std::string pen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1") {
            static Board instance(pen);
            return instance;
        }
        void registerMove() {
            halfMoveCount++;
            moveCount = floor(halfMoveCount / 2) + 1;
        }

    private:
        Board(std::string pen) {
            loadPEN(pen);
        }
        void loadPEN(std::string pen) {
            std::string piecesString = pen.substr(0, pen.find(' '));
            std::string otherInfo = pen.substr(pen.find(' ') + 1);

            // TODO: load pieces
            for (int i = 0; i < 64; i++) {}

            // Load other information into respective variables
            whiteCanCastleKingside = (otherInfo.find('K') != std::string::npos);
            whiteCanCastleQueenside = (otherInfo.find('Q') != std::string::npos);
            blackCanCastleKingside = (otherInfo.find('k') != std::string::npos);
            blackCanCastleQueenside = (otherInfo.find('q') != std::string::npos);
            moveCount = std::stoi(otherInfo.substr(otherInfo.find(' ') + 1));
            halfMoveCount = std::stoi(otherInfo.substr(otherInfo.find_last_of(' ') + 1));

            // Load the last move into the lastMove array
            std::string lastMoveStr = otherInfo.substr(0, otherInfo.find_last_of(' '));
            lastMoveCol = lastMoveStr[0] - 'a'; // Convert file letter to 0-based index
            lastMoveRow = lastMoveStr[1] - '1'; // Convert rank number to 0-based index
        }
};
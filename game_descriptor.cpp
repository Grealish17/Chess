#include "chess.h"

namespace CHESS{
    Game_Descriptor::Game_Descriptor(Game_Descriptor& game): turn(game.turn), verdict(game.verdict), status(game.status),
                                                             history(game.history){
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if(game.board[i][j] != nullptr){
                    auto name = game.board[i][j]->getShortName();
                    switch (name)
                    {
                        case 'K': {
                            std::pair<int, int> pK = {4, 0};
                            board[4][0] = std::make_unique<King>(King(white, board, pK));
                            break;
                        }
                        case 'Q': {
                            std::pair<int, int> pQ = {3, 0};
                            board[3][0] = std::make_unique<Queen>(Queen(white, board, pQ));
                            break;
                        }
                        case 'R': {
                            std::pair<int, int> pR1 = {0, 0};
                            board[0][0] = std::make_unique<Rook>(Rook(white, board, pR1));
                            break;
                        }
                        case 'B': {
                            std::pair<int, int> pB1 = {2, 0};
                            board[2][0] = std::make_unique<Bishop>(Bishop(white, board, pB1));
                            break;
                        }
                        case 'N': {
                            std::pair<int, int> pN1 = {1, 0};
                            board[1][0] = std::make_unique<Knight>(Knight(white, board, pN1));
                            break;
                        }
                        case 'P': {
                            std::pair<int, int> pP1 = {0, 1};
                            board[0][1] = std::make_unique<Pawn>(Pawn(white, board, pP1));
                            break;
                        }
                        case 'k': {
                            std::pair<int, int> pk = {4, 7};
                            board[4][7] = std::make_unique<King>(King(black, board, pk));
                            break;
                        }
                        case 'q': {
                            std::pair<int, int> pq = {3, 7};
                            board[3][7] = std::make_unique<Queen>(Queen(black, board, pq));
                            break;
                        }
                        case 'r': {
                            std::pair<int, int> pr1 = {0, 7};
                            board[0][7] = std::make_unique<Rook>(Rook(black, board, pr1));
                            break;
                        }
                        case 'b': {
                            std::pair<int, int> pb1 = {2, 7};
                            board[2][7] = std::make_unique<Bishop>(Bishop(black, board, pb1));
                            break;
                        }
                        case 'n': {
                            std::pair<int, int> pn1 = {1, 7};
                            board[1][7] = std::make_unique<Knight>(Knight(black, board, pn1));
                            break;
                        }
                        case 'p': {
                            std::pair<int, int> pp1 = {0, 6};
                            board[0][6] = std::make_unique<Pawn>(Pawn(black, board, pp1));
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        }
    }

    Game_Descriptor::Game_Descriptor(){
        status = GameIsOn;

        //WHITE
        std::pair<int, int> pR1 = {0, 0};
        board[0][0] = std::make_unique<Rook>(Rook(white, board, pR1));

        std::pair<int, int> pN1 = {1, 0};
        board[1][0] = std::make_unique<Knight>(Knight(white, board, pN1));

        std::pair<int, int> pB1 = {2, 0};
        board[2][0] = std::make_unique<Bishop>(Bishop(white, board, pB1));

        std::pair<int, int> pQ = {3, 0};
        board[3][0] = std::make_unique<Queen>(Queen(white, board, pQ));

        std::pair<int, int> pK = {4, 0};
        board[4][0] = std::make_unique<King>(King(white, board, pK));

        std::pair<int, int> pB2 = {5, 0};
        board[5][0] = std::make_unique<Bishop>(Bishop(white, board, pB2));

        std::pair<int, int> pN2 = {6, 0};
        board[6][0] = std::make_unique<Knight>(Knight(white, board, pN2));

        std::pair<int, int> pR2 = {7, 0};
        board[7][0] = std::make_unique<Rook>(Rook(white, board, pR2));

        std::pair<int, int> pP1 = {0, 1};
        board[0][1] = std::make_unique<Pawn>(Pawn(white, board, pP1));

        std::pair<int, int> pP2 = {1, 1};
        board[1][1] = std::make_unique<Pawn>(Pawn(white, board, pP2));

        std::pair<int, int> pP3 = {2, 1};
        board[2][1] = std::make_unique<Pawn>(Pawn(white, board, pP3));

        std::pair<int, int> pP4 = {3, 1};
        board[3][1] = std::make_unique<Pawn>(Pawn(white, board, pP4));

        std::pair<int, int> pP5 = {4, 1};
        board[4][1] = std::make_unique<Pawn>(Pawn(white, board, pP5));

        std::pair<int, int> pP6 = {5, 1};
        board[5][1] = std::make_unique<Pawn>(Pawn(white, board, pP6));

        std::pair<int, int> pP7 = {6, 1};
        board[6][1] = std::make_unique<Pawn>(Pawn(white, board, pP7));

        std::pair<int, int> pP8 = {7, 1};
        board[7][1] = std::make_unique<Pawn>(Pawn(white, board, pP8));

        //BLACK

        std::pair<int, int> pr1 = {0, 7};
        board[0][7] = std::make_unique<Rook>(Rook(black, board, pr1));

        std::pair<int, int> pn1 = {1, 7};
        board[1][7] = std::make_unique<Knight>(Knight(black, board, pn1));

        std::pair<int, int> pb1 = {2, 7};
        board[2][7] = std::make_unique<Bishop>(Bishop(black, board, pb1));

        std::pair<int, int> pq = {3, 7};
        board[3][7] = std::make_unique<Queen>(Queen(black, board, pq));

        std::pair<int, int> pk = {4, 7};
        board[4][7] = std::make_unique<King>(King(black, board, pk));

        std::pair<int, int> pb2 = {5, 7};
        board[5][7] = std::make_unique<Bishop>(Bishop(black, board, pb2));

        std::pair<int, int> pn2 = {6, 7};
        board[6][7] = std::make_unique<Knight>(Knight(black, board, pn2));

        std::pair<int, int> pr2 = {7, 7};
        board[7][7] = std::make_unique<Rook>(Rook(black, board, pr2));

        std::pair<int, int> pp1 = {0, 6};
        board[0][6] = std::make_unique<Pawn>(Pawn(black, board, pp1));

        std::pair<int, int> pp2 = {1, 6};
        board[1][6] = std::make_unique<Pawn>(Pawn(black, board, pp2));

        std::pair<int, int> pp3 = {2, 6};
        board[2][6] = std::make_unique<Pawn>(Pawn(black, board, pp3));

        std::pair<int, int> pp4 = {3, 6};
        board[3][6] = std::make_unique<Pawn>(Pawn(black, board, pp4));

        std::pair<int, int> pp5 = {4, 6};
        board[4][6] = std::make_unique<Pawn>(Pawn(black, board, pp5));

        std::pair<int, int> pp6 = {5, 6};
        board[5][6] = std::make_unique<Pawn>(Pawn(black, board, pp6));

        std::pair<int, int> pp7 = {6, 6};
        board[6][6] = std::make_unique<Pawn>(Pawn(black, board, pp7));

        std::pair<int, int> pp8 = {7, 6};
        board[7][6] = std::make_unique<Pawn>(Pawn(black, board, pp8));
    }

    void Game_Descriptor::makeMove(std::pair<int, int> square0, std::pair<int, int> square){
        if(board[square0.first][square0.second] == nullptr){
            throw std::invalid_argument("Empty square");
        }
        else if(!board[square0.first][square0.second]->checkMove(square)){
            throw std::invalid_argument("Not available moves");
        }
        else{
            board[square.first][square.second] = std::move(board[square0.first][square0.second]);
        }
    }

    void Game_Descriptor::addPiece(std::pair<int, int> square, std::unique_ptr<Piece>& piece){
        if(board[square.first][square.second] != nullptr){
            throw std::invalid_argument("Busy square");
        }
        else{
            board[square.first][square.second] = std::move(piece);
        }
    }

    void Game_Descriptor::deletePiece(std::pair<int, int> square){
        if(board[square.first][square.second] == nullptr){
            throw std::invalid_argument("Empty square");
        }
        else{
            board[square.first][square.second] = nullptr;
        }
    }

    void Game_Descriptor::changePiece(std::pair<int, int> square, std::unique_ptr<Piece>& piece){
        this->deletePiece(square);
        this->addPiece(square, piece);
    }
}

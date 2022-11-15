#include "chess.h"

namespace CHESS{
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

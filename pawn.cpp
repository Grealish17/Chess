#include "chess.h"

namespace CHESS{

    Pawn::Pawn(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0): Piece(color, chessboard, square0){}

    std::vector<std::pair<int, int>> Pawn::getAvailableMoves() {
        std::vector<std::pair<int, int>> moves;
        if(position.second == 1){
            if(board[position.first][position.second + 2] == nullptr){
                moves.emplace_back(std::pair<int, int>{position.first, position.second + 2});
            }
        }

        if(board[position.first][position.second + 1] == nullptr){
            moves.emplace_back(std::pair<int, int>{position.first, position.second + 1});
        }

        if(position.first + 1 < 8){
            if(board[position.first + 1][position.second + 1] != nullptr){
                if(board[position.first + 1][position.second + 1]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first + 1, position.second + 1});
                }
            }
        }

        if(position.first - 1 >= 0){
            if(board[position.first - 1][position.second + 1] != nullptr){
                if(board[position.first - 1][position.second + 1]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first - 1, position.second + 1});
                }
            }
        }

        return moves;
    }

    std::string Pawn::getName(){
        return "Pawn";
    }

    char Pawn::getShortName(){
        if(get_color() == white){
            return 'P';
        }
        else{
            return 'p';
        }
    }
}

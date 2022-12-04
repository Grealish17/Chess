#include "chess.h"

namespace CHESS{

    King::King(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0): Piece(color, chessboard, square0){}

    std::vector<std::pair<int, int>> King::getAvailableMoves(){
        std::vector<std::pair<int, int>> moves;
        if(position.first + 1 < 8){
            if(board[position.first + 1][position.second ] != nullptr){
                if(board[position.first + 1][position.second ]->get_color() != get_color()){
                    //std::array<std::array<std::unique_ptr<Piece>, 8>, 8> chessboard = board;
                    moves.emplace_back(std::pair<int, int>{position.first + 1, position.second});
                }
            }
            else{

            }
        }
    }

    std::string King::getName(){
        return "King";
    }

    char King::getShortName(){
        if(get_color() == white){
            return 'K';
        }
        else{
            return 'k';
        }
    }
}

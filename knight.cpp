#include "chess.h"

namespace CHESS{

    Knight::Knight(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0): Piece(color, chessboard, square0){}

    std::vector<std::pair<int, int>> Knight::getAvailableMoves() {
        std::vector<std::pair<int, int>> moves;
        if(position.first + 2 < 8 && position.second + 1 < 8){
            if(board[position.first + 2][position.second + 1] != nullptr){
                if(board[position.first + 2][position.second + 1]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first + 2, position.second + 1});
                }
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first + 2, position.second + 1});
            }
        }

        if(position.first + 1 < 8 && position.second + 2 < 8){
            if(board[position.first + 1][position.second + 2] != nullptr){
                if(board[position.first + 1][position.second + 2]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first + 1, position.second + 2});
                }
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first + 1, position.second + 2});
            }
        }

        if(position.first + 2 < 8 && position.second - 1 >= 0){
            if(board[position.first + 2][position.second - 1] != nullptr){
                if(board[position.first + 2][position.second - 1]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first + 2, position.second - 1});
                }
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first + 2, position.second - 1});
            }
        }

        if(position.first + 1 < 8 && position.second - 2 >= 0){
            if(board[position.first + 1][position.second - 2] != nullptr){
                if(board[position.first + 1][position.second - 2]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first + 1, position.second - 2});
                }
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first + 1, position.second - 2});
            }
        }

        if(position.first - 2 >=0 && position.second + 1 < 8){
            if(board[position.first - 2][position.second + 1] != nullptr){
                if(board[position.first - 2][position.second + 1]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first - 2, position.second + 1});
                }
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first - 2, position.second + 1});
            }
        }

        if(position.first - 1 >= 0 && position.second + 2 < 8){
            if(board[position.first - 1][position.second + 2] != nullptr){
                if(board[position.first - 1][position.second + 2]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first - 1, position.second + 2});
                }
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first - 1, position.second + 2});
            }
        }

        if(position.first - 2 >= 8 && position.second - 1 >= 0){
            if(board[position.first - 2][position.second - 1] != nullptr){
                if(board[position.first - 2][position.second - 1]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first - 2, position.second - 1});
                }
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first - 2, position.second - 1});
            }
        }

        if(position.first - 1 >= 8 && position.second - 2 >= 0){
            if(board[position.first - 1][position.second - 2] != nullptr){
                if(board[position.first - 1][position.second - 2]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first - 1, position.second - 2});
                }
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first - 1, position.second - 2});
            }
        }

        return moves;
    }

    std::string Knight::getName(){
        return "Knight";
    }

    char Knight::getShortName(){
        if(get_color() == white){
            return 'N';
        }
        else{
            return 'n';
        }
    }
}
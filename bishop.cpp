#include "chess.h"

namespace CHESS{

    Bishop::Bishop(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0): Piece(color, chessboard, square0){}

    std::vector<std::pair<int, int>> Bishop::getAvailableMoves() {
        std::vector<std::pair<int, int>> moves;

        for(int i(1); i<(8-std::max(position.first, position.second)); ++i){
            if(board[position.first + i][position.second + i] != nullptr){
                if(board[position.first + i][position.second + i]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first + i, position.second + i});
                }
                break;
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first + i, position.second + i});
            }
        }

        for(int i(1); i<=(std::min(position.first, position.second)); ++i){
            if(board[position.first - i][position.second - i] != nullptr){
                if(board[position.first - i][position.second - i]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first - i, position.second - i});
                }
                break;
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first - i, position.second - i});
            }
        }

        for(int i(1); i<(std::min(8-position.second, position.first)); ++i){
            if(board[position.first - i][position.second + i] != nullptr){
                if(board[position.first - i][position.second + i]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first - i, position.second + i});
                }
                break;
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first - i, position.second + i});
            }
        }

        for(int i(1); i<(std::min(8-position.first, position.second)); ++i){
            if(board[position.first + i][position.second - i] != nullptr){
                if(board[position.first + i][position.second - i]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first + i, position.second - i});
                }
                break;
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first + i, position.second - i});
            }
        }
        return moves;
    }

    std::string Bishop::getName(){
        return "Bishop";
    }

    std::string Bishop::getShortName(){
        if(get_color() == white){
            return "B";
        }
        else{
            return "b";
        }
    }
}

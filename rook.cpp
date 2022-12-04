#include "chess.h"

namespace CHESS{

    Rook::Rook(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0): Piece(color, chessboard, square0){}

    std::vector<std::pair<int, int>> Rook::getAvailableMoves() {
        std::vector<std::pair<int, int>> moves;
        for(int i(1); i<(8-position.first); ++i){
            if(board[position.first + i][position.second] != nullptr){
                if(board[position.first + i][position.second]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first + i, position.second});
                }
                break;
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first + i, position.second});
            }
        }

        for(int i(1); i<=(position.first); ++i){
            if(board[position.first - i][position.second] != nullptr){
                if(board[position.first - i][position.second]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first - i, position.second});
                }
                break;
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first - i, position.second});
            }
        }

        for(int i(1); i<(8-position.second); ++i){
            if(board[position.first ][position.second + i] != nullptr){
                if(board[position.first][position.second + i]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first, position.second + i});
                }
                break;
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first, position.second + i});
            }
        }

        for(int i(1); i<=(position.second); ++i){
            if(board[position.first][position.second - i] != nullptr){
                if(board[position.first][position.second - i]->get_color() != get_color()){
                    moves.emplace_back(std::pair<int, int>{position.first, position.second - i});
                }
                break;
            }
            else{
                moves.emplace_back(std::pair<int, int>{position.first, position.second - i});
            }
        }
        return moves;
    }

    std::string Rook::getName(){
        return "Rook";
    }

    char Rook::getShortName(){
        if(get_color() == white){
            return 'R';
        }
        else{
            return 'r';
        }
    }
}

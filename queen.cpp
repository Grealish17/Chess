#include "chess.h"

namespace CHESS{

    Piece::Piece(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0): color(color), board(chessboard), position(square0){}
    COLOR Piece::get_color(){
        return color;
    }

    bool Piece::checkMove(std::pair<int, int> square){
        std::vector<std::pair<int, int>> moves = getAvailableMoves();
        if(std::find(moves.begin(), moves.end(), square) == moves.end()){
            return true;
        }
        else{
            return false;
        }
    }

    Queen::Queen(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0): Piece(color, chessboard, square0){}

    std::vector<std::pair<int, int>> Queen::getAvailableMoves() {
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

    std::string Queen::getName(){
        return "Queen";
    }

    char Queen::getShortName(){
        if(get_color() == white){
            return 'Q';
        }
        else{
            return 'q';
        }
    }
}

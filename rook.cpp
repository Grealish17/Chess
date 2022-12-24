#include "chess.h"

namespace CHESS{

    Rook::Rook(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0): Piece(color, game, square0){}

    std::vector<std::pair<int, int>> Rook::getAvailableMoves() {
        std::vector<std::pair<int, int>> moves;
        for(int i(1); i<(8-position.first); ++i){
            if(game.board[position.first + i][position.second] != nullptr){
                if(game.board[position.first + i][position.second]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first + i][position.second] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first + i, position.second);
                }
                break;
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first + i][position.second] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first + i, position.second);
            }
        }

        for(int i(1); i<=(position.first); ++i){
            if(game.board[position.first - i][position.second] != nullptr){
                if(game.board[position.first - i][position.second]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first - i][position.second] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first - i, position.second);
                }
                break;
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first - i][position.second] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first - i, position.second);
            }
        }

        for(int i(1); i<(8-position.second); ++i){
            if(game.board[position.first ][position.second + i] != nullptr){
                if(game.board[position.first][position.second + i]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first][position.second + i] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first, position.second + i);
                }
                break;
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first][position.second + i] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first, position.second + i);
            }
        }

        for(int i(1); i<=(position.second); ++i){
            if(game.board[position.first][position.second - i] != nullptr){
                if(game.board[position.first][position.second - i]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first][position.second - i] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first, position.second - i);
                }
                break;
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first][position.second - i] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first, position.second - i);
            }
        }
        return moves;
    }

    std::vector<std::pair<int, int>> Rook::getAvailableMovesWithoutCheck(){
        std::vector<std::pair<int, int>> moves;
        for(int i(1); i<(8-position.first); ++i){
            if(game.board[position.first + i][position.second] != nullptr){
                if(game.board[position.first + i][position.second]->get_color() != get_color()){
                    moves.emplace_back(position.first + i, position.second);
                }
                break;
            }
            else{
                moves.emplace_back(position.first + i, position.second);
            }
        }

        for(int i(1); i<=(position.first); ++i){
            if(game.board[position.first - i][position.second] != nullptr){
                if(game.board[position.first - i][position.second]->get_color() != get_color()){
                    moves.emplace_back(position.first - i, position.second);
                }
                break;
            }
            else{
                moves.emplace_back(position.first - i, position.second);
            }
        }

        for(int i(1); i<(8-position.second); ++i){
            if(game.board[position.first ][position.second + i] != nullptr){
                if(game.board[position.first][position.second + i]->get_color() != get_color()){
                    moves.emplace_back(position.first, position.second + i);
                }
                break;
            }
            else{
                moves.emplace_back(position.first, position.second + i);
            }
        }

        for(int i(1); i<=(position.second); ++i){
            if(game.board[position.first][position.second - i] != nullptr){
                if(game.board[position.first][position.second - i]->get_color() != get_color()){
                    moves.emplace_back(position.first, position.second - i);
                }
                break;
            }
            else{
                moves.emplace_back(position.first, position.second - i);
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

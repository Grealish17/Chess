#include "chess.h"

namespace CHESS{

    Bishop::Bishop(COLOR color,  Game_Descriptor& game, std::pair<int, int>& square0): Piece(color, game, square0){}

    std::vector<std::pair<int, int>> Bishop::getAvailableMoves() {
        std::vector<std::pair<int, int>> moves;

        for(int i(1); i<=(7-std::max(position.first, position.second)); ++i){
            if(game.board[position.first + i][position.second + i] != nullptr){
                if(game.board[position.first + i][position.second + i]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first + i][position.second + i] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first + i, position.second + i);
                }
                break;
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first + i][position.second + i] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first + i, position.second + i);
            }
        }

        for(int i(1); i<=(std::min(position.first, position.second)); ++i){
            if(game.board[position.first - i][position.second - i] != nullptr){
                if(game.board[position.first - i][position.second - i]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first - i][position.second - i] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first - i, position.second - i);
                }
                break;
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first - i][position.second - i] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first - i, position.second - i);
            }
        }

        for(int i(1); i<=(std::min(7-position.second, position.first)); ++i){
            if(game.board[position.first - i][position.second + i] != nullptr){
                if(game.board[position.first - i][position.second + i]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first - i][position.second + i] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first - i, position.second + i);
                }
                break;
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first - i][position.second + i] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first - i, position.second + i);
            }
        }

        for(int i(1); i<=(std::min(7-position.first, position.second)); ++i){
            if(game.board[position.first + i][position.second - i] != nullptr){
                if(game.board[position.first + i][position.second - i]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first + i][position.second - i] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first + i, position.second - i);
                }
                break;
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first + i][position.second - i] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first + i, position.second - i);
            }
        }

        return moves;
    }

    std::vector<std::pair<int, int>> Bishop::getAvailableMovesWithoutCheck(){
        std::vector<std::pair<int, int>> moves;

        for(int i(1); i<=(7-std::max(position.first, position.second)); ++i){
            if(game.board[position.first + i][position.second + i] != nullptr){
                if(game.board[position.first + i][position.second + i]->get_color() != get_color()){
                    moves.emplace_back(position.first + i, position.second + i);
                }
                break;
            }
            else{
                moves.emplace_back(position.first + i, position.second + i);
            }
        }

        for(int i(1); i<=(std::min(position.first, position.second)); ++i){
            if(game.board[position.first - i][position.second - i] != nullptr){
                if(game.board[position.first - i][position.second - i]->get_color() != get_color()){
                    moves.emplace_back(position.first - i, position.second - i);
                }
                break;
            }
            else{
                moves.emplace_back(position.first - i, position.second - i);
            }
        }

        for(int i(1); i<=(std::min(7-position.second, position.first)); ++i){
            if(game.board[position.first - i][position.second + i] != nullptr){
                if(game.board[position.first - i][position.second + i]->get_color() != get_color()){
                    moves.emplace_back(position.first - i, position.second + i);
                }
                break;
            }
            else{
                moves.emplace_back(position.first - i, position.second + i);
            }
        }

        for(int i(1); i<=(std::min(7-position.first, position.second)); ++i){
            if(game.board[position.first + i][position.second - i] != nullptr){
                if(game.board[position.first + i][position.second - i]->get_color() != get_color()){
                    moves.emplace_back(position.first + i, position.second - i);
                }
                break;
            }
            else{
                moves.emplace_back(position.first + i, position.second - i);
            }
        }
        return moves;
    }

    std::string Bishop::getName(){
        return "Bishop";
    }

    char Bishop::getShortName(){
        if(get_color() == white){
            return 'B';
        }
        else{
            return 'b';
        }
    }
}

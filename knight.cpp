#include "chess.h"

namespace CHESS{

    Knight::Knight(COLOR color,  Game_Descriptor& game, std::pair<int, int>& square0): Piece(color, game, square0){}

    std::vector<std::pair<int, int>> Knight::getAvailableMoves() {
        std::vector<std::pair<int, int>> moves;
        if(position.first + 2 < 8 && position.second + 1 < 8){
            if(game.board[position.first + 2][position.second + 1] != nullptr){
                if(game.board[position.first + 2][position.second + 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first + 2][position.second + 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first + 2, position.second + 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first + 2][position.second + 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first + 2, position.second + 1);
            }
        }

        if(position.first + 1 < 8 && position.second + 2 < 8){
            if(game.board[position.first + 1][position.second + 2] != nullptr){
                if(game.board[position.first + 1][position.second + 2]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first + 1][position.second + 2] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first + 1, position.second + 2);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first + 1][position.second + 2] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first + 1, position.second + 2);
            }
        }

        if(position.first + 2 < 8 && position.second - 1 >= 0){
            if(game.board[position.first + 2][position.second - 1] != nullptr){
                if(game.board[position.first + 2][position.second - 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first + 2][position.second - 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first + 2, position.second - 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first + 2][position.second - 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first + 2, position.second - 1);
            }
        }

        if(position.first + 1 < 8 && position.second - 2 >= 0){
            if(game.board[position.first + 1][position.second - 2] != nullptr){
                if(game.board[position.first + 1][position.second - 2]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first + 1][position.second - 2] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first + 1, position.second - 2);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first + 1][position.second - 2] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first + 1, position.second - 2);
            }
        }

        if(position.first - 2 >=0 && position.second + 1 < 8){
            if(game.board[position.first - 2][position.second + 1] != nullptr){
                if(game.board[position.first - 2][position.second + 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first - 2][position.second + 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first - 2, position.second + 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first - 2][position.second + 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first - 2, position.second + 1);
            }
        }

        if(position.first - 1 >= 0 && position.second + 2 < 8){
            if(game.board[position.first - 1][position.second + 2] != nullptr){
                if(game.board[position.first - 1][position.second + 2]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first - 1][position.second + 2] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first - 1, position.second + 2);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first - 1][position.second + 2] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first - 1, position.second + 2);
            }
        }

        if(position.first - 2 >= 0 && position.second - 1 >= 0){
            if(game.board[position.first - 2][position.second - 1] != nullptr){
                if(game.board[position.first - 2][position.second - 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first - 2][position.second - 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first - 2, position.second - 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first - 2][position.second - 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first - 2, position.second - 1);
            }
        }

        if(position.first - 1 >= 0 && position.second - 2 >= 0){
            if(game.board[position.first - 1][position.second - 2] != nullptr){
                if(game.board[position.first - 1][position.second - 2]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first - 1][position.second - 2] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first - 1, position.second - 2);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first - 1][position.second - 2] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first - 1, position.second - 2);
            }
        }

        return moves;
    }

    std::vector<std::pair<int, int>> Knight::getAvailableMovesWithoutCheck(){
        std::vector<std::pair<int, int>> moves;
        if(position.first + 2 < 8 && position.second + 1 < 8){
            if(game.board[position.first + 2][position.second + 1] != nullptr){
                if(game.board[position.first + 2][position.second + 1]->get_color() != get_color()){
                    moves.emplace_back(position.first + 2, position.second + 1);
                }
            }
            else{
                moves.emplace_back(position.first + 2, position.second + 1);
            }
        }

        if(position.first + 1 < 8 && position.second + 2 < 8){
            if(game.board[position.first + 1][position.second + 2] != nullptr){
                if(game.board[position.first + 1][position.second + 2]->get_color() != get_color()){
                    moves.emplace_back(position.first + 1, position.second + 2);
                }
            }
            else{
                moves.emplace_back(position.first + 1, position.second + 2);
            }
        }

        if(position.first + 2 < 8 && position.second - 1 >= 0){
            if(game.board[position.first + 2][position.second - 1] != nullptr){
                if(game.board[position.first + 2][position.second - 1]->get_color() != get_color()){
                    moves.emplace_back(position.first + 2, position.second - 1);
                }
            }
            else{
                moves.emplace_back(position.first + 2, position.second - 1);
            }
        }

        if(position.first + 1 < 8 && position.second - 2 >= 0){
            if(game.board[position.first + 1][position.second - 2] != nullptr){
                if(game.board[position.first + 1][position.second - 2]->get_color() != get_color()){
                    moves.emplace_back(position.first + 1, position.second - 2);
                }
            }
            else{
                moves.emplace_back(position.first + 1, position.second - 2);
            }
        }

        if(position.first - 2 >=0 && position.second + 1 < 8){
            if(game.board[position.first - 2][position.second + 1] != nullptr){
                if(game.board[position.first - 2][position.second + 1]->get_color() != get_color()){
                    moves.emplace_back(position.first - 2, position.second + 1);
                }
            }
            else{
                moves.emplace_back(position.first - 2, position.second + 1);
            }
        }

        if(position.first - 1 >= 0 && position.second + 2 < 8){
            if(game.board[position.first - 1][position.second + 2] != nullptr){
                if(game.board[position.first - 1][position.second + 2]->get_color() != get_color()){
                    moves.emplace_back(position.first - 1, position.second + 2);
                }
            }
            else{
                moves.emplace_back(position.first - 1, position.second + 2);
            }
        }

        if(position.first - 2 >= 8 && position.second - 1 >= 0){
            if(game.board[position.first - 2][position.second - 1] != nullptr){
                if(game.board[position.first - 2][position.second - 1]->get_color() != get_color()){
                    moves.emplace_back(position.first - 2, position.second - 1);
                }
            }
            else{
                moves.emplace_back(position.first - 2, position.second - 1);
            }
        }

        if(position.first - 1 >= 8 && position.second - 2 >= 0){
            if(game.board[position.first - 1][position.second - 2] != nullptr){
                if(game.board[position.first - 1][position.second - 2]->get_color() != get_color()){
                    moves.emplace_back(position.first - 1, position.second - 2);
                }
            }
            else{
                moves.emplace_back(position.first - 1, position.second - 2);
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
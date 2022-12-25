#include "chess.h"

namespace CHESS{

    Pawn::Pawn(COLOR color,  Game_Descriptor& game, std::pair<int, int>& square0): Piece(color, game, square0){}

    std::string Pawn::toNotation(std::pair<int, int> square){
        std::string s = to_string(square);
        return s;
    }

    std::vector<std::pair<int, int>> Pawn::getAvailableMoves() {
        std::vector<std::pair<int, int>> moves;
        if(this->get_color() == white)
        {
            if(position.second == 1){
                if(game.board[position.first][position.second + 2] == nullptr){
                    Game_Descriptor test(game);
                    test.board[position.first][position.second + 2] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first, position.second + 2);
                }
            }

            if(game.board[position.first][position.second + 1] == nullptr){
                Game_Descriptor test(game);
                test.board[position.first][position.second + 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first, position.second + 1);
            }

            if(position.first + 1 < 8){
                if(game.board[position.first + 1][position.second + 1] != nullptr){
                    if(game.board[position.first + 1][position.second + 1]->get_color() != get_color()){
                        Game_Descriptor test(game);
                        test.board[position.first + 1][position.second + 1] = std::move(test.board[position.first][position.second]);
                        if(!test.CheckCheck(test.turn))
                            moves.emplace_back(position.first + 1, position.second + 1);
                    }
                }
            }

            if(position.first - 1 >= 0){
                if(game.board[position.first - 1][position.second + 1] != nullptr){
                    if(game.board[position.first - 1][position.second + 1]->get_color() != get_color()){
                        Game_Descriptor test(game);
                        test.board[position.first - 1][position.second + 1] = std::move(test.board[position.first][position.second]);
                        if(!test.CheckCheck(test.turn))
                            moves.emplace_back(position.first - 1, position.second + 1);
                    }
                }
            }
        }
        else{
            if(position.second == 6){
                if(game.board[position.first][position.second - 2] == nullptr){
                    Game_Descriptor test(game);
                    test.board[position.first][position.second - 2] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first, position.second - 2);
                }
            }

            if(game.board[position.first][position.second - 1] == nullptr){
                Game_Descriptor test(game);
                test.board[position.first][position.second - 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first, position.second - 1);
            }

            if(position.first + 1 < 8){
                if(game.board[position.first + 1][position.second - 1] != nullptr){
                    if(game.board[position.first + 1][position.second - 1]->get_color() != get_color()){
                        Game_Descriptor test(game);
                        test.board[position.first + 1][position.second - 1] = std::move(test.board[position.first][position.second]);
                        if(!test.CheckCheck(test.turn))
                            moves.emplace_back(position.first + 1, position.second - 1);
                    }
                }
            }

            if(position.first - 1 >= 0){
                if(game.board[position.first - 1][position.second - 1] != nullptr){
                    if(game.board[position.first - 1][position.second - 1]->get_color() != get_color()){
                        Game_Descriptor test(game);
                        test.board[position.first - 1][position.second - 1] = std::move(test.board[position.first][position.second]);
                        if(!test.CheckCheck(test.turn))
                            moves.emplace_back(position.first - 1, position.second - 1);
                    }
                }
            }
        }

        return moves;
    }

    std::vector<std::pair<int, int>> Pawn::getAvailableMovesWithoutCheck(){
        std::vector<std::pair<int, int>> moves;
        if(this->get_color() == white)
        {
            if(position.first + 1 < 8){
                if(game.board[position.first + 1][position.second + 1] != nullptr){
                    if(game.board[position.first + 1][position.second + 1]->get_color() != get_color()){
                        moves.emplace_back(position.first + 1, position.second + 1);
                    }
                }
            }

            if(position.first - 1 >= 0){
                if(game.board[position.first - 1][position.second + 1] != nullptr){
                    if(game.board[position.first - 1][position.second + 1]->get_color() != get_color()){
                        moves.emplace_back(position.first - 1, position.second + 1);
                    }
                }
            }
        }
        else{
            if(position.first + 1 < 8){
                if(game.board[position.first + 1][position.second - 1] != nullptr){
                    if(game.board[position.first + 1][position.second - 1]->get_color() != get_color()){
                        moves.emplace_back(position.first + 1, position.second - 1);
                    }
                }
            }

            if(position.first - 1 >= 0){
                if(game.board[position.first - 1][position.second - 1] != nullptr){
                    if(game.board[position.first - 1][position.second - 1]->get_color() != get_color()){
                        moves.emplace_back(position.first - 1, position.second - 1);
                    }
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

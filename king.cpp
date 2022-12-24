#include "chess.h"

namespace CHESS{

    King::King(COLOR color,  Game_Descriptor& game, std::pair<int, int>& square0): Piece(color, game, square0){}

    std::vector<std::pair<int, int>> King::getAvailableMoves(){
        std::vector<std::pair<int, int>> moves;
        if(position.first + 1 < 8){
            if(game.board[position.first + 1][position.second] != nullptr){
                if(game.board[position.first + 1][position.second]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first + 1][position.second] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                        moves.emplace_back(position.first + 1, position.second);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first + 1][position.second] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                    moves.emplace_back(position.first + 1, position.second);
            }
        }

        if(position.first - 1 >= 0){
            if(game.board[position.first - 1][position.second] != nullptr){
                if(game.board[position.first - 1][position.second]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first - 1][position.second] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                        moves.emplace_back(position.first - 1, position.second);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first - 1][position.second] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                    moves.emplace_back(position.first - 1, position.second);
            }
        }

        if(position.second + 1 < 8){
            if(game.board[position.first][position.second + 1] != nullptr){
                if(game.board[position.first][position.second + 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first][position.second + 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                        moves.emplace_back(position.first, position.second + 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first][position.second + 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                    moves.emplace_back(position.first, position.second + 1);
            }
        }

        if(position.second - 1 >= 0){
            if(game.board[position.first][position.second - 1] != nullptr){
                if(game.board[position.first][position.second - 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first][position.second - 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                        moves.emplace_back(position.first, position.second - 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first][position.second - 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                    moves.emplace_back(position.first, position.second - 1);
            }
        }

        if(position.first + 1 < 8 && position.second + 1 < 8){
            if(game.board[position.first + 1][position.second + 1] != nullptr){
                if(game.board[position.first + 1][position.second + 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first + 1][position.second + 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                        moves.emplace_back(position.first + 1, position.second + 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first + 1][position.second + 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                    moves.emplace_back(position.first + 1, position.second + 1);
            }
        }

        if(position.first - 1 >= 0 && position.second + 1 < 8){
            if(game.board[position.first - 1][position.second + 1] != nullptr){
                if(game.board[position.first - 1][position.second + 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first - 1][position.second + 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                        moves.emplace_back(position.first - 1, position.second + 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first - 1][position.second + 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                    moves.emplace_back(position.first - 1, position.second + 1);
            }
        }

        if(position.first + 1 < 8 && position.second - 1 >= 0){
            if(game.board[position.first + 1][position.second - 1] != nullptr){
                if(game.board[position.first + 1][position.second - 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first + 1][position.second - 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                        moves.emplace_back(position.first + 1, position.second - 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first + 1][position.second - 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                    moves.emplace_back(position.first + 1, position.second - 1);
            }
        }

        if(position.first - 1 >= 0 && position.second - 1 >= 0){
            if(game.board[position.first - 1][position.second - 1] != nullptr){
                if(game.board[position.first - 1][position.second - 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first - 1][position.second - 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                        moves.emplace_back(position.first - 1, position.second - 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first - 1][position.second - 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn) && !test.CheckCheckmate(test.turn))
                    moves.emplace_back(position.first - 1, position.second - 1);
            }
        }

        return moves;
    }

    std::vector<std::pair<int, int>> King::getAvailableMovesWithoutCheck(){
        std::vector<std::pair<int, int>> moves;
        if(position.first + 1 < 8){
            if(game.board[position.first + 1][position.second] != nullptr){
                if(game.board[position.first + 1][position.second]->get_color() != get_color()){
                    moves.emplace_back(position.first + 1, position.second);
                }
            }
            else{
                moves.emplace_back(position.first + 1, position.second);
            }
        }

        if(position.first - 1 >= 0){
            if(game.board[position.first - 1][position.second] != nullptr){
                if(game.board[position.first - 1][position.second]->get_color() != get_color()){
                    moves.emplace_back(position.first - 1, position.second);
                }
            }
            else{
                moves.emplace_back(position.first - 1, position.second);
            }
        }

        if(position.second + 1 < 8){
            if(game.board[position.first][position.second + 1] != nullptr){
                if(game.board[position.first][position.second + 1]->get_color() != get_color()){
                    moves.emplace_back(position.first, position.second + 1);
                }
            }
            else{
                moves.emplace_back(position.first, position.second + 1);
            }
        }

        if(position.second - 1 >= 0){
            if(game.board[position.first][position.second - 1] != nullptr){
                if(game.board[position.first][position.second - 1]->get_color() != get_color()){
                    moves.emplace_back(position.first, position.second - 1);
                }
            }
            else{
                moves.emplace_back(position.first, position.second - 1);
            }
        }

        if(position.first + 1 < 8 && position.second + 1 < 8){
            if(game.board[position.first + 1][position.second + 1] != nullptr){
                if(game.board[position.first + 1][position.second + 1]->get_color() != get_color()){
                    moves.emplace_back(position.first + 1, position.second + 1);
                }
            }
            else{
                moves.emplace_back(position.first + 1, position.second + 1);
            }
        }

        if(position.first - 1 >= 0 && position.second + 1 < 8){
            if(game.board[position.first - 1][position.second + 1] != nullptr){
                if(game.board[position.first - 1][position.second + 1]->get_color() != get_color()){
                    moves.emplace_back(position.first - 1, position.second + 1);
                }
            }
            else{
                moves.emplace_back(position.first - 1, position.second + 1);
            }
        }

        if(position.first + 1 < 8 && position.second - 1 >= 0){
            if(game.board[position.first + 1][position.second - 1] != nullptr){
                if(game.board[position.first + 1][position.second - 1]->get_color() != get_color()){
                    moves.emplace_back(position.first + 1, position.second - 1);
                }
            }
            else{
                moves.emplace_back(position.first + 1, position.second - 1);
            }
        }

        if(position.first - 1 >= 0 && position.second - 1 >= 0){
            if(game.board[position.first - 1][position.second - 1] != nullptr){
                if(game.board[position.first - 1][position.second - 1]->get_color() != get_color()){
                    moves.emplace_back(position.first - 1, position.second - 1);
                }
            }
            else{
                moves.emplace_back(position.first - 1, position.second - 1);
            }
        }

        return moves;
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

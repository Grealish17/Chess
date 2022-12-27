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
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first + 1, position.second);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first + 1][position.second] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first + 1, position.second);
            }
        }

        if(position.first - 1 >= 0){
            if(game.board[position.first - 1][position.second] != nullptr){
                if(game.board[position.first - 1][position.second]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first - 1][position.second] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first - 1, position.second);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first - 1][position.second] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first - 1, position.second);
            }
        }

        if(position.second + 1 < 8){
            if(game.board[position.first][position.second + 1] != nullptr){
                if(game.board[position.first][position.second + 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first][position.second + 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first, position.second + 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first][position.second + 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first, position.second + 1);
            }
        }

        if(position.second - 1 >= 0){
            if(game.board[position.first][position.second - 1] != nullptr){
                if(game.board[position.first][position.second - 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first][position.second - 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first, position.second - 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first][position.second - 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first, position.second - 1);
            }
        }

        if(position.first + 1 < 8 && position.second + 1 < 8){
            if(game.board[position.first + 1][position.second + 1] != nullptr){
                if(game.board[position.first + 1][position.second + 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first + 1][position.second + 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first + 1, position.second + 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first + 1][position.second + 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first + 1, position.second + 1);
            }
        }

        if(position.first - 1 >= 0 && position.second + 1 < 8){
            if(game.board[position.first - 1][position.second + 1] != nullptr){
                if(game.board[position.first - 1][position.second + 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first - 1][position.second + 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first - 1, position.second + 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first - 1][position.second + 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first - 1, position.second + 1);
            }
        }

        if(position.first + 1 < 8 && position.second - 1 >= 0){
            if(game.board[position.first + 1][position.second - 1] != nullptr){
                if(game.board[position.first + 1][position.second - 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first + 1][position.second - 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first + 1, position.second - 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first + 1][position.second - 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first + 1, position.second - 1);
            }
        }

        if(position.first - 1 >= 0 && position.second - 1 >= 0){
            if(game.board[position.first - 1][position.second - 1] != nullptr){
                if(game.board[position.first - 1][position.second - 1]->get_color() != get_color()){
                    Game_Descriptor test(game);
                    test.board[position.first - 1][position.second - 1] = std::move(test.board[position.first][position.second]);
                    if(!test.CheckCheck(test.turn))
                        moves.emplace_back(position.first - 1, position.second - 1);
                }
            }
            else{
                Game_Descriptor test(game);
                test.board[position.first - 1][position.second - 1] = std::move(test.board[position.first][position.second]);
                if(!test.CheckCheck(test.turn))
                    moves.emplace_back(position.first - 1, position.second - 1);
            }
        }

        if(this->get_color() == white && game.castlingWhiteIsAvailable){
            if(position.first == 4 && position.second == 0 && this->game.board[7][0] != nullptr && this->game.board[6][0] == nullptr && this->game.board[5][0] == nullptr){
                if(this->game.board[7][0]->getShortName() == 'R'){
                    Game_Descriptor test(game);
                    test.board[5][0] = std::move(test.board[4][0]);
                    if(!test.CheckCheck(test.turn)){
                        Game_Descriptor test2(game);
                        test2.board[6][0] = std::move(test2.board[4][0]);
                        if(!test2.CheckCheck(test2.turn))
                            moves.emplace_back(6, 0);
                    }
                }
            }
            if(position.first == 4 && position.second == 0 && this->game.board[0][0] != nullptr && this->game.board[3][0] == nullptr && this->game.board[2][0] == nullptr && this->game.board[1][0] == nullptr){
                if(this->game.board[0][0]->getShortName() == 'R'){
                    Game_Descriptor test(game);
                    test.board[3][0] = std::move(test.board[4][0]);
                    if(!test.CheckCheck(test.turn)){
                        Game_Descriptor test2(game);
                        test2.board[2][0] = std::move(test2.board[4][0]);
                        if(!test2.CheckCheck(test2.turn))
                            moves.emplace_back(2, 0);
                    }
                }
            }
        }
        else if(game.castlingBlackIsAvailable){
            if(position.first == 4 && position.second == 7 && this->game.board[7][7] != nullptr && this->game.board[6][7] == nullptr && this->game.board[5][7] == nullptr){
                if(this->game.board[7][7]->getShortName() == 'r'){
                    Game_Descriptor test(game);
                    test.board[5][7] = std::move(test.board[4][7]);
                    if(!test.CheckCheck(test.turn)){
                        Game_Descriptor test2(game);
                        test2.board[6][7] = std::move(test2.board[4][7]);
                        if(!test2.CheckCheck(test2.turn))
                            moves.emplace_back(6, 7);
                    }
                }
            }
            if(position.first == 4 && position.second == 7 && this->game.board[0][7] != nullptr && this->game.board[3][7] == nullptr && this->game.board[2][7] == nullptr && this->game.board[1][7] == nullptr){
                if(this->game.board[0][7]->getShortName() == 'r'){
                    Game_Descriptor test(game);
                    test.board[3][7] = std::move(test.board[4][7]);
                    if(!test.CheckCheck(test.turn)){
                        Game_Descriptor test2(game);
                        test2.board[2][7] = std::move(test2.board[4][7]);
                        if(!test2.CheckCheck(test2.turn)) {
                            moves.emplace_back(2, 7);
                        }
                    }
                }
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

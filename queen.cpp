#include "chess.h"

namespace CHESS{

    Piece::Piece(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0): color(color), game(game), position(square0){}
    COLOR Piece::get_color(){
        return color;
    }

    bool Piece::checkMove(std::pair<int, int> square){
        std::vector<std::pair<int, int>> moves = getAvailableMoves();
        if(std::find(moves.begin(), moves.end(), square) != moves.end()){
            return true;
        }
        else{
            return false;
        }
    }

    void Piece::setPosition(std::pair<int, int> square){
        position = square;
    }

    std::string Piece::toNotation(std::pair<int, int> square){
        std::string s = " ";
        s[0] = toupper(this->getShortName());
        s += to_string(square);
        return s;
    }

    Queen::Queen(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0): Piece(color, game, square0){}

    std::vector<std::pair<int, int>> Queen::getAvailableMoves(){
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
                    if(game.board[position.first][position.second - i]->get_color() != get_color()){
                        Game_Descriptor test(game);
                        test.board[position.first][position.second - i] = std::move(test.board[position.first][position.second]);
                        if(!test.CheckCheck(test.turn))
                            moves.emplace_back(position.first, position.second - i);
                    }
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

        for(int i(1); i<(8-std::max(position.first, position.second)); ++i){
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

        for(int i(1); i<(std::min(8-position.second, position.first)); ++i){
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

        for(int i(1); i<(std::min(8-position.first, position.second)); ++i){
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

    std::vector<std::pair<int, int>> Queen::getAvailableMovesWithoutCheck(){
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

        for(int i(1); i<(8-std::max(position.first, position.second)); ++i){
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

        for(int i(1); i<(std::min(8-position.second, position.first)); ++i){
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

        for(int i(1); i<(std::min(8-position.first, position.second)); ++i){
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

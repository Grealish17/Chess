#include "chess.h"

namespace CHESS{

    King::King(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0): Piece(color, chessboard, square0){}

    std::string King::getName(){
        return "King";
    }

    std::string King::getShortName(){
        if(get_color() == white){
            return "K";
        }
        else{
            return "k";
        }
    }
}

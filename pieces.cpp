#include "chess.h"

namespace CHESS{
    King::King(COLOR color): Piece(color){
        this->color = color;
    }

    Piece::Piece(COLOR color){
        this->color = color;
    }
}

#include "chess.h"

namespace CHESS{
    void Game_History::addMove(const std::string& move){
        moves.push_back(move);
    }
}

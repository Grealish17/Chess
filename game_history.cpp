#include "chess.h"
#include <fstream>

namespace CHESS{
    std::string to_string(std::pair<int, int> square){
        std::string s = "  ";
        s[0] = 'a' + square.first;
        s[1] = '1' + square.second;
        return s;
    }

    void Game_History::addMove(const std::string& move){
        moves.push_back(move);
    }

    bool Game_History::saveToFile(const std::string& file_name){
        std::ofstream fout;
        fout.open(file_name);
        if(!fout.is_open()){
            std::cout << "Файл не найден!" << std::endl;
            return false;
        }
        else{
            int k(0);
            for(std::string& move: moves){
                if(k%2 == 0)
                    fout << std::to_string(k/2 + 1) + " :   " + move + "   ";
                else
                    fout << move + "\n";
                ++k;
            }
        }
        fout.close();
        return true;
    }
}

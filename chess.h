#include <iostream>
#include <list>
#include <vector>

namespace CHESS{
    std::string toNotation(std::string name, std::pair<int, int> square);

    class Piece{
    private:
        bool color;
    public:
        bool checkMove(std::pair<int, int> square);
        std::string getShortName();
        std::vector<std::pair<int, int>> getAvailableMoves();
        std::string getName();
    };

    class Game_History{
    private:
        std::list<std::string> moves;
    public:
        void addMove(std::string move);
    };

    class Game_Descriptor{
    private:
        Piece board[8][8];
        Game_History history;
        bool turn;
        std::string status;
        std::string verdict;
    public:
        void makeMove(std::pair<int, int> square0, std::pair<int, int> square);
    };
}
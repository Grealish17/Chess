#include <iostream>
#include <list>
#include <vector>

namespace CHESS{
    std::string toNotation(std::string name, std::pair<int, int> square);

    class Piece{
    private:
        bool color;
    public:
        explicit Piece(bool color){
            this->color = color;
        }
        virtual bool checkMove(std::pair<int, int> square) = 0;
        virtual std::string getShortName() = 0;
        virtual std::vector<std::pair<int, int>> getAvailableMoves() = 0;
        virtual std::string getName() = 0;
    };

    class Game_History{
    private:
        std::list<std::string> moves;
    public:
        void addMove(std::string move);
    };

    class Game_Descriptor{
    private:
        Piece* board[8][8];
        Game_History history;
        bool turn;
        std::string status;
        std::string verdict;
    public:
        void makeMove(std::pair<int, int> square0, std::pair<int, int> square);
    };

    class King: public Piece{
    private:
        bool color;
    public:
        explicit King(bool color): Piece(color){
            this->color = color;
        }
        bool checkMove(std::pair<int, int> square) override;
        std::string getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::string getName() override;
    };
}
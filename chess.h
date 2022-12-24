//#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <memory>
#include <algorithm>

namespace CHESS{

    enum COLOR{
        black,
        white
    };

    COLOR& inverse(COLOR& color);

    enum STATUS{
        GameIsOn,
        NoGame,
        WhiteWin,
        BlackWin,
        Draw
    };

    std::string to_string(STATUS status);

    enum VERDICT{
        Checkmate,
        Check,
        Stalemate,
        Nothing
    };

    std::string to_string(VERDICT verdict);

    class Game_Descriptor;

    class Piece{
    protected:
        std::pair<int, int> position;
        Game_Descriptor& game;
    private:
        COLOR color;
    public:
        explicit Piece(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0);
        bool checkMove(std::pair<int, int> square);
        void setPosition(std::pair<int, int> square);
        virtual char getShortName() = 0;
        virtual std::vector<std::pair<int, int>> getAvailableMoves() = 0;
        virtual std::vector<std::pair<int, int>> getAvailableMovesWithoutCheck() = 0;
        virtual std::string getName() = 0;
        //virtual std::string toNotation(std::pair<int, int> square) = 0;//realization
        COLOR get_color();
    };

    class Game_History{
    private:
        std::list<std::string> moves;
    public:
        void addMove(const std::string& move);
        //void readFromFile(std::string file_name);
    };

    class Game_Descriptor{
    public:
        std::array<std::array<std::unique_ptr<Piece>, 8>, 8> board;
        Game_History history;
        COLOR turn = white;
        STATUS status = NoGame;
        VERDICT verdict = Nothing;
        void addPiece(std::pair<int, int> square, Piece& piece);
        void deletePiece(std::pair<int, int> square);
    public:
        explicit Game_Descriptor();
        Game_Descriptor(Game_Descriptor& game);
        void makeMove(std::pair<int, int> square0, std::pair<int, int> square);
        void changePiece(std::pair<int, int> square, Piece& piece);
        
        bool CheckCheckmate(COLOR color);
        bool CheckCheck(COLOR color);
        bool CheckStalemate(COLOR color);
    };

    class King: public Piece{
    public:
        explicit King(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0);
        char getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::vector<std::pair<int, int>> getAvailableMovesWithoutCheck() override;
        std::string getName() override;
    };

    class Queen: public Piece{
    public:
        explicit Queen(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0);
        char getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::vector<std::pair<int, int>> getAvailableMovesWithoutCheck() override;
        std::string getName() override;
    };

    class Rook: public Piece{
    public:
        explicit Rook(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0);
        char getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::vector<std::pair<int, int>> getAvailableMovesWithoutCheck() override;
        std::string getName() override;
    };

    class Bishop: public Piece{
    public:
        explicit Bishop(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0);
        char getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::vector<std::pair<int, int>> getAvailableMovesWithoutCheck() override;
        std::string getName() override;
    };

    class Knight: public Piece{
    public:
        explicit Knight(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0);
        char getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::vector<std::pair<int, int>> getAvailableMovesWithoutCheck() override;
        std::string getName() override;
    };

    class Pawn: public Piece{
    public:
        explicit Pawn(COLOR color, Game_Descriptor& game, std::pair<int, int>& square0);
        char getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::vector<std::pair<int, int>> getAvailableMovesWithoutCheck() override;
        std::string getName() override;
    };

}
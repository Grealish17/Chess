#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <memory>
#include <algorithm>
#include <SFML/Graphics.hpp>

const int FIELD_SIZE = 800;
const int SQUARE_SIZE = 100;

namespace CHESS{

    enum COLOR{
        black,
        white
    };

    enum STATUS{
        GameIsOn,
        NoGame,
        NewGame,
        WhiteWin,
        BlackWin,
        Draw
    };

    enum VERDICT{
        Checkmate,
        Check,
        Stalemate,
        ThreefoldRepetition,
        DeadPosition,
        Nothing
    };

    //class Game_Descriptor;

    class Piece{
    protected:
        std::pair<int, int> position;
        const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board;
    private:
        COLOR color;
    public:
        explicit Piece(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0);
        bool checkMove(std::pair<int, int> square);
        virtual char getShortName() = 0;
        virtual std::vector<std::pair<int, int>> getAvailableMoves() = 0;
        virtual std::string getName() = 0;
        //friend Game_Descriptor;
        //virtual std::string toNotation(std::pair<int, int> square) = 0;//realization
        COLOR get_color();
    };

    class Game_History{
    private:
        std::list<std::string> moves;
    public:
        void addMove(const std::string& move);
        void readFromFile(std::string file_name);
    };

    class Game_Descriptor : public sf::Drawable, public sf::Transformable{
    private:
        std::array<std::array<std::unique_ptr<Piece>, 8>, 8> board;
        Game_History history;
        COLOR turn = white;
        STATUS status = NoGame;
        VERDICT verdict = Nothing;
        sf::Font font;
        void addPiece(std::pair<int, int> square, std::unique_ptr<Piece>& piece);
        void deletePiece(std::pair<int, int> square);
    public:
        explicit Game_Descriptor();
        explicit Game_Descriptor(std::array<std::array<std::unique_ptr<Piece>, 8>, 8> board, COLOR turn, STATUS status, VERDICT verdict);
        void makeMove(std::pair<int, int> square0, std::pair<int, int> square);
        void changePiece(std::pair<int, int> square, std::unique_ptr<Piece>& piece);
        bool CheckCheckmate(COLOR color);
        bool CheckCheck(COLOR color);
        void CheckDeadPosition();
        void CheckThreefoldRepetition();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };

    class King: public Piece{
    public:
        explicit King(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0);
        char getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::string getName() override;
    };

    class Queen: public Piece{
    public:
        explicit Queen(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0);
        char getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::string getName() override;
    };

    class Rook: public Piece{
    public:
        explicit Rook(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0);
        char getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::string getName() override;
    };

    class Bishop: public Piece{
    public:
        explicit Bishop(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0);
        char getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::string getName() override;
    };

    class Knight: public Piece{
    public:
        explicit Knight(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0);
        char getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::string getName() override;
    };

    class Pawn: public Piece{
    public:
        explicit Pawn(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0);
        char getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::string getName() override;
    };

    class PieceTextures{
    public:
        static sf::Texture blackKing;
        static sf::Texture blackQueen;
        static sf::Texture blackRook;
        static sf::Texture blackKnight;
        static sf::Texture blackBishop;
        static sf::Texture blackPawn;

        static sf::Texture whiteKing;
        static sf::Texture whiteQueen;
        static sf::Texture whiteRook;
        static sf::Texture whiteKnight;
        static sf::Texture whiteBishop;
        static sf::Texture whitePawn;

        static sf::Texture loadTexture(const std::string& str);
    };

}
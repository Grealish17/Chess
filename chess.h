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

    class Piece{
    protected:
        std::pair<int, int> position;
        const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board;
    private:
        COLOR color;
    public:
        explicit Piece(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0);
        bool checkMove(std::pair<int, int> square);
        virtual std::string getShortName() = 0;
        virtual std::vector<std::pair<int, int>> getAvailableMoves() = 0;
        virtual std::string getName() = 0;
        virtual std::string toNotation(std::pair<int, int> square) = 0;//realization
        COLOR get_color();
    };

    class Game_History{
    private:
        std::list<std::string> moves;
    public:
        void addMove(const std::string& move);
        void readFromFile(std::string file_name);
    };

    class Game_Descriptor{
    private:
        std::array<std::array<std::unique_ptr<Piece>, 8>, 8> board;
        Game_History history;
        COLOR turn = white;
        STATUS status = NoGame;
        VERDICT verdict = Nothing;
        void addPiece(std::pair<int, int> square, std::unique_ptr<Piece>& piece);
        void deletePiece(std::pair<int, int> square);
    public:
        void makeMove(std::pair<int, int> square0, std::pair<int, int> square);
        void changePiece(std::pair<int, int> square, std::unique_ptr<Piece>& piece);
        void CheckOrCheckmate();
        void CheckDeadPosition();
        void CheckThreefoldRepetition();
    };

    class King: public Piece{
    public:
        explicit King(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0);
        std::string getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::string getName() override;
    };

    class Queen: public Piece{
    public:
        explicit Queen(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0);
        std::string getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::string getName() override;
    };

    class Rook: public Piece{
    public:
        explicit Rook(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0);
        std::string getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::string getName() override;
    };

    class Bishop: public Piece{
    public:
        explicit Bishop(COLOR color, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& chessboard, std::pair<int, int>& square0);
        std::string getShortName() override;
        std::vector<std::pair<int, int>> getAvailableMoves() override;
        std::string getName() override;
    };
}
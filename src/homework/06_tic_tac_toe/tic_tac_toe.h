#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <string>
#include <vector>
#include <iostream>

class TicTacToe
{
public:
    TicTacToe() = default;

    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over();
    std::string get_player() const { return player; }
    std::string get_winner() const { return winner; }

    // I/O operator overloads
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

private:
    std::vector<std::string> pegs{9, " "};
    std::string player;
    std::string winner;

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToe
{
    public:
        bool game_over();
        void start_game(std::string first_player);
        void mark_board(int position);
        std::string get_player() const {return player;}
        void display_board()const;
    private:
    std::string player;
    std::vector<std::string> pegs{9, " "};
    void set_next_player();
    bool check_board_full();
    void clear_board();

};

#endif

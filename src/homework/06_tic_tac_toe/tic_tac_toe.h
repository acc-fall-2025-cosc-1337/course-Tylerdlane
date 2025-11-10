#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class TicTacToe
{
public:
    void start_game(string first_player);
    void mark_board(int position);
    void display_board() const;
    bool game_over();
    string get_player() const { return player; }
    string get_winner() const { return winner; }

private:
    string player;
    string winner;
    vector<string> pegs{9, " "};

    void set_next_player();
    bool check_board_full() const;
    void clear_board();
    void set_winner();
    bool check_column_win() const;
    bool check_row_win() const;
    bool check_diagonal_win() const;
};

#endif

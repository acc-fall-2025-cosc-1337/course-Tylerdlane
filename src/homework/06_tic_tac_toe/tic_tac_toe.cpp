#include "tic_tac_toe.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void TicTacToe::start_game(string first_player)
{
    if (first_player == "X" || first_player == "O")
    {
        player = first_player;
        clear_board();
    }
    else
    {
        cout << "Invalid first player. Must be X or O.\n";
    }
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::display_board() const
{
    for (int i = 0; i < 9; i += 3)
    {
        cout << pegs[i] << " | " << pegs[i + 1] << " | " << pegs[i + 2] << "\n";
    }
}

void TicTacToe::set_next_player()
{
    if (player == "X")
        player = "O";
    else
        player = "X";
}

bool TicTacToe::check_board_full() const
{
    for (auto peg : pegs)
    {
        if (peg == " ")
            return false;
    }
    return true;
}

void TicTacToe::clear_board()
{
    for (auto &peg : pegs)
    {
        peg = " ";
    }
}

bool TicTacToe::check_column_win() const
{
    return ((pegs[0] != " " && pegs[0] == pegs[3] && pegs[3] == pegs[6]) ||
            (pegs[1] != " " && pegs[1] == pegs[4] && pegs[4] == pegs[7]) ||
            (pegs[2] != " " && pegs[2] == pegs[5] && pegs[5] == pegs[8]));
}

bool TicTacToe::check_row_win() const
{
    return ((pegs[0] != " " && pegs[0] == pegs[1] && pegs[1] == pegs[2]) ||
            (pegs[3] != " " && pegs[3] == pegs[4] && pegs[4] == pegs[5]) ||
            (pegs[6] != " " && pegs[6] == pegs[7] && pegs[7] == pegs[8]));
}

bool TicTacToe::check_diagonal_win() const
{
    return ((pegs[0] != " " && pegs[0] == pegs[4] && pegs[4] == pegs[8]) ||
            (pegs[6] != " " && pegs[6] == pegs[4] && pegs[4] == pegs[2]));
}

void TicTacToe::set_winner()
{
    if (player == "X")
        winner = "O";
    else
        winner = "X";
}

bool TicTacToe::game_over()
{
    if (check_row_win() || check_column_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }
    else if (check_board_full())
    {
        winner = "C"; // tie (cat’s game)
        return true;
    }
    return false;
}

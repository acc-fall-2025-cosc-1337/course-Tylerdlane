#include "tic_tac_toe.h"
#include <cmath>


void TicTacToe::start_game(std::string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

bool TicTacToe::game_over()
{
    if (check_column_win() || check_row_win() || check_diagonal_win())
    {
        set_winner(player == "X" ? "O" : "X");
        return true;
    }
    else if (check_board_full())
    {
        winner = "C";
        return true;
    }
    return false;
}

void TicTacToe::set_next_player()
{
    player = (player == "X" ? "O" : "X");
}

bool TicTacToe::check_board_full()
{
    for (auto& peg : pegs)
        if (peg == " ")
            return false;
    return true;
}

void TicTacToe::clear_board()
{
    for (auto& peg : pegs)
        peg = " ";
}

void TicTacToe::set_winner(std::string win_player)
{
    winner = win_player;
}

// Display board
std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    // board dimension is 3 or 4
    size_t size = static_cast<size_t>(std::sqrt(game.pegs.size()));

    for (size_t i = 0; i < game.pegs.size(); ++i)
    {
        out << game.pegs[i];

        if ((i + 1) % size == 0)
            out << "\n";
        else
            out << " ";
    }

    return out;
}

// Input
std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position;
    std::cout << "Enter position: ";
    in >> position;
    game.mark_board(position);
    return in;
}

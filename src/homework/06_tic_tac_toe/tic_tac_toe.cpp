#include "tic_tac_toe.h"

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
        winner = "C";    // tie
        return true;
    }
    return false;
}

void TicTacToe::set_next_player()
{
    if (player == "X")
        player = "O";
    else
        player = "X";
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

bool TicTacToe::check_row_win()
{
    if ((pegs[0] == pegs[1] && pegs[1] == pegs[2] && pegs[0] != " ") ||
        (pegs[3] == pegs[4] && pegs[4] == pegs[5] && pegs[3] != " ") ||
        (pegs[6] == pegs[7] && pegs[7] == pegs[8] && pegs[6] != " "))
        return true;

    return false;
}

bool TicTacToe::check_column_win()
{
    if ((pegs[0] == pegs[3] && pegs[3] == pegs[6] && pegs[0] != " ") ||
        (pegs[1] == pegs[4] && pegs[4] == pegs[7] && pegs[1] != " ") ||
        (pegs[2] == pegs[5] && pegs[5] == pegs[8] && pegs[2] != " "))
        return true;

    return false;
}

bool TicTacToe::check_diagonal_win()
{
    if ((pegs[0] == pegs[4] && pegs[4] == pegs[8] && pegs[0] != " ") ||
        (pegs[2] == pegs[4] && pegs[4] == pegs[6] && pegs[2] != " "))
        return true;

    return false;
}

void TicTacToe::set_winner(std::string win_player)
{
    winner = win_player;
}

// DISPLAY BOARD
std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    for (int i = 0; i < game.pegs.size(); i++)
    {
        out << game.pegs[i];
        if ((i + 1) % 3 == 0)
            out << "\n";
        else
            out << " ";
    }
    return out;
}

// INPUT MOVE
std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position;
    std::cout << "Enter position 1-9: ";
    in >> position;

    game.mark_board(position);
    return in;
}

#include "tic_tac_toe_4.h"

bool TicTacToe4::check_row_win()
{
    for (int r = 0; r < 16; r += 4)
        if (pegs[r] != " " && pegs[r] == pegs[r+1] &&
            pegs[r+1] == pegs[r+2] && pegs[r+2] == pegs[r+3])
            return true;
    return false;
}

bool TicTacToe4::check_column_win()
{
    for (int c = 0; c < 4; c++)
        if (pegs[c] != " " && pegs[c] == pegs[c+4] &&
            pegs[c+4] == pegs[c+8] && pegs[c+8] == pegs[c+12])
            return true;
    return false;
}

bool TicTacToe4::check_diagonal_win()
{
    if (pegs[0] != " " && pegs[0] == pegs[5] &&
        pegs[5] == pegs[10] && pegs[10] == pegs[15])
        return true;

    if (pegs[3] != " " && pegs[3] == pegs[6] &&
        pegs[6] == pegs[9] && pegs[9] == pegs[12])
        return true;

    return false;
}

#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(TicTacToe game)
{
    // Add game to history
    games.push_back(game);

    // Update the totals using winner from game
    update_winner_count(game.get_winner());
}

void TicTacToeManager::get_winner_total(int& o, int& x, int& t)
{
    o = o_win;
    x = x_win;
    t = ties;
}

void TicTacToeManager::update_winner_count(std::string winner)
{
    if (winner == "X")
    {
        x_win++;
    }
    else if (winner == "O")
    {
        o_win++;
    }
    else
    {
        ties++;
    }
}

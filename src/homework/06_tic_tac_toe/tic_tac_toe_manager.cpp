#include "tic_tac_toe_manager.h"
#include <iostream>

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& game)
{
    update_winner_count(game->get_winner());
    games.push_back(std::move(game));
}

void TicTacToeManager::update_winner_count(std::string winner)
{
    if (winner == "X") x_win++;
    else if (winner == "O") o_win++;
    else ties++;
}

void TicTacToeManager::get_winner_total(int& o, int& x, int& t) const
{
    o = o_win;
    x = x_win;
    t = ties;
}

void TicTacToeManager::display_history() const
{
    for (auto& game : games)
    {
        std::cout << *game << "\n";
    }
}

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include <memory>
#include <vector>
#include "tic_tac_toe.h"

class TicTacToeManager
{
public:
    void save_game(std::unique_ptr<TicTacToe>& game);
    void get_winner_total(int& o, int& x, int& t) const;
    void display_history() const;

private:
    std::vector<std::unique_ptr<TicTacToe>> games;
    int x_win{0};
    int o_win{0};
    int ties{0};

    void update_winner_count(std::string winner);
};

#endif

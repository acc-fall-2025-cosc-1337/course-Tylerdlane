#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

int main()
{
    TicTacToeManager manager;
    TicTacToe game;

    std::string first_player;
    char choice = 'Y';

    while (choice == 'Y' || choice == 'y')
    {
        std::cout << "Enter first player (X or O): ";
        std::cin >> first_player;

        game.start_game(first_player);

        while (!game.game_over())
        {
            std::cin >> game;   // input move
            std::cout << game;  // show board
            std::cout << "\n";
        }

        std::cout << "Winner: " << game.get_winner() << "\n";

        manager.save_game(game);

        int o, x, t;
        manager.get_winner_total(o, x, t);

        std::cout << "Scoreboard -> X Wins: " << x
                  << "  O Wins: " << o
                  << "  Ties: " << t << "\n\n";

        std::cout << "Play again? (Y/N): ";
        std::cin >> choice;
    }

    return 0;
}

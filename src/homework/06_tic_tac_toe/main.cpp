#include <iostream>
#include <memory>
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

int main()
{
    TicTacToeManager manager;
    char again = 'y';

    while (again == 'y' || again == 'Y')
    {
        int choice;
        std::cout << "Play TicTacToe 3 or 4? Enter 3 or 4: ";
        std::cin >> choice;

        std::unique_ptr<TicTacToe> game;

        if (choice == 3)
            game = std::make_unique<TicTacToe3>();
        else
            game = std::make_unique<TicTacToe4>();

        std::string first;
        std::cout << "Enter first player (X or O): ";
        std::cin >> first;

        game->start_game(first);

        while (!game->game_over())
        {
            std::cin >> *game;
            std::cout << *game << "\n";
        }

        std::cout << "Winner: " << game->get_winner() << "\n";

        manager.save_game(game);

        int o, x, t;
        manager.get_winner_total(o, x, t);

        std::cout << "X wins: " << x
                  << " | O wins: " << o
                  << " | Ties: " << t << "\n";

        std::cout << "Play again? (y/n): ";
        std::cin >> again;
    }

    return 0;
}

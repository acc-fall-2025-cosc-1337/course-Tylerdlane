#include "tic_tac_toe.h"
#include <iostream>

using namespace std;

int main()
{
    TicTacToe game;
    string first_player;
    char choice;

    cout << "Welcome to Tic Tac Toe!\n";

    do
    {
        // Start game
        do
        {
            cout << "Enter first player (X or O): ";
            cin >> first_player;
        } while (first_player != "X" && first_player != "O");

        game.start_game(first_player);
        int position;

        while (!game.game_over())
        {
            game.display_board();
            cout << "Player " << game.get_player() << ", enter a position (1-9): ";
            cin >> position;

            while (position < 1 || position > 9)
            {
                cout << "Invalid position. Enter a number between 1 and 9: ";
                cin >> position;
            }

            game.mark_board(position);
        }

        game.display_board();
        cout << "\nGame Over! Winner: " << game.get_winner() << endl;

        cout << "\nPlay again? (Y/N): ";
        cin >> choice;
        choice = toupper(choice);

    } while (choice == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}

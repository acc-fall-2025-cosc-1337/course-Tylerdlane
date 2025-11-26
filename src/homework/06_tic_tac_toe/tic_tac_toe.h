#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <string>
#include <vector>
#include <iostream>

class TicTacToe
{
public:
    TicTacToe() = default;
    TicTacToe(int size) : pegs(size * size, " ") {}

    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over();
    std::string get_player() const { return player; }
    std::string get_winner() const { return winner; }

    // Friends for input/output
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

protected:
    std::vector<std::string> pegs;
    virtual bool check_column_win() { return false; }
    virtual bool check_row_win() { return false; }
    virtual bool check_diagonal_win() { return false; }

private:
    std::string player;
    std::string winner;

    void set_next_player();
    bool check_board_full();
    void clear_board();
    void set_winner(std::string win_player);
};

#endif

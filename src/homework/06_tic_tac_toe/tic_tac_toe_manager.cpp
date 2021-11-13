// include
#include "tic_tac_toe_manager.h"
#include <utility>

using std::cout;

void TicTacToeManager::save_game(unique_ptr<TicTacToe>&& b)
{
    update_winner_count(b->get_winner());

    games_played.push_back(move(b));
}

void TicTacToeManager::update_winner_count(string winner)
{
    if(winner == "X")
    {
    x_win = x_win + 1;
    }
    else if(winner == "O")
    {
    o_win = o_win + 1;
    }
    else
    {
    ties = ties + 1;
    }
}

void TicTacToeManager::get_winner_total(int& w, int& o, int& t)
{
    w = x_win;
    o = o_win;
    t = ties;
}

ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    // variables
    int i;

    for(i=0;i<manager.games_played.size();i++)
    {
    out << "\nGame " << i+1 << "\n";
    out << *manager.games_played[i] <<"\n";
    }

    // return
    return out;
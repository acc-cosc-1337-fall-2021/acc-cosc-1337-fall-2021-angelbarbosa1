#include "tic_tac_toe_manager.h"
//cpp
Tic_tac_manager::Tic_tac_manager(tic_tac_data d): data(d)
{
    games = data.get_games();
    for(auto&game : games)
    {
        update_winner_count(game->get_winner());
    }
    
}
void Tic_tac_manager::save_game(unique_ptr<Tic_tac> &b)
{
    update_winner_count(b -> get_winner());
    games.push_back(std::move(b));
}
void Tic_tac_manager::get_winner_total(int& x, int& o, int& t)
{
    x = x_wins;
    o = o_wins;
    t = ties; 
}
void Tic_tac_manager::update_winner_count(string winner)
{
    if(winner == "X")
    {
        x_wins ++;
    }
    else if(winner == "O")
    {
        o_wins ++;
    }
    else if(winner == "C")
    {
        ties ++;
    }
}
std::ostream& operator<<(std::ostream& out, const Tic_tac_manager& manager)
{
    for(const auto& game: manager.games)
    {
        cout<<*game<<"\n";
    }
    return out;
}
Tic_tac_manager::~Tic_tac_manager()
{
    data.save_games(games);
}

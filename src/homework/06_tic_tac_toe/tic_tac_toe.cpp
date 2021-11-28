//cpp
#include "tic_tac_toe.h"
#include <algorithm>
using std::cout; using std::cin;
bool Tic_tac::game_over()
{
    if(check_column_win() || check_row_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }
    else if(check_board_full())
    {
        winner = "C";
        return true;
    }
    else
    {
        return false;
    }
}

void Tic_tac::start_game(string first_player)
{
    player = first_player;
    clear_board();
}

void Tic_tac::mark_board(int position)
{
    pegs[position-1] = player;
    set_next_player();

}

string Tic_tac::get_player() const
{
    return player;
}

void Tic_tac::set_next_player()
{
    if(player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}

bool Tic_tac::check_column_win()
{
    return false;
}

bool Tic_tac::check_row_win()
{
    return false;
}

bool Tic_tac::check_diagonal_win()
{
    return false;
}

bool Tic_tac::check_board_full()
{
    if(std::find(pegs.begin(), pegs.end(), " ") != pegs.end()) 
    {
        return false;
    } 
    else 
    {
        return true;
    }
}

void Tic_tac::clear_board()
{
    for(auto i : pegs)
    {
        i = " ";
    }
}

string Tic_tac::get_winner()
{
    return winner;
}

void Tic_tac::set_winner()
{
    if(player == "X")
    {
        winner = "O";
    }
    else
    {
        winner = "X";
    }
}
std::istream& operator>>(std::istream& in, Tic_tac& game)
{
    int pos;
    cout<<"Enter position on board: ";
	cin>> pos;
    game.mark_board(pos);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Tic_tac& game)
{
    int count = 0;
    if (game.pegs.size() == 9)
    {
        for(string i : game.pegs)
        {
            if (count == 2)
            {
                cout << i << "\n";
                count = 0;
            }else{
                cout<< i << "|";
                count ++;
            }
        }
    }else if (game.pegs.size() == 16)
    {
        for(string i : game.pegs)
        {
            if (count == 3)
            {
                cout << i << "\n";
                count = 0;
            }else{
                cout<< i << "|";
                count ++;
            }
        }
    }
    return out;
}
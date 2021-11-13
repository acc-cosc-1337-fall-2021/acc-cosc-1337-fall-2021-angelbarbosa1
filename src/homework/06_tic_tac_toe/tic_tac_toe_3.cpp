// include
#include "tic_tac_toe_3.h"

bool TicTacToe3::check_column_win()
{
    bool you_win;
    string last_player;

    you_win = false;
    last_player = (get_player() == "X") ? "O" : "X";

    if(pegs[0]==last_player && pegs[3] == last_player && pegs[6] == last_player)
    {
        you_win = true;
    }
    else if(pegs[1]==last_player && pegs[4] == last_player && pegs[7] == last_player)
    {
        you_win = true;
    }
    else if(pegs[2]==last_player && pegs[5] == last_player && pegs[8] == last_player)
    {
        you_win = true;
    }

    return you_win;
}

bool TicTacToe3::check_row_win()
{
    bool you_win;
    string last_player;

    you_win = false;
    last_player = (get_player() == "X") ? "O" : "X";

    if(pegs[0]==last_player && pegs[1] == last_player && pegs[2] == last_player)
    {
        you_win = true;
    }
    else if(pegs[3]==last_player && pegs[4] == last_player && pegs[5] == last_player)
    {
        you_win = true;
    }
    else if(pegs[6]==last_player && pegs[7] == last_player && pegs[8] == last_player)
    {
        you_win = true;
    }

    return you_win;
}

bool TicTacToe3::check_diagonal_win()
{
    bool you_win;
    string last_player;

    you_win = false;
    last_player = (get_player() == "X") ? "O" : "X";

    if(pegs[0] == last_player && pegs[4] == last_player && pegs[8] == last_player)
    {
        you_win = true;
    }
    else if(pegs[2] == last_player && pegs[4] == last_player && pegs[6] == last_player)
    {
        you_win = true;
    }

    return you_win;
}
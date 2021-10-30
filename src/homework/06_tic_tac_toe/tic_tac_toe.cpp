// include
#include "tic_tac_toe.h"
#include <iostream>

// using
using std::cout;

void TicTacToe::start_game(string first_player)
{

    player = first_player;

    clear_board();
}

void TicTacToe::display_board() const
{
 
    int i;
    string g_left;
    string g_name;
    string g_row;
    string g_col;
    string g_sp;


    g_left = string(20,' ');
    g_name = string(7,' ');
    g_row = string(25,'_') + "\n\n";
    g_col = "|";
    g_sp = string(3,' ');

    cout<<"\n";
    cout << g_left << g_name << "Tic-Tac-Toe" << "\n";

    cout << g_left << g_row;

    cout << g_left;

    for(i=0;i<9;i++)
    {
        cout << g_col << g_sp << pegs[i] << g_sp;
        if( (i+1) % 3 == 0)
        {
            cout << g_col << "\n";

            cout << g_left << g_row;

            if(i != 8)
            { 
                cout << g_left; 
            }
        }
    }
}

void TicTacToe::mark_board(int position)
{
    int w;

    w = position - 1;

    pegs[w] = get_player();

    set_next_player();
}

string TicTacToe::get_player()const
{
    return player;
}

void TicTacToe::set_next_player()
{
    player = (get_player() == "X") ? "O" : "X";
}

string TicTacToe::get_winner()
{
    return winner;
}

void TicTacToe::set_winner()
{
    winner = (get_player() == "X") ? "O" : "X";
}

void TicTacToe::clear_board()
{
    int i;

    for(i=0;i<9;i++)
    {
    pegs[i] = " ";
    }
}

bool TicTacToe::game_over()
{
    bool game_result;

    game_result = false;

    if(check_column_win() == true || check_row_win() == true || check_diagonal_win() == true)
    {
    set_winner();
    game_result = true;
    }
    else if(check_board_full() == true)
    {
    winner = "C";
    game_result = true;
    }

    return game_result;
}

bool TicTacToe::check_column_win()
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

bool TicTacToe::check_row_win()
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

bool TicTacToe::check_diagonal_win()
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

bool TicTacToe::check_board_full()
{
    int i;
    bool not_available;

    not_available = true;

    for(i=0;i<9;i++)
    {
        if(pegs[i] == " "){ not_available = false; break; }
    }

    return not_available;
}

void strToUpper(string &str)
{
    int i;

    for(i=0;i<str.length();i++)
    {
        str[i] = toupper(str[i]);
    }
}

void strToLower(string &str)
{
    int i;

    for(i=0;i<str.length();i++)
    {
        str[i] = tolower(str[i]);
    }
}
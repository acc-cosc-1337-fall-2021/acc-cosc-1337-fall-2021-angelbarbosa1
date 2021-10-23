// include
#include "tic_tac_toe.h"
#include <iostream>

using std::cout;

void TicTacToe::start_game(string first_player)
{
    player = first_player;

    clear_board();
}

void TicTacToe::display_board() const
{
    int i;
    string left;
    string name;
    string row;
    string g_col;
    string g_sp;

    left = string(20,' ');
    name = string(7,' ');
    row = string(25,'_') + "\n\n";
    g_col = "|";
    g_sp = string(3,' ');

    cout<<"\n";
    cout << left << name << "Tic-Tac-Toe" << "\n";

    cout << left << row;

    cout << left;

    for(i=0;i<9;i++)
{
        cout << g_col << g_sp << pegs[i] << g_sp;
        if( (i+1) % 3 == 0)
    {
    cout << g_col << "\n";

    cout << left << row;

    if(i != 8)
    { 
    cout << left; 
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
    return check_board_full();
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
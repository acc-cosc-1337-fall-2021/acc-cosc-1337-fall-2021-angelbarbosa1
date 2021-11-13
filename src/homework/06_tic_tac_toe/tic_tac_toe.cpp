// include
#include "tic_tac_toe.h"
#include "math.h"

using std::cout;using std::sqrt;

void TicTacToe::start_game(string first_player)
{
    player = first_player;

    clear_board();
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

    for(i=0;i<pegs.size();i++)
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
    return false;
}

bool TicTacToe::check_row_win()
{
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    return false;
}

bool TicTacToe::check_board_full()
{
    int i;
    bool not_available;

    not_available = true;

    for(i=0;i<pegs.size();i++)
    {
        if(pegs[i] == " "){ not_available = false; break; }
    }

    return not_available;
}

ostream& operator<<(ostream& out, const TicTacToe& game)
{
    int const base_col = 3;

    int i;
    int ind_sz;
    int space_sz;
    int peg_num;
    int col_num;
    int add_col;
    int base_sz;
    int add_sz;
    int game_board_size;
    string game_title;
    string g_left;
    string g_name;
    string g_row;
    string g_col;
    string g_sp;

    game_title = "Tic-Tac_Toe";                                         

    ind_sz = 20;                                                       
    space_sz = 3;                                                       

    peg_num = game.pegs.size();
    col_num = sqrt(peg_num);
    add_col = col_num - base_col;                                       

    base_sz = (space_sz * (base_col* 2)) +  (base_col * 2)  +  1;       
    add_sz = (space_sz * (add_col * 2)) +  (add_col * 2);               
    game_board_size = base_sz + add_sz;                                 /

    g_sp = string(space_sz,' ');
    g_left = string(ind_sz,' ');
    g_name = string((game_board_size - game_title.size())/2,' ');
    g_row = string(game_board_size,'_');
    g_col = "|";

    out << "\n" << g_left << g_name << game_title << "\n";

    out << g_left << g_row << "\n\n";
    
    out << g_left;

    for(i=0;i<game.pegs.size();i++)
    {
        out << g_col << g_sp << game.pegs[i] << g_sp;
        if( (i+1) % col_num == 0)
        {
            out << g_col << "\n";

            out << g_left << g_row << "\n\n";

            if(i != peg_num-1)
            { 
                out << g_left; 
            }
        }
    }

    return out;
}

istream& operator>>(istream& in, TicTacToe& game)
{
    int position;

    cout << "\nSelect a position between 1 and " << game.pegs.size() << " : ";
    in >> position;

    game.mark_board(position);

    return in;
}

void game_menu()
{
    cout << "\nThere are two versions of Tic-Tac-Toe:\n";
	cout << "1) 3 X 3\n";
	cout << "2) 4 X 4\n\n";
	cout << "Which would you like to play? Enter 1 or 2: ";
}
void strToUpper(string &str)
{
    int i;

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

#include<string>
#include<vector>

using std::string; using std::vector;

class TicTacToe
{
    public:
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        void display_board()const;
        string get_player()const;
        
    private:
        string player;
        vector<string> pegs = vector<string>(9," ");

        bool check_board_full();
        void set_next_player();
        void clear_board();
};

void strToUpper(string &str);
void strToLower(string &str);
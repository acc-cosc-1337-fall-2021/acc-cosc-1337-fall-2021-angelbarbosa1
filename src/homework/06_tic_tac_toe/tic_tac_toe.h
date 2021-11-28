
//h
#include <iostream>
#include<vector>
#include<memory>
using std::string;using std::vector;

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class Tic_tac
{
public:
    Tic_tac(int SIZE):pegs(SIZE*SIZE," "){}
    Tic_tac(std::vector<string> p, string win): pegs(p), winner(win){}
    void start_game(string first_player);
    void mark_board(int position);
    bool game_over();
    string get_player() const;
    string get_winner();
    friend std::ostream& operator<<(std::ostream& out, const Tic_tac& game);
    friend std::istream& operator>>(std::istream& in, Tic_tac& game);
    std::vector<string> get_pegs()const{return pegs;}
private:
    void set_next_player();
    void set_winner();
    void clear_board();
    bool check_board_full();

    string player;
    string winner;
protected:
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();
    vector<string> pegs;
};

#endif
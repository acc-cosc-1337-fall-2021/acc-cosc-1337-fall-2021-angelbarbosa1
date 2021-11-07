//h
#include <iostream>
#include <string>
#include <vector>
#include "tic_tac_toe.h"

#ifndef tictactoemgr_h
#define tictactoemgr_h

class TicTacToeManager
{

public:
void save_game(TicTacToe b);
void get_winner_total(int& o, int& w, int& t);
friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);

private:
std::vector<TicTacToe> games;
int x_win=0;
int o_win=0;
int ties=0;

void update_winner_count(std::string winner);

};

#endif
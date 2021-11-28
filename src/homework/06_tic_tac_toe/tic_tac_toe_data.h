//h
#include "tic_tac_toe.h"
#include <fstream>
#include <memory>
#ifndef TIC_TAC_DATA
#define TIC_TAC_DATA

class tic_tac_data
{
public: 
void save_games(const std::vector<std::unique_ptr<Tic_tac>>& games);
std::vector<std::unique_ptr<Tic_tac>>get_games();
private:
    string file_name{"tictactoe_data.txt"};
};

#endif
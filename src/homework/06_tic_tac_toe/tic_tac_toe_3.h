
   
//h
#include "tic_tac_toe.h"
#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H

class Tic_tac_3 : public Tic_tac
{
public:
    Tic_tac_3():Tic_tac(3){}
    Tic_tac_3(std::vector<string> p, string winner):Tic_tac(p,winner){}
private:
    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();
};
#endif
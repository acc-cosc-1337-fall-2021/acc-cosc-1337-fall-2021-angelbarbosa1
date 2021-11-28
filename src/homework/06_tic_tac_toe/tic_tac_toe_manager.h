#include <iostream>
#include "tic_tac_toe.h"
#include<vector>
#include "tic_tac_toe_data.h"

//h
using std::cout; using std::cin; using std::string;using std::vector; using std::unique_ptr;

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H
class Tic_tac_manager
{
public:
    Tic_tac_manager() = default;
    Tic_tac_manager(tic_tac_data d);
    void save_game( unique_ptr<Tic_tac> &b);
    friend std::ostream& operator<<(std::ostream& out, const Tic_tac_manager& manager);
    void get_winner_total(int& x, int& o, int& c);
    ~Tic_tac_manager();
private:
    vector<unique_ptr<Tic_tac>> games;
    int x_wins = 0;
    int o_wins = 0;
    int ties = 0;
    tic_tac_data data;
    void update_winner_count(string winner);

};
#endif
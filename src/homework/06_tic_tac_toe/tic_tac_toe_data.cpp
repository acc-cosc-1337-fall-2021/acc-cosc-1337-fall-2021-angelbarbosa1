//cpp

#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <fstream>
#include <memory>
#include <iostream>
using namespace std; 
void tic_tac_data :: save_games(const std::vector<std::unique_ptr<Tic_tac>>& games)
{
    std::ofstream tictacfile;
    tictacfile.open(file_name);
    for(int i = 0; i < games.size(); ++i){
        auto game = games[i] ->get_pegs();
        for(int j = 0; j < game.size(); ++j)
        {
        tictacfile << game[j] ;
        }
        tictacfile<< games[i] -> get_winner() << "\n";
    }
    tictacfile.close();
}

std::vector<std::unique_ptr<Tic_tac>>tic_tac_data :: get_games()
{
    std::vector<std::unique_ptr<Tic_tac>> games;
    ifstream in_file;
    in_file.open(file_name);

    string line;
    vector<string> peg;
    while(getline(in_file, line))
    {
        for(int i = 0; i < line.size(); ++i)
        {
        peg.push_back(string(1,line[i]));
        }
        string winner = peg[peg.size()-1];
        unique_ptr<Tic_tac> game;
        if(peg.size() == 9)
        {
        auto game = make_unique<Tic_tac_3>(peg,winner);
        }else if(peg.size() == 16)
        {
        auto game = make_unique<Tic_tac_4>(peg,winner);                
        }
        games.push_back(std::move(game));
        peg.clear();

    }
    in_file.close(); 
    return games;

}
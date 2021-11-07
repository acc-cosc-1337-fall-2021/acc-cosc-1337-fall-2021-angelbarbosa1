#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;

std::string player;
std::string winner;


int main() 
{
	TicTacToe game;
	TicTacToeManager gamesession;

	cout<<"This is the tic tac toe game"<<"\n";
	std::string player_choice;
	int x, o, t;

	do{
		cout<<"Enter X or O to play the game"<<"\n";
		cout<<"Or Q to quit the game"<<"\n";
		cin>>player_choice;
		game.start_game(player_choice);

		if (player_choice=="X"||player_choice=="O"){
				
				while (game.game_over()!=true){
				cin>>game;
				cout<<game;
				}

			cout<<"The winner is "<<game.get_winner()<<"\n";

			gamesession.save_game(game);
			gamesession.get_winner_total(x, o, t);
			cout<<"O Total Wins ="<<o<<"\n";
        	cout<<"X Total Wins ="<<x<<"\n";
        	cout<<"Total Ties ="<<t<<"\n";
			cout<<"\n";
			cout<<"Select X or O to play again"<<"\n";
		}

		else if(player_choice=="Q"){
			break;
		}

		else{
			cout<<"This is not valid selection"<<"\n";
		}
		
	}while (player_choice!="Q");

	cout<<"This is the end of the game.\n";
   	cout<<"These are the games you just played.\n";
	
	cout<<gamesession;

	return 0;
}
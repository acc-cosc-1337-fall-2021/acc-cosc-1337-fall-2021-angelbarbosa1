#include "tic_tac_toe.h"
#include <iostream>

using std::cin; using std::cout;

int main(){

TicTacToe game;

int position;
string play_again;
string first_player;
string game_winner;

play_again = "y";

cout << "\nThis is the gameTic-Tac-Toe\n";

do
	{
		do
		{
			cout << "\nyou want to be 'X' or 'O'? ";
			cin >> first_player;
			strToUpper(first_player);
		} while (first_player != "X" && first_player != "O");

		game.start_game(first_player);
		game.display_board();
		
		do
		{
		cout<<"\nSelect a position between 1 and 9: ";
		cin>>position;
		game.mark_board(position);
		game.display_board();

		} while (game.game_over() == false);
		cout << "Game Over\n\n";
		game_winner = game.get_winner();
		if(game_winner == "C")
		{
			cout << "It's a tie:(\n";
		}
		else
		{
			cout << "The winner is " << game_winner << "!  Congrats!\n\n";
		}

		game.start_game(first_player);

		cout << "\nyou do want to play again?  Enter 'y' for 'yes' or 'n' for 'no': ";
		cin >> play_again;
		strToLower(play_again);

	} while (play_again == "y");

	cout << "\nProgram exiting.\n";
	
	return 0;
}
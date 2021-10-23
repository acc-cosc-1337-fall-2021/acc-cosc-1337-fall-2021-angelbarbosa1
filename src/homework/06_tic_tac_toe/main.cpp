#include "tic_tac_toe.h"
#include <iostream>

using std::cin; using std::cout;

int main(){

	TicTacToe game;

	int position;
	string play_again;
	string first_player;

	play_again = "y";

	cout << "\nWelcome to Tic Tac Toe\n";

	do
	{
		do
		{
		cout << "\nYou want to be 'X' or 'O'? ";
		cin >> first_player;
		strToUpper(first_player);
			
		} while (first_player != "X" && first_player != "O");

		game.start_game(first_player);

		game.display_board();
		
		do
		{
		cout<<"\nSelect position between 1 and 9: ";
		cin>>position;

		game.mark_board(position);

		game.display_board();

		} while (game.game_over() == false);

		cout << "Game Over\n";

		game.start_game(first_player);

		do
		{
		cout << "\nYou do want to play again?  Press 'y' for 'yes' or 'n' for 'no': ";
		cin >> play_again;
		strToLower(play_again);

		} while (play_again != "y" && play_again != "n");

	} while (play_again == "y");

	cout << "\nEnding game.\n";
	
	return 0;
}
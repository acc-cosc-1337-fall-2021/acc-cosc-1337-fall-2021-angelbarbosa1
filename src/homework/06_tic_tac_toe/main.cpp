#include "tic_tac_toe_4.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_manager.h"

using std::cin;using std::cout;using std::unique_ptr;using std::make_unique;

int main(){

	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	int version_choice;
	int w, o, t;
	int position;
	string play_again;
	string first_player;
	string game_winner;

	play_again = "y";

	cout << "\nThis is the game TicTacToe.\n";

	do
	{
		game_menu();
		cin >> version_choice;

		if(version_choice == 1)
		{
			game = make_unique<TicTacToe3>();
		}
		else
		{
			game = make_unique<TicTacToe4>();
		}

		do
		{
			cout << "\nDo you want 'X' or 'O'? ";
			cin >> first_player;
			strToUpper(first_player);
			
		} while (first_player != "X" && first_player != "O");

		game->start_game(first_player);
		cout << *game;
		
		do
		{
			cin >> *game;

			cout << *game;

		} while (game->game_over() == false);

		cout << "Game Over\n\n";

		game_winner = game->get_winner();

		if(game_winner == "C")
		{
			cout << "Its a tie.\n";
		}
		else
		{
			cout << "The winner is " << game_winner << "!  Congrats!\n\n";
		}

		manager.save_game(move(game)); // use with function def argument &&

		manager.get_winner_total(w,o,t);

		cout << "Running Totals:\n";
		cout << "X: " << w << "\n";
		cout << "O: " << o << "\n";
		cout << "Tie: " << t << "\n";

		cin >> play_again;
		strToLower(play_again);

	} while (play_again == "y");
	
	manager.get_winner_total(w,o,t);

	cout << "\nFinal Totals:\n";
	cout << "X: " << w << "\n";
	cout << "O: " << o << "\n";
	cout << "Tie: " << t << "\n";

	cout << manager;

	cout << "\nThe end.\n";
	

	return 0;

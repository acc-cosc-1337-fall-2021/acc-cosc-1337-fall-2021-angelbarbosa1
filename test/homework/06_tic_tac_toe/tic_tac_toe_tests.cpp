#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe.h"

using std::cout;using std::unique_ptr;using std::make_unique;using std::move;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 1", "3X3 - Validate TicTacToe getwinner function")
{
	TicTacToeManager manager;

	int i;
	int ix;
	int w, o, t;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	first_player = "X";
	game_done = false;
	string auto_player[] = {"X","O","X"};
	int auto_positions[][9] = 	{ 	{1,2,3,4,5,7,6,9,8},
									{2,1,5,4,8,3,6,7,9},
									{4,1,5,2,6,7,3,8,9}
								};

	do
	{
		game = make_unique<TicTacToe3>();

		game->start_game(auto_player[i]);
		cout << *game;
		
		ix = 0;

		do
		{
			position = auto_positions[i][ix];
			game->mark_board(position);
			game_done = game->game_over();

			if(game_done == true)
			{
				game_winner = game->get_winner();

				if(i == 0)
				{
					REQUIRE(game_winner == "C");

					REQUIRE(ix == 8);
				}
				else if(i == 1)
				{
					REQUIRE(game_winner == "O");

					REQUIRE(ix == 4);
				}
				else
				{
					REQUIRE(game_winner == "X");

					REQUIRE(ix == 4);
				}
			}

			ix++;

		} while (game_done == false);

		manager.save_game(move(game));

		i++;

	} while(i < 3);

	REQUIRE(i == 3);

	manager.get_winner_total(w,o,t);
	REQUIRE(w == 1);
	REQUIRE(o == 1);
	REQUIRE(t == 1);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 2", "4X4 - Test First Player Set to X")
{
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	game = make_unique<TicTacToe4>();

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[16] = {1,2,3,4,6,5,7,8,9,10,12,11,14,13,16,15};

	game->start_game(first_player);
	cout << *game;

	do
	{
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			REQUIRE(i == 15);

			REQUIRE(first_player == "X");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 16);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 3", "4X4 - Test First Player Set to O")
{
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	game = make_unique<TicTacToe4>();

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "O";
	int auto_positions[16] = {1,2,3,4,6,5,7,8,9,10,12,11,14,13,16,15};

	game->start_game(first_player);
	cout << *game;

	do
	{
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			REQUIRE(i == 15);
      
			REQUIRE(first_player == "O");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 16);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 4", "4X4 - Tie Game - No Winner")
{
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	game = make_unique<TicTacToe4>();

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[16] = {1,2,3,4,6,5,7,8,9,10,12,11,14,13,16,15};

	game->start_game(first_player);
	cout << *game;

	do
	{
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			REQUIRE(i == 15);

			game_winner = game->get_winner();
			REQUIRE(game_winner == "C");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 16);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 5", "4X4 - Winner - Test Column Win 1,5,9,13")
{
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	game = make_unique<TicTacToe4>();

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[16] = {1,2,5,6,9,10,13,14,3,4,7,8,11,12,16,15};

	game->start_game(first_player);
	cout << *game;

	do
	{
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			REQUIRE(i == 6);

			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 6", "Winner - Test Column Win 2,6,10,14")
{
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	game = make_unique<TicTacToe4>();

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[16] = {2,1,6,5,10,9,14,13,15,3,4,7,8,11,12,16};

	game->start_game(first_player);
	cout << *game;

	do
	{
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			REQUIRE(i == 6);

			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 7", "Winner - Test Column Win 3,7,11,15")
{
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	game = make_unique<TicTacToe4>();

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[16] = {3,1,7,5,11,9,15,13,14,2,4,6,8,10,12,16};

	game->start_game(first_player);
	cout << *game;

	do
	{
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			REQUIRE(i == 6);

			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 8", "Winner - Test Column Win 4,8,12,16")
{
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	game = make_unique<TicTacToe4>();

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[16] = {4,1,8,5,12,9,16,13,14,2,3,6,10,7,11,15};

	game->start_game(first_player);
	cout << *game;

	do
	{
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			REQUIRE(i == 6);

			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 9", "Winner - Test Row Win 1,2,3,4")
{
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	game = make_unique<TicTacToe4>();

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[16] = {1,5,2,6,3,7,4,8,9,12,13,10,11,14,15,16};

	game->start_game(first_player);
	cout << *game;

	do
	{
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			REQUIRE(i == 6);

			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 10", "Winner - Test Row Win 5,6,7,8")
{
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	game = make_unique<TicTacToe4>();

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[16] = {5,2,6,3,7,4,8,9,12,13,10,11,14,15,16,1};

	game->start_game(first_player);
	cout << *game;

	do
	{
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			REQUIRE(i == 6);

			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 11", "Winner - Test Row Win 9.10,11,12")
{
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	game = make_unique<TicTacToe4>();

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[16] = {9,5,10,6,11,7,12,1,2,3,4,8,13,14,15,16};

	game->start_game(first_player);
	cout << *game;

	do
	{
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			REQUIRE(i == 6);

			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 12", "Winner - Test Row Win 13,14,15,16")
{
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	game = make_unique<TicTacToe4>();

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[16] = {13,9,14,10,15,11,16,12,1,2,3,4,5,6,7,8};

	game->start_game(first_player);
	cout << *game;

	do
	{
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			REQUIRE(i == 6);

			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 13", "Winner - Test Diagonal Win 1,6,11,16")
{
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	game = make_unique<TicTacToe4>();

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[16] = {1,2,6,3,11,10,16,9,12,13,4,5,7,8,14,15};

	game->start_game(first_player);
	cout << *game;

	do
	{
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			REQUIRE(i == 6);

			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 14", "Winner - Test Diagonal Win 4,7,10,13")
{
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	game = make_unique<TicTacToe4>();

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[16] = {4,2,7,3,10,1,13,9,12,13,2,5,8,14,15,16};

	game->start_game(first_player);
	cout << *game;

	do
	{
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			REQUIRE(i == 6);

			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 7);
}

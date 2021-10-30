#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include <iostream>

using std::cout;

TEST_CASE("verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("verify TicTacToe test case 1", "Test First Player Set to X")
{
	TicTacToe game;

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {1,2,3,4,5,7,6,9,8};

	game.start_game(first_player);
	game.display_board();

	do
	{
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(game_done == true)
		{
			REQUIRE(i == 8);

			game_winner = game.get_winner();
			REQUIRE(first_player == "X");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 9);
}

TEST_CASE("verify TicTacToe test case 2", "First Player Set to O")
{
	TicTacToe game;

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "O";
	int auto_positions[9] = {1,2,3,4,5,7,6,9,8};

	game.start_game(first_player);
	game.display_board();

	do
	{
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(game_done == true)
		{
			REQUIRE(i == 8);

			game_winner = game.get_winner();
			REQUIRE(first_player == "O");
		}
		
		i++;
	} while (game_done == false);

	REQUIRE(i == 9);
}

TEST_CASE("verify TicTacToe test case 3", "tied")
{
	TicTacToe game;

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {1,2,3,4,5,7,6,9,8};

	game.start_game(first_player);
	game.display_board();

	do
	{
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(game_done == true)
		{
			REQUIRE(i == 8);
			game_winner = game.get_winner();
			REQUIRE(game_winner == "C");
		}
		
		i++;

	} while (game_done == false);

	REQUIRE(i == 9);
}

TEST_CASE("verify TicTacToe test case 4", "Winner -1,4,7")
{
	TicTacToe game;

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {1,2,4,5,7,3,6,8,9};

	game.start_game(first_player);
	game.display_board();

	do
	{
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(game_done == true)
		{
			REQUIRE(i == 4);

			game_winner = game.get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;

	} while (game_done == false);

	REQUIRE(i == 5);
}

TEST_CASE("verify TicTacToe test case 5", "Winner - 2,5,8")
{
	TicTacToe game;

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {2,1,5,4,8,3,6,7,9};

	game.start_game(first_player);
	game.display_board();

	do
	{
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(game_done == true)
		{
			REQUIRE(i == 4);

			game_winner = game.get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;

	} while (game_done == false);

	REQUIRE(i == 5);
}

TEST_CASE("verify TicTacToe test case 6", "Winner - 3,6,9")
{
	TicTacToe game;

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {3,1,6,4,9,2,5,7,8};

	game.start_game(first_player);
	game.display_board();

	do
	{
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(game_done == true)
		{
			REQUIRE(i == 4);

			game_winner = game.get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;

	} while (game_done == false);

	REQUIRE(i == 5);
}

TEST_CASE("verify TicTacToe test case 7", "Winner - 1,2,3")
{
	TicTacToe game;

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {1,4,2,5,3,7,6,8,9};

	game.start_game(first_player);
	game.display_board();

	do
	{
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(game_done == true)
		{
			REQUIRE(i == 4);

			game_winner = game.get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;

	} while (game_done == false);

	REQUIRE(i == 5);
}

TEST_CASE("verify TicTacToe test case 8", "Winner 4,5,6")
{
	TicTacToe game;

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {4,1,5,2,6,7,3,8,9};

	game.start_game(first_player);
	game.display_board();

	do
	{
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(game_done == true)
		{
			REQUIRE(i == 4);

			game_winner = game.get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;

	} while (game_done == false);

	REQUIRE(i == 5);
}

TEST_CASE("verify TicTacToe test case 9", "Winner 7,8,9")
{
	TicTacToe game;

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {7,1,8,2,9,6,3,4,5};

	game.start_game(first_player);
	game.display_board();

	do
	{
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(game_done == true)
		{
			REQUIRE(i == 4);

			game_winner = game.get_winner();
			REQUIRE(game_winner == "X");
		}

		i++;

	} while (game_done == false);

	REQUIRE(i == 5);
}

TEST_CASE("verify TicTacToe test case 10", "Winner - 1,5,9")
{
	TicTacToe game;

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {1,3,5,4,9,2,6,7,8};

	game.start_game(first_player);
	game.display_board();

	do
	{
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(game_done == true)
		{
				REQUIRE(i == 4);

			game_winner = game.get_winner();
			REQUIRE(game_winner == "X");
		}
		
		i++;

	} while (game_done == false);

	REQUIRE(i == 5);
}

TEST_CASE("verify TicTacToe test case 11", "Winne- 7,5,3")
{
	TicTacToe game;

	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {7,1,5,4,3,2,6,9,8};

	game.start_game(first_player);
	game.display_board();

	do
	{
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(game_done == true)
		{
				REQUIRE(i == 4);

			game_winner = game.get_winner();
			REQUIRE(game_winner == "X");
		}

		i++;

	} while (game_done == false);

	REQUIRE(i == 5);
}
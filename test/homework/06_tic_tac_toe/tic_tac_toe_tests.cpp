#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "tic_tac_toe.h"
#include <iostream>

using std::cout;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Tic-Tac-Toe")
{
	TicTacToe game;
	int i;
	int position;
	string first_player;

	i = 0;
	first_player = "X";
	int auto_positions[9] = {1,2,3,4,5,7,6,9,8};

	game.start_game(first_player);
	game.display_board();

	do
	{
		position = auto_positions[i];
		game.mark_board(position);

		if(i < 8)
		{
			REQUIRE(game.game_over() == false);
		}
		else
		{
			REQUIRE(game.game_over() == true);

			REQUIRE(i == 8);
		}
		
		i++;
	} while (game.game_over() == false);

	REQUIRE(i == 9);
}
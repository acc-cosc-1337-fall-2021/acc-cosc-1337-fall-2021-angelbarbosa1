#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("First player set to X"){
	TicTacToe game;
	game.start_game("X");
	REQUIRE(game.get_player()=="X");
}

TEST_CASE("Test first player set to O"){
	TicTacToe game;
	game.start_game("O");
	REQUIRE(game.get_player()=="O");
}

TEST_CASE("Test win by 1st column"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(4);
	REQUIRE(game.game_over()==false);
	game.mark_board(6);
	REQUIRE(game.game_over()==false);
	game.mark_board(7);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}

TEST_CASE("Test win by 2nd column"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(3);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(6);
	REQUIRE(game.game_over()==false);
	game.mark_board(8);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}

TEST_CASE("Test win by 3rdcolumn"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(3);
	REQUIRE(game.game_over()==false);
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(6);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(9);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}

TEST_CASE("Test win by 1st row"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(4);
	REQUIRE(game.game_over()==false);
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(9);
	REQUIRE(game.game_over()==false);
	game.mark_board(3);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}

TEST_CASE("Test win by 2nd row"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(4);
	REQUIRE(game.game_over()==false);
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(9);
	REQUIRE(game.game_over()==false);
	game.mark_board(6);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}

TEST_CASE("Test win by 3rd row"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(7);
	REQUIRE(game.game_over()==false);
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(8);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(9);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}

TEST_CASE("Test win by diagnol top left"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(3);
	REQUIRE(game.game_over()==false);
	game.mark_board(9);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}

TEST_CASE("Test win by diagnol bottom left"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(7);
	REQUIRE(game.game_over()==false);
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(8);
	REQUIRE(game.game_over()==false);
	game.mark_board(3);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}

TEST_CASE("Test case to determine if there is a tie"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(3);
	REQUIRE(game.game_over()==false);
	game.mark_board(7);
	REQUIRE(game.game_over()==false);
	game.mark_board(4);
	REQUIRE(game.game_over()==false);
	game.mark_board(6);
	REQUIRE(game.game_over()==false);
	game.mark_board(9);
	REQUIRE(game.game_over()==false);
	game.mark_board(8);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="C");
}

TEST_CASE("Test TicTacToe manager get winner total function"){
	TicTacToe game;
	TicTacToeManager session;
	game.start_game("X");
	game.mark_board(7);
	REQUIRE(game.game_over()==false);
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(8);
	REQUIRE(game.game_over()==false);
	game.mark_board(3);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
	session.save_game(game);
	int x, o, t;
	session.get_winner_total(x, o, t);
	REQUIRE(x==1);
	REQUIRE(o==0);
	REQUIRE(t==0);

	game.start_game("X");
	game.mark_board(7);
	REQUIRE(game.game_over()==false);
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(8);
	REQUIRE(game.game_over()==false);
	game.mark_board(3);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
	session.save_game(game);
	session.get_winner_total(x, o, t);
	REQUIRE(x==2);
	REQUIRE(o==0);
	REQUIRE(t==0);


	game.start_game("X");
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(3);
	REQUIRE(game.game_over()==false);
	game.mark_board(7);
	REQUIRE(game.game_over()==false);
	game.mark_board(4);
	REQUIRE(game.game_over()==false);
	game.mark_board(6);
	REQUIRE(game.game_over()==false);
	game.mark_board(9);
	REQUIRE(game.game_over()==false);
	game.mark_board(8);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="C");

	session.save_game(game);
	session.get_winner_total(x, o, t);
	
	REQUIRE(x==2);
	REQUIRE(o==0);
	REQUIRE(t==1);


}
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
using std::make_unique;
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify if board is full function works")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_3> ();
	game ->start_game("X");
	game ->mark_board(2);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(1);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(4);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(3);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(6);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(7);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(8);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(9);
	REQUIRE(game ->game_over() == true);
	REQUIRE(game ->get_winner() == "C");
	
}

TEST_CASE("Test first player set to X")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_3> ();
	game ->start_game("X");
	REQUIRE(game ->get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_3> ();
	game ->start_game("O");
	REQUIRE(game ->get_player() == "O");
}

TEST_CASE("Test win by first column")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_3> ();
	game ->start_game("X");
	game ->mark_board(1);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(2);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(4);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(7);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "X");
}

TEST_CASE("Test win by second column")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_3> ();
	game ->start_game("O");
	game ->mark_board(2);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(3);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(7);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(8);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "O");
}

TEST_CASE("Test win by third column")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_3> ();
	game ->start_game("X");
	game ->mark_board(3);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(2);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(6);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(9);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "X");
}

TEST_CASE("Test win by first row")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_3> ();
	game ->start_game("O");
	game ->mark_board(1);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(4);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(2);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(3);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "O");
}

TEST_CASE("Test win by second row")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_3> ();
	game ->start_game("X");
	game ->mark_board(4);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(2);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(3);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(6);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "X");
}

TEST_CASE("Test win by third row")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_3> ();
	game ->start_game("O");
	game ->mark_board(7);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(2);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(8);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(3);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(9);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "O");
}

TEST_CASE("Test win diagonally from top left")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_3> ();
	game ->start_game("X");
	game ->mark_board(1);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(2);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(3);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(9);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "X");

}

TEST_CASE("Test win diagonally from bottom left")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_3> ();
	game ->start_game("O");
	game ->mark_board(7);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(2);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(6);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(3);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "O");
}

TEST_CASE("Test win by first column 4")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_4> ();
	game ->start_game("X");
	game ->mark_board(1);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(2);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(10);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(9);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(11);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(13);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "X");
}

TEST_CASE("Test win by second column 4")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_4> ();
	game ->start_game("O");
	game ->mark_board(2);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(1);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(6);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(13);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(10);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(8);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(14);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "O");
}

TEST_CASE("Test win by third column 4")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_4> ();
	game ->start_game("X");
	game ->mark_board(3);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(2);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(7);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(10);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(11);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(16);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(15);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "X");
}

TEST_CASE("Test win by fourth column 4")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_4> ();
	game ->start_game("O");
	game ->mark_board(4);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(2);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(8);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(1);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(12);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(15);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "O");
}

TEST_CASE("Test win by first row 4")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_4> ();
	game ->start_game("O");
	game ->mark_board(1);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(2);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(6);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(3);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(15);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(4);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "O");
}

TEST_CASE("Test win by second row 4")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_4> ();
	game ->start_game("X");
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(4);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(6);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(10);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(7);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(16);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(8);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "X");
}

TEST_CASE("Test win by third row 4")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_4> ();
	game ->start_game("O");
	game ->mark_board(9);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(10);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(6);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(11);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(15);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(12);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "O");
}

TEST_CASE("Test win by forth row 4")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_4> ();
	game ->start_game("O");
	game ->mark_board(13);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(14);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(6);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(15);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(1);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "O");
}

TEST_CASE("Test win diagonally from top left 4")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_4> ();
	game ->start_game("X");
	game ->mark_board(1);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(6);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(7);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(11);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(3);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(16);
	REQUIRE(game ->game_over() == true);
	REQUIRE(game ->get_winner() == "X");

}

TEST_CASE("Test win diagonally from bottom left 4")
{
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_4> ();
	game ->start_game("O");
	game ->mark_board(13);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(5);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(10);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(9);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(7);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(1);
	REQUIRE(game ->game_over() == false);
	game ->mark_board(4);
	REQUIRE(game->game_over() == true);
	REQUIRE(game ->get_winner() == "O");
}

TEST_CASE("Test Manager")
{
	Tic_tac_manager manager;
	unique_ptr<Tic_tac> game = make_unique<Tic_tac_3> ();
	int x_wins, o_wins, ties;
	game -> start_game("X");
	game ->mark_board(2);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(1);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(4);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(3);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(5);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(6);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(7);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(8);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(9);
	REQUIRE(game -> game_over() == true);
	manager.save_game(game);
	game -> start_game("X");
	game -> mark_board(7);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(2);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(5);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(6);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(3);
	REQUIRE(game -> game_over() == true);
	manager.save_game(game);
	game -> start_game("O");
	game -> mark_board(1);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(2);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(4);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(5);
	REQUIRE(game -> game_over() == false);
	game -> mark_board(7);
	REQUIRE(game -> game_over() == true);
	manager.save_game(game);
	manager.get_winner_total(x_wins,o_wins,ties);
	REQUIRE(x_wins == 1);
	REQUIRE(o_wins == 1);
	REQUIRE(ties == 1);

}

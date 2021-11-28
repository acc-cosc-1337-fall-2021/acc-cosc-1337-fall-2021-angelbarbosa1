#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <memory>
#include <string>
#include <iostream>
using std::cout; using std::cin; using std::string;using std::make_unique; using namespace std;

int main() 
{
	tic_tac_data data;
	Tic_tac_manager manager(data);
	int x_wins, o_wins, ties;
	bool vars = true;
	do{
		unique_ptr<Tic_tac> game;
		string player;
		int pos;
		char varification;
		int choice;
		cout<<"1- Play 3x3\n";
		cout<<"2- Play 4x4\n";
		cout<<"3- Exit\n";
		cin>>choice;
		if(choice == 1)
		{
		unique_ptr<Tic_tac> game = make_unique<Tic_tac_3> ();
		cout<<"Enter X or O: ";
		cin>> player;
		if (player == "x")
		{
			player = "X";
		}
		else if (player == "o")
		{
			player = "O";
		}
		if(player == "X" || player == "O")
		{
			game -> start_game(player);
			while(game -> game_over() != true)
			{
			cin >> *game;
			cout<< *game;
			}
			if(game -> get_winner() == "X")
			{
			cout<<"X wins!\n";
			}
			else if(game -> get_winner() == "O")
			{
			cout<<"O wins!\n";
			}
			else if (game -> get_winner() == "C")
			{
			cout<< "Tie\n";
			}
			manager.save_game(game);
			manager.get_winner_total(x_wins,o_wins,ties);
			cout<<"\nX wins: "<<x_wins<<"\n";
			cout<<"O wins: "<<o_wins<<"\n";
			cout<<"Ties: "<<ties<<"\n\n";
		}
			else
			{
			cout<<"Did not enter valid entry\n";
			}
		}
		if(choice == 2)
		{
			unique_ptr<Tic_tac> game = make_unique<Tic_tac_4> ();
			cout<<"Enter X or O: ";
			cin>> player;
			if (player == "x")
			{
				player = "X";
			}
			else if (player == "o")
			{
				player = "O";
			}
			if(player == "X" || player == "O")
			{
				game -> start_game(player);
				while(game -> game_over() != true)
				{
					cin >> *game;
					cout<< *game;
				}
				if(game -> get_winner() == "X")
				{
					cout<<"X wins!\n";
				}
				else if(game -> get_winner() == "O")
				{
					cout<<"O wins!\n";
				}
				else if (game -> get_winner() == "C")
				{
					cout<< "Tie\n";
				}
				manager.save_game(game);
				manager.get_winner_total(x_wins,o_wins,ties);
				cout<<"\nX wins: "<<x_wins<<"\n";
				cout<<"O wins: "<<o_wins<<"\n";
				cout<<"Ties: "<<ties<<"\n\n";
			}
			else
			{
				cout<<"Entry not valid.\n";
			}
		}
		if (choice == 3)
		{
			cout<<"Are you sure you want to exit? (y/other char)\n";
			cin>>ws>>varification;
			if(varification == 'Y'|| varification  == 'y')
			{
				vars = false;
			}else{
				vars = true;
			}
		}
		if (choice != 2 && choice != 1 && choice != 3)
		{
			cout<<"Entry not valid.\n";
		}
		
	}while(vars);

	cout<<"\n"<<manager;
	cout<<"X wins: "<<x_wins<<"\n";
	cout<<"O wins: "<<o_wins<<"\n";
	cout<<"Ties: "<<ties<<"\n\n";

	return 0;
}


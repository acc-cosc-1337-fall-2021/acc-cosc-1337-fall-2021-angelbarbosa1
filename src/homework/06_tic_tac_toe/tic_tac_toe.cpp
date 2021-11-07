//cpp

#include "tic_tac_toe.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;

std::string TicTacToe::get_winner(){

    return winner;
}

void TicTacToe::set_winner(){

    if (TicTacToe::player=="X"){
        TicTacToe::winner="O";
    }
    else{
        TicTacToe::winner="X";
    }
    return;

}

bool TicTacToe::game_over(){

    if (TicTacToe::check_column_win()==true){
    set_winner();
    cout<<"GAME OVER"<<"\n";
    return true;
    }
    else if (TicTacToe::check_row_win()==true){
    set_winner();
    cout<<"GAME OVER"<<"\n";
    return true;
    }
    else if (TicTacToe::check_diagonal_win()==true){
    set_winner();
    cout<<"GAME OVER"<<"\n";
    return true;
}

    else if (TicTacToe::check_board_full()==true){
    TicTacToe::winner="C";
    cout<<"GAME OVER"<<"\n";
    return true;
    }

    return false;    
}

void TicTacToe::start_game (std::string first_player){
    
player=first_player;
clear_board();
return;
}

void TicTacToe::mark_board(int position){

    TicTacToe::pegs[position-1]=player;
    set_next_player();
}

std::string TicTacToe::get_player()const {

    return player;
}

std::ostream& operator<<(std::ostream& out, const TicTacToe& game2){
        out<<game2.pegs[0]<<"|"<<game2.pegs[1]<<"|"<<game2.pegs[2]<<"\n";
        out<<game2.pegs[3]<<"|"<<game2.pegs[4]<<"|"<<game2.pegs[5]<<"\n";
        out<<game2.pegs[6]<<"|"<<game2.pegs[7]<<"|"<<game2.pegs[8]<<"\n";

        return out;
}


std::istream& operator>>(std::istream& in, TicTacToe& game2){
    int position;
	cout<<"Enter 1 to 9"<<"\n";
    in>>position;
    game2.mark_board(position);
				
    return in;
}


void TicTacToe::set_next_player(){
    if (TicTacToe::player=="X"){
        TicTacToe::player="O";
    }
    else{
        TicTacToe::player="X";
    }

}


bool TicTacToe::check_board_full(){
    
    int num=0;
    for (int i=0;i<=8;i++){
        if (TicTacToe::pegs[i]==" "){
            num ++;
        }
    }
    if (num>=1){
        return false;
    }
    else {
        cout<<"TIE"<<"\n";
        clear_board();   
        return true;
    }
}

void TicTacToe::clear_board(){

    for (int i=0; i<=8; i++){
        TicTacToe::pegs[i]=" ";
    }

}

bool TicTacToe::check_column_win(){

    if (TicTacToe::pegs[0]=="X" && TicTacToe::pegs[3]=="X" && TicTacToe::pegs[6]=="X"){
        return true;
    }
    else if (TicTacToe::pegs[0]=="O" && TicTacToe::pegs[3]=="O" && TicTacToe::pegs[6]=="O"){
        return true;
    }
    else if (TicTacToe::pegs[1]=="O" && TicTacToe::pegs[4]=="O" && TicTacToe::pegs[7]=="O"){
        return true;
    }
    else if (TicTacToe::pegs[1]=="X" && TicTacToe::pegs[4]=="X" && TicTacToe::pegs[7]=="X"){
        return true;
    }
    else if (TicTacToe::pegs[2]=="O" && TicTacToe::pegs[5]=="O" && TicTacToe::pegs[8]=="O"){
        return true;
    }
    else if (TicTacToe::pegs[2]=="X" && TicTacToe::pegs[5]=="X" && TicTacToe::pegs[8]=="X"){
        return true;
    }
    else return false;

}




bool TicTacToe::check_row_win(){
    if (TicTacToe::pegs[0]=="X" && TicTacToe::pegs[1]=="X" && TicTacToe::pegs[2]=="X"){
        return true;
    }
    else if (TicTacToe::pegs[0]=="O" && TicTacToe::pegs[1]=="O" && TicTacToe::pegs[2]=="O"){
        return true;
    }
    else if (TicTacToe::pegs[3]=="O" && TicTacToe::pegs[4]=="O" && TicTacToe::pegs[5]=="O"){
        return true;
    }
    else if (TicTacToe::pegs[3]=="X" && TicTacToe::pegs[4]=="X" && TicTacToe::pegs[5]=="X"){
        return true;
    }
    else if (TicTacToe::pegs[6]=="O" && TicTacToe::pegs[7]=="O" && TicTacToe::pegs[8]=="O"){
        return true;
    }
    else if (TicTacToe::pegs[6]=="X" && TicTacToe::pegs[6]=="X" && TicTacToe::pegs[8]=="X"){
        return true;
    }
    else return false;
}




bool TicTacToe::check_diagonal_win(){
    if (TicTacToe::pegs[0]=="X" && TicTacToe::pegs[4]=="X" && TicTacToe::pegs[8]=="X"){
        return true;
    }
    else if (TicTacToe::pegs[0]=="O" && TicTacToe::pegs[4]=="O" && TicTacToe::pegs[8]=="O"){
        return true;
    }
    else if (TicTacToe::pegs[2]=="O" && TicTacToe::pegs[4]=="O" && TicTacToe::pegs[6]=="O"){
        return true;
    }
    else if (TicTacToe::pegs[2]=="X" && TicTacToe::pegs[4]=="X" && TicTacToe::pegs[6]=="X"){
        return true;
    }
        else return false;
}
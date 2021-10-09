/*
use a vector of int with values 8, 4, 20, 88, 66, 99

Prompt user for 1 for Get Max from vector and 2 for Get primes.
Prompt user for a number and return max value or list of primes
and display them to screen.
Program continues until user decides to exit.

*/
#include"func.h"
using std::cout;
using std::cin;

int main() 
{
int choice;
	std::string dna;
	do{
	cout<<"\n";
	cout<<"Main Menu\n";	
	cout<<"\n";
	cout<<"1 - Get GC content\n";	
	cout<<"2 - Get DNA complement\n";
	cout<<"3 - Exit\n";	
	cout<<"Put your choice:\n";
	cin>>choice;

	switch(choice){
	case 1:
		cout<<"You pick GC content\n ";
		cout<<"Put DNA string \n";
		cin>>dna;
		cout<<"The answer is: "<<get_gc_content(dna);
		break;
		
	case 2:
		cout<<"You pick DNA complement  \n";
		cout<<"Put your DNA string  \n";
		cin>>dna;
		cout<<"The answer is: "<<get_dna_complement(dna);
		break;

	case 3:
		char confirm;
		cout<<"You are sure you want to exit? (Y) or (N)\n";
		cin>>confirm;

		if (confirm=='Y'||confirm=='y'){
		break;
		}
		else{
			choice=4;
			break;
		}
		default:
			cout<<"Not valid option";
			break;	
		}
	} while (choice !=3);

	return 0;
}
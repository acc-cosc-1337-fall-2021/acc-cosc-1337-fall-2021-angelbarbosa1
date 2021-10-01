//write include statements
#include<iostream>
#include<string>
#include"dna.h"

//write using statements
using std::cin;
using std::cout;
using std::endl;
using std::string;


/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	char confirmation = 'n';
	int user_choice = 0;
	int user_input_num1;
	int user_input_num2;
	int results;

	do {
		cout << "_____MAIN MENU_____"<< endl;
		cout << "1-Factorial" << endl;
		cout << "2-Greatest Common Divisor" << endl;
		cout << "3-Exit" << endl;
		cout<< "___________________________" << endl;
		cout << "Make a selection: ";
		cin >> user_choice;
		

		if (user_choice == 1) {
			cout << "What number do you want to calculate factorial for? ";
			cin >> user_input_num1;
			results = factorial(user_input_num1);
			cout << "Factorial for " << user_input_num1 << " is " << results << "." << endl;
			cout << " " << endl; 
		}

		if (user_choice == 2) {
			cout << "Enter first number: ";
			cin >> user_input_num1;
			cout << "Enter second number: ";
			cin >> user_input_num2;
			results = gcd(user_input_num1, user_input_num2);
			cout << "The GCD for " << user_input_num1 << " and " << user_input_num2 << " is " << results << "." << endl;
			cout << " " <<endl; 
		}

		if (user_choice == 3) {
			cout << "You are sure you want to exit?   ";
			cin >> confirmation;
			if ((confirmation == 'y') || (confirmation == 'Y')) {
				cout << "End" << endl;
				return 0;
			}
		}
		
	} while ((confirmation != 'Y') && (confirmation != 'y'));
	return 0;
}
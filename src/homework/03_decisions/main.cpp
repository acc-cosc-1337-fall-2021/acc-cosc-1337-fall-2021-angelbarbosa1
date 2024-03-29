//write include statements
#include <iostream>
#include "decisions.h"

using std::cout; using std::cin;


int main() 
{
	int num;
	int grade;
	string letter_grade;

	cout << "\n\nMAIN MENU\n\n";
	cout << "1-Letter Grade Using If\n";
	cout << "2-Letter Grade Using Switch\n";
	cout << "3-Exit\n\n";
	cout << "Enter your selection from menu: ";
	cin >> num;

	switch(num)
	{
		case 1 ... 2:
			cout << "Enter a numerical grade between 0 and 100: ";
			cin >> grade;

			if (grade < 0 || grade > 100)
			{
				cout << "\nThe number you entered is out of range.\n";
			}
			else
			{
			switch (num)
			{
			case 1:
			cout << "\nYou chose the 'if' method of letter grade calculation.";
			letter_grade = get_letter_grade_using_if(grade);
			break;
			default:
			cout << "\nYou chose the 'switch' method of letter grade calculation.";
			letter_grade = get_letter_grade_using_switch(grade);
			break;
			}

			cout << "\nThe numerical grade " << grade << " is the letter grade " << letter_grade << ".\n";
			}
			break;
		case 3:
			cout << "\nYou chose to exit the program.\n";
			break;
		default: 
			cout << "\nYou made an invalid selection.\n";
			break;
	}
	cout << "\nThis is the end of the program. \n";
	
	// return
	return 0;
}
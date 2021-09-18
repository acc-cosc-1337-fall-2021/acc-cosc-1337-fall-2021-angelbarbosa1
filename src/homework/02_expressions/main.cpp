//write include statements
#include <iostream>
#include <iomanip>
#include <math.h>
#include "hwexpressions.h"
//write namespace using statement for cout
using std::cin; using std::cout; using std::setw; using std::setprecision; using std::fixed;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	double meal_amount;
	double tip_rate;
	double tip_amount;
	double tax_amount;
	double total;

	cout << "Enter the meal cost: ";
	cin >> meal_amount;
	cout << "Enter yout tip percentage (do not add symbol): ";
	cin >> tip_rate;

	tax_amount = get_sales_tax_amount(meal_amount);

	total = meal_amount + tax_amount +tip_amount;

	total = roundf(total*100)/100;

	cout << fixed;
	cout << setprecision(2);
	cout << "\n";
	cout << "Order Receipt\n";
	cout << setw(14) << "Meal Amount: $" << setw(5) << meal_amount << "\n";
	cout << setw(14) << "Sales Tax:   $" << setw(5) << tax_amount << "\n";
	cout << setw(14) << "Tip Amount:  $" << setw(5) << tip_amount << "\n";
	cout << setw(14) << "Total:       $" << setw(5) << total << "\n\n";
	return 0;
}

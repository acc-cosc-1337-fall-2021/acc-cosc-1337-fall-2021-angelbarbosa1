//write include statements
#include "data_types.h"
#include <iostream>
//write namespace using statement for cout
using namespace std;
using std::cout;
using std::cin;
/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	int result;
	int num1;
	cout<<"Pick a number to multiply!";
	cin>>num1;
	result = multiply_numbers(num1);
	cout<<"The result is"<< result;
	return 0;
}

/*
*	Solution to Project Euler's Exercise #2
*	Author: Brei
*/

#include <iostream>
using namespace std;

// -Logical approach-
int sum_of_fibs(int cnt, bool even)
{
	// Routine #1: Display the fibonnacci sequence in the output with 'cnt' as the number of items to be displayed

	int sum = 0, total = 0, total_even = 0, num1 = 0, num2 = 1;

	for(int i = 1; i <= cnt; ++i) {
		// Loop and display each number separated by spaces
		sum = num1 + num2;

		cout << sum << " ";

		total += sum;			// add each result to the total

		// Get the total of all even numbers
		if(sum % 2 == 0) {
			total_even += sum;
		}

		num1 = num2;
		num2 = sum;

		// If at 'cnt', add newline escapes
		if (i == cnt) {
			cout << endl << endl;
		}

	}

	// Routine #2: Get the total of all the fibs

	// Routine #3: Get the total of the even numbered fibs

	if(even == true) {
		return total_even;
	}
	else {
		return total;
	}
}
// -END of logical approach-

int sum_of_fibs2(int val, bool even)
{
	int sum = 0, total = 0, total_even = 0, num1 = 0, num2 = 1;

	while(num1 + num2 < val) {
		// While the sum of the last two numbers doesn't exceed the val parameter, execute the code
		sum = num1 + num2;

		cout << sum << " ";

		total += sum;			// add each result to the total

		// Get the total of all even numbers
		if(sum % 2 == 0) {
			total_even += sum;
		}

		num1 = num2;
		num2 = sum;
	}

	cout << endl << endl;

	if(even == true) {
		return total_even;
	}
	else {
		return total;
	}
}

int main()
{
	//cout << "Total: " << sum_of_fibs(10, true) << endl;
	cout << "Total: " << sum_of_fibs2(4000000, true) << endl;
}
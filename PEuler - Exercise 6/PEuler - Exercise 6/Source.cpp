/*
*	Solution to Project Euler's Exercise #5
*	Author: Brei
*
*	The sum of the squares of the first ten natural numbers is,
*	1^2 + 2^2 + ... + 10^2 = 385
*
*	The square of the sum of the first ten natural numbers is,
*	(1 + 2 + ... + 10)^2 = 55^2 = 3025
*
*	Hence the difference between the sum of the squares of the first ten natural numbers and
*	the square of the sum is 3025 − 385 = 2640.
*
*	Find the difference between the sum of the squares of the first one hundred natural numbers
*	and the square of the sum.
*/

#include<iostream>
#include<math.h>
using namespace std;

// Method #1 - Use x*x for x^2
// Method #2 - Use pow(x, 2) from the math library

int sumOfSquares(int low, int high)
{
	int result = 0;

	// Iterate through the number range {low, ..., high}
	for(int i = low; i <= high; ++i) {
		// Square each iteration
		result += (i * i);
		// result += (int) pow(i, 2);			// Method #2
	}

	return result;
}

int squareOfSums(int low, int high)
{
	int result = 0;
	// Iterate through the number range {low, ..., high}
	for(int i = low; i <= high; ++i) {
		// Add each iteration
		result += i;
	}

	// Return the square of the result
	return result * result;
	// return (int) pow(result, 2);				// Method #2
}

int getDifference(int num1, int num2)
{
	return num1 - num2;
}

int main()
{
	// Test sumOfSquares(a, b)
	int a = 1, b = 100;

	cout << "Sum of squares (" << a << ", " << b << "):	" << sumOfSquares(a, b) << endl << endl;

	// Test squareOfSums(a, b)
	cout << "Square of sums (" << a << ", " << b << "):	" << squareOfSums(a, b) << endl << endl;

	// Test getDifference(x, y)
	cout << "Difference (" << squareOfSums(a, b) << ", " << sumOfSquares(a, b) << "):	"
		<< getDifference(squareOfSums(a, b), sumOfSquares(a, b)) << endl << endl;

	return 0;
}
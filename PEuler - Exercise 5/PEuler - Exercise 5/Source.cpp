/*
*	Solution to Project Euler's Exercise #5
*	Author: Brei
*
*	2520 is the smallest number that can be divided by each of the numbers from 1 to 10 
*	without any remainder.
*
*	What is the smallest positive number that is evenly divisible by all of the numbers 
*	from 1 to 20?
*
*	NOTE: Current solution smallestDivisible(low, high) is very slow. It took hours to complete
*	the operation. Must optimize code and look for a better algorithm for LCMs.
*/

#include<iostream>
#include<Windows.h>
using namespace std;

// BONUS: Clear screen function (for Windows only)
void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition( hStdOut, homeCoords );
 }

// Iterative method. BRUTE FORCE.
long long int smallestDivisible(int low, int high)
{
	long long int num = high;
	bool flag = true;

	// Step 1: Iterate through the possible answers (initialized at 20)
	while(flag == true) {
		
		// Step 2: Check if the number in each iteration is divisible with
		// all the numbers within the range
		for(int i = low; i <= high; ++i) {
			cout << i << endl;
			ClearScreen();

			if(num % i != 0) {
				num += high;
				//i = low;
				break;
			}

			// If inner loop reached the last number in the range, exit all iterations
			if(i == high) {
				//i = low;
				flag = false;
			}
		}
	}

	return num;

}
// End of Brute Force Method

int findLcmRecursive(int low, int high)
{
	int num1 = low, num2 = low + 1, result = 0;

	// LCM(a, b) = (a * b) / GCD(a, b)
	
	return result;
}

int getGcd(int num1, int num2)
{
	// Euclidian Algorithm
	int temp = 0;

	if(num1 > num2) {

		while(num1 % num2 != 0) {
			temp = num2;
			num2 = num1 % num2;
			num1 = temp;
		}
		
		return num2;
	}

	if(num2 > num1) {

		while(num2 % num1 != 0) {
			temp = num1;
			num1 = num2 % num1;
			num2 = temp;
		}
		
		return num1;
	}

	return 0;

}

int main()
{
	// testing smallestDivisible(low, high)
	// Reference: for range 1 - 20, their LCM is 232792560
	int low = 1, high = 10, input = 0;

	ClearScreen();

	cout << smallestDivisible(low, high) << " is the smallest positive number that is evenly divisible"
		<< " by all of the numbers from " << low << " to " << high << "." << endl << endl;

	// Test getGcd(num1, num2)
	cout << "Num 1: ";
	cin >> low;

	cout << "Num 2: ";
	cin >> high;

	cout << "GCD = " << getGcd(low, high) << endl;

	return 0;
}
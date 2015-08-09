/*
*	Solution to Project Euler's Exercise #4
*	Author: Brei
*
*	A palindromic number reads the same both ways. The largest palindrome made from the product of
*	two 2-digit numbers is 9009 = 91 × 99
*
*	Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool isPalindromic(vector<int> num)
{
	// For words with size larger than 1, start iteration
	cout << endl << endl;
	for(int i = 0; i < num.size(); ++i) {
		cout << num[i];
	}
	cout << endl << endl;

	if(num.size() > 1) {
		// Check if the vector index value is equal to its counterpart
		// (e.g. first index val == last index val)
		for(int toRight = 0, toLeft = num.size() - 1; toRight <= toLeft ;++toRight, --toLeft) {
			// if equal, continue on checking
			if(num[toRight] != num[toLeft]) {
				// if not equal, the number is not palindromic
				return false;
			}
		}
	}

	return true;
}

vector<int> returnNumVec(int num)
{
	// Stores an int into a vector

	vector<int> result;
	int digitCnt = 0, temp = num;

	// count the number of digits in num
	while(temp > 0) {
		++digitCnt;
		temp /= 10;
	}

	--digitCnt;												// subtract 1 from the number of digits
															// as this variable will be used in the
															// subsequent pow() functions
	//cout << "digitCnt: " << digitCnt << endl;

	do {
		int digit = num / (int) pow(10, digitCnt);			// 1235 / 1000 = 1
		num %= (int) pow(10, digitCnt);						// 1235 % 1000 = 235

		result.push_back(digit);							// push digit to vector

		--digitCnt;
	} while(digitCnt >= 0);

	return result;
}

void flushIstream()
{
	cin.clear();
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

int main()
{
	/*
	// Testing the returnNumVec() function
	vector<int> number;
	int test = 1234567;

	number = returnNumVec(test);

	cout << "Test number is " << test << "." << endl;

	cout << "Here are its vector contents: ";
	for(int i = 0; i < number.size(); ++i) {
		cout << number[i];
	}

	cout << endl;

	// Testing the isPalindromic() function
	
	int input = 0;
	while(true) {
		cout << "Input a number: ";
		cin >> input;

		if(!cin){
			cerr << "Not a valid input. Terminating..." << endl;

			break;
		}

		number = returnNumVec(input);

		if(isPalindromic(number)) {
			cout << input << " is palindromic." << endl << endl;
		}
		else {
			cout << input << " is not palindromic." << endl << endl;
		}

		flushIstream();
	}
	*/

	// Finding the largest palindrome that is a product of two 3-digit numbers

	// Step 1: Iterate through each factor combination (Start from 999 * 999)
	int x = 999, y = 999, product = x * y, cx = x, cy = y;

	// Step 2: Check if product is a palindrome and terminate the iteration
	for( ; x >= cx / 2; --x) {
		/*
		* A simple algorithm:
		*
		* A loop within a loop shown in x * y where y is iterated up to 10 steps below.
		* Iteration 1: 999 * 999; 999 * 998; ... ; 999 * 989;
		* Iteration 2: 998 * 999; 998 * 998; ... ; 998 * 989;
		* And so on until...
		* Iteration n: 333 * 999; 333 * 998; ... ; 333 * 989;
		*/
		for( ; y >= cy - 10; --y) {
			product = x * y;

			if(isPalindromic(returnNumVec(product))) {
				cout << "The largest palindrome product possible from two 3-digit numbers is "
					<< product << " with the factors of " << x << " and " << y << "." << endl;

				break;			// NOTE: This breaks our of the inner loop only
								// The same condition has to be placed in the outer loop
								// for a complete exit.
			}
		}

		y = cy;

		if(isPalindromic(returnNumVec(product))) {
			break;
		}
	}

	return 0;
}
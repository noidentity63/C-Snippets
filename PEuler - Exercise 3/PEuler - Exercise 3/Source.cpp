/*
*	Solution to Project Euler's Exercise #3
*	Author: Brei
*
*	The prime factors of 13195 are 5, 7, 13 and 29.
*
*	What is the largest prime factor of the number 600851475143 ?
*/

#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;


bool isPrime(long long int num)
{
	for(int i = 2; i <= num / 2; ++i) {
		
		if(num % i == 0) {
			return false;
		}
	}

	return true;
}

void isPrimeTest()
{
	while(true) {

		cout << "Input number: ";

		long long int input;
		cin >> input;

		// Input validation
		if(!cin) {
			cerr << "Invalid input. Terminating program..." << endl;

			// Flush input stream
			cin.clear();						// clears error flags
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			/*
			streamsize is a type. cin.ignore() takes two arguments: the maximum number of characters
			to ignore (type is streamsize), and the delimiter after which to stop ignoring
			(type is char). std::numeric_limits<streamsize>::max() means "the largest number that
			can fit into a variable of type streamsize. So the whole line means "ignore as many 
			characters as necessary until you ignore a newline, then stop
			*/

			break;
		}

		if(isPrime(input)) {
			cout << "Prime number" << endl;
		}
		else {
			cout << "Composite number" << endl;
		}

		cin.clear();						// clears error flags
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	}
}

int largestPrimeFactor(long long int num)
{
	/* Note: Weird behavior when num = 9 and other numbers with 3 as a factor.
	* Behavior seems similar to an infinite loop.
	* FIXED: Silly mistake. { int temp = 2 } was placed inside the while loop, no wonder it's infinite
	* as it keeps getting reassigned to 2.
	*/
	vector<long long int> factors;

	long long int temp = 2;					// initialized to smallest prime number

	// Iterate through each possible prime factor of num starting from 2
	while(!isPrime(num)) {

		// Check if each iteration is a factor AND a prime number
		if(num % temp == 0 && isPrime(temp)) {
			num /= temp;				
		}
		else {
			++temp;
		}
								
	}
	
	return num;				// return the largest value left in the series of divisions
}

vector<long long int> fetchFactors(long long int num)
{
	vector<long long int> factors;
	
	long long int temp = 2;

	while(!isPrime(num)) {

		// Check if each iteration is a factor AND a prime number
		if(num % temp == 0 && isPrime(temp)) {
			num /= temp;				
			factors.push_back(temp);		// not connected with the exercise but included a vector
											// that stores all the prime factors within the iteration
		}
		else {
			++temp;
		}							
	}

	factors.push_back(num);					// appends the largest prime factor to the vector

	return factors;
}

int main()
{
	//isPrimeTest();

	while(true) {

		cout << "Input number: ";

		long long int input;
		cin >> input;

		// Input validation
		if(!cin) {
			cerr << "Invalid input. Terminating program..." << endl;

			// Flush input stream
			cin.clear();						// clears error flags
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			/*
			streamsize is a type. cin.ignore() takes two arguments: the maximum number of characters
			to ignore (type is streamsize), and the delimiter after which to stop ignoring
			(type is char). std::numeric_limits<streamsize>::max() means "the largest number that
			can fit into a variable of type streamsize. So the whole line means "ignore as many 
			characters as necessary until you ignore a newline, then stop
			*/

			break;
		}

		cout << "Prime factors: ";

		vector<long long int> factors = fetchFactors(input);
		for(unsigned int i = 0; i < factors.size(); ++i) {
			cout << factors[i] << " ";
		}
		cout << endl;

		cout << "Largest prime factor: " << largestPrimeFactor(input) << endl << endl;

		cin.clear();						// clears error flags
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	}
	
	return 0;
}
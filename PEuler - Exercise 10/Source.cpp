/*
*	Solution to Project Euler's Exercise #10
*	Author: Brei
*
*	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

*	Find the sum of all the primes below two million.
*/

#include<iostream>
using namespace std;


bool isPrime(long long num)
{
	for(int i = 2; i <= num / 2; ++i) {
		
		if(num % i == 0) {
			return false;
		}
	}

	return true;
}

// BRUTE FORCE: Loop the loop
long long sumPrimesBelow(long long num)

{
	long long cnt = 2, result = 0;

	// Start iteration from 2, then proceed with 3 and then followed by a pattern of adding 2
	// (2, 3, 5, 7, 9, ...)
	while(cnt < num) {

		// If prime, add current iteration to the result
		if(isPrime(cnt)) {
			result += cnt;
		}

		// If at the first prime number, increment just by 1
		if(cnt == 2) {
			++cnt;
		}
		else {
			cnt += 2;
		}
	}

	return result;
}

// Try the Sieve of Erastothenes next

int main()
{
	long long num = 2000000;

	// Test sumPrimesBelow(num)
	cout << "The sum of all prime numbers below " << num << " is " << sumPrimesBelow(num) << endl;
	// Answer = 142913828922

	return 0;
}
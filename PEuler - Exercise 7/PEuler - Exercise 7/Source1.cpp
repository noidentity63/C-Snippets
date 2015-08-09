/*
*	Solution to Project Euler's Exercise #7
*	Author: Brei
*	
*	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
*
*	What is the 10 001st prime number?
*/


#include<iostream>
using namespace std;

bool isPrime(unsigned int num)
{
	for(unsigned int i = 2; i <= num / 2; ++i) {
		
		if(num % i == 0) {
			return false;
		}
	}

	return true;
}

bool isOdd(unsigned int num)
{
	if(num % 2 == 0) {
		return false;
	}

	return true;
}

// Method #1: Iteration aka BRUTE FORCE
unsigned int getNthPrime(unsigned int nth)
{
	unsigned int cnt = 1, current = 2;

	while(cnt < nth) {
		cout << "Prime number #" << cnt << ":\t" << current << endl;

		// If currentPrime is 2, increment current and cnt by 1
		if(current == 2) {
			++current;
			++cnt;
		}


		// If current is odd AND prime, update currentPrime, increment current by 2 and
		// increment cnt by 1
		if(isOdd(current) && isPrime(current)) {
			++cnt;
			current += 2;
		}

		// Keep on checking the value of current and keep incrementing by 2 as long as it's not
		// odd or prime. DON'T increment cnt.
		while(!isOdd(current) || !isPrime(current)) {
			current += 2;
		}
	}

	return current;
}

// Method #2: Number Theory

int main()
{
	// Test isOdd(x)
	unsigned int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (int i = 0 ; i != 10; ++i) {
		
		if(isOdd(arr[i])) {
			cout << arr[i] << " is odd." << endl;
		}
		else {
			cout << arr[i] << " is even." << endl;
		}
	}

	cout << endl;

	// Test getNthPrime(x)
	int cnt = 10001;

	cout << "n = " << cnt << endl;
	cout << "Prime number #" << cnt << ":\t" << getNthPrime(cnt) << endl;

	return 0;
}
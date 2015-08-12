#ifndef LARGE_NUM_H
#define LARGE_NUM_H

#include<vector>
#include<string>

struct LargeNum
{
	std::string numString;

private:
	// Method that checks if two numbers are adjacent
	// Note that the order is important; num1 is the first number and thus the reference
	bool isAdjacent(int num1, int num2) {
		// If the two numbers are next to each other, return true
		if((num1 == (num2 - 1)) || (num1 == (num2 + 1)) || (num2 == (num1 - 1))
			|| (num2 == (num1 + 1))) {
				return true;
		}

		return false;
	}

	std::vector<int> storeNumString(std::string numString)
	{
		std::vector<int> digits;

		for (auto c : numString) {

			//if(isdigit(numString[c])) {
				digits.push_back(c - '0');
			//}
		}

		return digits;
	}

	std::vector<int> storeAdjacentFactors(std::string numString)
	{
		std::vector<int> factors;
		
		// Iterate through the string with a ranged-for statement
		for(decltype(numString.size()) c = 0; c < numString.size(); ++c) {

			// Check if each string character is a digit
			if(isdigit(numString[c])) {
				// numString[c] - 48
				int digit1 = numString[c] - '0', digit2 = 0;

				if(c != numString.size()) {
					digit2 = numString[c + 1] - '0';

					// If isDigit is at the end of string, digit2 will be the previous number
					if(c == numString.size() - 1) {
					digit2 = numString[c - 1] - '0';

					}
				}

				// If a digit, compare the current digit with the next digit and check if they're
				// adjacent
				if(isAdjacent(digit1, digit2)) {
					factors.push_back(digit1);
				}
				else {
					if (c > 0) {
						digit2 = numString[c - 1] - '0';
					}

					// 1156008				5

					if(isAdjacent(digit1, digit2)) {
						factors.push_back(digit1);
					}
					else {
						factors.push_back(0);
					}
				}
			}
		}	

		return factors;
	}

public:

	// The class methods can't access the class variable directly, it has to be returned through
	// an in-class function with a 'this' routine
	std::string getNumString()
	{
		return this -> numString;
	}

	int largestProduct(unsigned int cnt)
	{
		int factorCnt = 0, largestProduct = 0, currentProduct = 1;
		std::vector<int> factors = storeAdjacentFactors(numString);

		for(auto factor : factors) {
			// Check if the value within the current vector iteration is a nonzero
			// If it is a nonzero, increment factorCnt and get the current product.
			if(factor != 0) {
				++factorCnt;
				currentProduct *= factor;
			}
			// If it is a zero, check if factorCnt is equal to the cnt argument.
			else {

				if((factorCnt == cnt) && (currentProduct > largestProduct)) {
					largestProduct = currentProduct;
				}

				// Reset factorCnt
				factorCnt = 0;
			}
		}

		return largestProduct;
	}

	void displayAdjFactors()
	{
		std::vector<int> factors = storeAdjacentFactors(numString);

		// Iterate through the whole vector and display for each iteration
		for(decltype(factors.size()) i = 0; i < factors.size(); ++i) {
		
			std::cout << factors[i] << " ";

			/*
			// Create a new line if current output is 0
			if(factors[i] == 0) {
				std::cout << std::endl;
			}
			*/
		}
	}

	void displayNum()
	{
		std::vector<int> num = storeNumString(numString);

		for(decltype(num.size()) i = 0; i < num.size(); ++i) {
			std::cout << num[i];
		}

		std::cout << std::endl;
	}
};

#endif
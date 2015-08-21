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
			|| (num2 == (num1 + 1)) || (num1 == num2)) {
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

	// Stores the adjacent numbers of numString
	std::vector<int> storeAdjacentFactors(std::string numString)
	{
		int refDigit = 0;
		unsigned int factorCnt = 0;
		std::vector<int> factors;
		
		// Iterate through the string with a ranged-for statement
		for(decltype(numString.size()) c = 0; c < numString.size(); ++c) {

			// Check if each string character is a digit
			if(isdigit(numString[c])) {
				// numString[c] - 48
				int currDigit = numString[c] - '0', digit2 = numString[c + 1] - '0';
			
				if(factorCnt == 0 && isAdjacent(currDigit, digit2)) {
						factors.push_back(currDigit);
						++factorCnt;

						refDigit = currDigit;	
				}
				else {
					// Compare the current digit with the next digit and check if they're
					// adjacent
					if(isAdjacent(refDigit, currDigit)) {
						factors.push_back(currDigit);
						++factorCnt;
					}
					else {
						if(c == numString.size() - 1) {
							digit2 = refDigit;
						}
					
						// 6911566500899898998471567			15			0 
						factors.push_back(0);
						factorCnt = 0;	

						if(isAdjacent(currDigit, digit2)) {
							factors.push_back(currDigit);
							++factorCnt;

							refDigit = currDigit;
						}
						else {
							refDigit = 0;
						}
					}
					/*
					else {
						factors.push_back(0);
					}
					*/
				}
			}

			//std::cout << factors[c] << " ";
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

	long long int largestProduct(unsigned int cnt)
	{
		long long int largestProduct = 0, currentProduct = 1;
		unsigned int factorCnt = 0;
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
				currentProduct = 1;
				factorCnt = 0;
			}
		}

		return largestProduct;
	}

	long long int getLargestProduct(unsigned int cnt)
	{
		long long int largestProduct = 0, currentProduct = 1;
		unsigned int factorCnt = 0;
			
		// Iterate through the string with a ranged-for statement
		for(decltype(numString.size()) c = 0; c < numString.size() - (cnt - 2); ++c) {

			// Check if each string character is a digit
			if(isdigit(numString[c])) {
				// numString[c] - 48
				currentProduct = 1;
			
				for(unsigned int d = 0; d < cnt; ++d) {
					// Check each iteration if adjacent
					// If adjacent, keep on multiplying
					if(isAdjacent(numString[c] - '0', numString[c + d] - '0')) {
						currentProduct *= numString[c + d] - '0';
					}
				}

				if(currentProduct > largestProduct) {
					largestProduct = currentProduct;
				}
			}
			//std::cout << factors[c] << " ";
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
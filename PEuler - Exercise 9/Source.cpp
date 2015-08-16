/*
*	Solution to Project Euler's Exercise #8
*	Author: Brei
*	
*	A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

	a^2 + b^2 = c^2
*
*	For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2

*	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc.
*/

#include<iostream>
#include<math.h>
#include<Windows.h>
using namespace std;

int abc()
{
	unsigned int m = 1, n = 2; 

	/* When m and n are any two positive integers (m < n):

		a = n^2 - m^2
		b = 2nm
		c = n^2 + m^2
	*/
	int a = (n * n) - (m * m), b = 2 * (n * m), c = (n * n) + (m * m), product = 0;
	int scale = 2;

	// Check if all conditions for the Pythagorean triplet are valid
	// a < b < c
	if ((a < b) && (b < c)) {

		// Scale up through the Pythagorean triples (x2 scale) until a + b + c = 1000
		while((a + b + c) != 1000) {
			a = (n * n) - (m * m), b = 2 * (n * m), c = (n * n) + (m * m);
			int a1 = a, b1 = b, c1 = c;

			for(int addToScale = 0; addToScale < 6; ++addToScale) {

				for(;;) {
					cout << a1 << " ";
					cout << b1 << " ";
					cout << c1 << " \t\t";
					cout << a1 + b1 + c1;
					cout << endl;

					a1 *= scale + addToScale, b1 *= scale + addToScale, c1 *= scale + addToScale;
					
					if((a1 + b1 + c1) >= 1000) {
						a1 = a, b1 = b, c1 = c;
						break;
					}

					Sleep(500);
				}
				
				if((a + b + c) >= 1000) {
					break;
				}

				Sleep(1000);
			}

			cout << a1 << " ";
			cout << b1 << " ";
			cout << c1 << " \t";
			cout << a1 + b1 + c1;
			cout << endl;

			++n, ++m;
		}

		if((a + b + c) == 1000) {
			product = a * b * c;
		}

	}
	else {
		return -1;
	}
	
	return product;
}

// Another attempt
int abcMethod2(int a, int b, int c)
{
	int a1 = a, b1 = b, c1 = c, product = 0;

	if(a < b && b < c) {
		
		while(true) {
			int scale = 0;

			for(;; ++c1) {

				// Iterate through b1 until it becomes equal or greater than c1
				for(int i = b1; i < c1; ++i) {

					// Iterate through a1 until it becomes equal or greater than b1
					for(int j = a1; j < i; ++j) {

						// Check if the three numbers are Pythagorean triples
						if((j * j) + (i * i) == (c1 * c1)) {

							//Check if the three numbers sum up to 1000
							if((i + j + c1) == 1000) {
								product = i * j * c1;
								return product;
							}

							if((i + j + c1) > 1000) {
								++scale;
							}
						}

					cout << j << " " << i << " " << c1 << " \t\t" << j + i + c1 << endl;
					//Sleep(150);
					}
				}
			}
		}	
	}
	else {
		cerr << "Pythagorean triplet condition (a < b < c) not met" << endl;
	}

	return 0;
}


int main()
{
	cout << "a x b x c = " << abcMethod2(3, 4, 5) << endl;		// Answer: 31875000 (200, 375, 425)

	//abcMethod2(3, 4, 5);

	return 0;
}
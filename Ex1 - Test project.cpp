#include <iostream>
using namespace std;

double square(double x)
{
	return x*x;
}

double input_num()
{
	double x;

	cout << "Input number to be squared: ";
	cin >> x;

	return x;
}

void print_square(double num)
{
	cout << "The square of " << num << " is " << square(num) << ".\n";
}

int sum50_100()
{
	// Returns the sum of a set of numbers from 50 to 100 inclusive
	int sum = 0, cnt = 50;

	while (cnt <= 100) {
		sum += cnt;
		++cnt;
	}

	return sum;
}

int sum100_100()
{
	// Returns the sum of a set numbers from -100 to 100 inclusive
	int sum = 0;

	for(int i = -100; i <= 100; ++i) {
		sum += i;
	}

	return sum;
}

void sum_iset()
{
	double sum = 0, input = 0, set[10] = { };
	int count = 0;

	cout << "Type the numbers to be added, each separated by a space" << endl;

	while(cin >> input) {
		// while there is a value in the input stream, execute this block
		set[count] = input;
		sum += input;
		++count;
	}

	cout << "The sum of all the inputs (";
	for(int i = 0; i < count; ++i) {
		if (i == count - 1) {
			// checks if count is at the end of the array
			cout << set[i];
		}
		else {
			cout << set[i] << ", ";
		}
	}
	cout << ") is " << sum << "." << endl << endl;

	cin.ignore(INT_MAX);
}

void num_occur()
{
	// NOTE:	There is still confusion regarding this function
	//			The last distinct numbers won't print at the console

	double val = 0, curr_val = 0;
	int cnt = 0;

	cout << "Input a string of numbers (separated by spaces). Press Ctrl - Z and then Enter to continue." << endl;

	if(cin >> curr_val) {
		// if (cin >> curr_val) ensures that the input isn't empty
		cnt = 1;

		while(cin >> val) {
			if (val == curr_val) {
				++cnt;
			}
			else {
				cout << curr_val << " occurs " << cnt << " time/s. " << endl;

				curr_val = val;		// remember the new value
				cnt = 1;			// reset counter
			}
		}

		cout << curr_val << " occurs " << cnt << " time/s. " << endl;
	}

	cin.ignore(INT_MAX);
}


int main()
{
	//input_num();
	//print_square(input_num());

	//cout << "The size of a double type is " << sizeof(double) << ".\n";

	cout << "The sum of the set of numbers from 50 to 100 is " << sum50_100() << "." << endl;
	cout << "The sum of the set of numbers from -100 to 100 is " << sum100_100() << "." << endl << endl;

	//sum_iset();
	num_occur();

	return 0;
}
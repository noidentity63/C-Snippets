#include <iostream>
#include "Sales_item.h"
using namespace std;

int main()
{
	unsigned u1 = 10, u2 = 42;

	cout << u2 - u1 << endl;		// displays 32
	cout << u1 - u2 << endl;		// displays 4294967264

	Sales_item total;

	if(cin >> total) {

		Sales_item trans;	// running sum

		while(cin >> trans) {
			if(total.isbn() == trans.isbn()) {
				trans += total;
			}
			else{
				cout << trans << endl;
				total = trans;
			}
		}

		cout << total << endl;

		return 0;
	}

	else {

		cerr << "No data?!" << endl;

		return -1;
	}

}
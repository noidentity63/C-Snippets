#include<iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
	// Define two class instances
	Sales_data book1, book2;

	// code to read into book1 and book2
	double price = 0;

	cin >> book1.bookNo >> book1.units_sold >> price;
	book1.revenue = book1.units_sold * price;

	cin >> book2.bookNo >> book2.units_sold >> price;
	book2.revenue = book2.units_sold * price;

	// code to check whether the instances have an equal ISBN
	// if ISBNs are equal, print the sum of the two objects
	if(book1.bookNo == book2.bookNo) {
		unsigned totalCnt = book1.units_sold + book2.units_sold;
		double totalRevenue = book1.revenue + book2.revenue;

		// print: ISBN, total sold, total revenue, average price per book
		cout << book1.bookNo << "\t" << totalCnt << "\t" << totalRevenue << "\t";

		// if no books are sold, print out the fact
		if(totalCnt != 0) {
			cout << totalRevenue / totalCnt << endl;
		}
		else {
			cout << "(No sales)" << endl;
		}
		return 0;
	}
	else {
		cerr << "Data must refer to same ISBN." << endl;
		return -1;
	}

}
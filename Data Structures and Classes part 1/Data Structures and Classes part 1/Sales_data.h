// It is best practice to include header guards							

#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<string>					// #include is called a preprocessor

struct Sales_data {
	// Creates a data structure (or class) named Sales_data
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};

#endif
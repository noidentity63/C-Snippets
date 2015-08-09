// Create a School_data class containing the grading system data, etc.
#ifndef SCHOOL_DATA_H
#define SCHOOL_DATA_H
#include<vector>
#include<string>

struct School_data
{
	std::vector<double> fourScales;
	std::vector<double> percentages;

	std::string name;
};

#endif
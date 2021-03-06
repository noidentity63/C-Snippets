/*
*
*	Silliman University Grade Converter
*	Author: Brei
*
*	Desc: A simple program that receives user input whose value is a grade in either the
		4.0 scale (1.0 - 4.0) or percentage form (73 - 100), and converts it to the other.
*
*	Table of grades (data obtained from SU's student manual):

	
	A (Excellent)		4.0		4.0, 3.9, 3.8				Excellent		97 � 100
	A-(Very Good)		3.5		3.7, 3.6, 3.5, 3.4, 3.3		Superior		93 � 96
	B (Good)			3.0		3.2, 3.1, 3.0, 2.9, 2.8		Good			89 � 92
	B-(Above Average)	2.5		2.7, 2.6, 2.5, 2.4, 2.3		Above Average	85 � 88
	C Average			2.0		2.2, 2.1, 2.0, 1.9, 1.8		Average			81 � 84
	C-Below Average		1.5		1.7, 1.6, 1.5, 1.4, 1.3		Below Average	77 � 80
	P Passing			1.0		1.2, 1.1, 1.0				Passing			73 � 76
	F Failure			0.0		0.0							Failure			72 & below
*
*/

/*
	The <windows.h> header has had the min() and max() macros since time immemorial, and they 
	frequently cause problems with C++. Fortunately, you can disable them by adding 
	#define NOMINMAX before including <windows.h>.
*/
#define NOMINMAX

#include<conio.h>
#include<chrono>
#include<future>
#include<iostream>
#include<limits>
#include<thread>
#include<Windows.h>
#include "School_data.h"
using namespace std;

// BONUS: Clear screen function (for Windows only)
void clearScreen(bool moveToHomeOnly)			// moveToHomeOnly is true if you only need to move
												// the cursor to home
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );

	if(!moveToHomeOnly) {
		
		if (hStdOut == INVALID_HANDLE_VALUE) return;

		/* Get the number of cells in the current buffer */
		if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
		cellCount = csbi.dwSize.X *csbi.dwSize.Y;

		/* Fill the entire buffer with spaces */
		if (!FillConsoleOutputCharacter(
			hStdOut,
			(TCHAR) ' ',
			cellCount,
			homeCoords,
			&count
			)) return;

		/* Fill the entire buffer with the current colors and attributes */
		if (!FillConsoleOutputAttribute(
			hStdOut,
			csbi.wAttributes,
			cellCount,
			homeCoords,
			&count
			)) return;

	}

	/* Move the cursor home */
	SetConsoleCursorPosition( hStdOut, homeCoords );
 }

void displayTable(vector<double> table)
{
	decltype(table.size()) cnt = 0;			// decltype = declare type
											// the type of cnt will be the same as the type
											// of table.size()
	
	//auto cnt = 0;							// auto can also be the alternative for decltype

	while(cnt < table.size()) {
		cout << table[cnt] << "\t";

		if(table[cnt] == 97 || table[cnt] == 93 || table[cnt] == 89 || table[cnt] == 85
			|| table[cnt] == 81 || table[cnt] == 77 || table[cnt] == 73) {
				cout << endl;
		}

		if((table[cnt] <= 3.8 && table[cnt] > 3.79) || (table[cnt] <= 3.3 && table[cnt] > 3.29) 
			|| (table[cnt] <= 2.8 && table[cnt] > 2.79) || (table[cnt] <= 2.3 && table[cnt] > 2.29)
			|| (table[cnt] <= 1.8 && table[cnt] > 1.79) || (table[cnt] <= 1.3 && table[cnt] > 1.29) 
			|| (table[cnt] <= 1.0 && table[cnt] > 0.99)) {
				cout << endl;
		}

		++cnt;
	}

}

double toPercentage(double gradeRate)
{
	double result = 0;

	/*
	vector<double> percentages;

	for(double percent = 100; percent >= 73; --percent) {
		percentages.push_back(percent);
	}

	displayTable(percentages);
	*/

	switch((int) (gradeRate * 10)) {

	case 40:		result = 100;	break;
	case 39:		result = 99;	break;
	case 38:		result = 97;	break;

	case 37:		result = 96;	break;
	case 36:
	case 35:		result = 95;	break;
	case 34:		result = 94;	break;
	case 33:		result = 93;	break;

	case 32:		result = 92;	break;
	case 31:
	case 30:		result = 91;	break;
	case 29:		result = 90;	break;
	case 28:		result = 89;	break;

	case 27:		result = 88;	break;
	case 26:
	case 25:		result = 87;	break;
	case 24:		result = 86;	break;
	case 23:		result = 85;	break;

	case 22:		result = 84;	break;
	case 21:
	case 20:		result = 83;	break;
	case 19:		result = 82;	break;
	case 18:		result = 81;	break;

	case 17:		result = 80;	break;
	case 16:
	case 15:		result = 79;	break;
	case 14:		result = 78;	break;
	case 13:		result = 77;	break;

	case 12:		result = 76;	break;
	case 11:		result = 74;	break;
	case 10:		result = 73;	break;
	}

	return result;
}

double to4Scale(double gradePrcnt)
{
	double result = 0;

	/*
	vector<double> rates;

	for(double rate = 4.0; rate >= 0.99; rate -= 0.1) {
		rates.push_back(rate);
	}
	
	displayTable(rates);
	*/

	switch((int) gradePrcnt) {

	case 100:		result = 4.0;	break;
	case 99:		
	case 98:		result = 3.9;	break;
	case 97:		result = 3.8;	break;

	case 96:		result = 3.7;	break;
	case 95:		result = 3.5;	break;
	case 94:		result = 3.4;	break;
	case 93:		result = 3.3;	break;

	case 92:		result = 3.2;	break;
	case 91:		result = 3.0;	break;
	case 90:		result = 2.9;	break;
	case 89:		result = 2.8;	break;
	
	case 88:		result = 2.7;	break;
	case 87:		result = 2.5;	break;
	case 86:		result = 2.4;	break;
	case 85:		result = 2.3;	break;

	case 84:		result = 2.2;	break;
	case 83:		result = 2.0;	break;
	case 82:		result = 1.9;	break;
	case 81:		result = 1.8;	break;

	case 80:		result = 1.7;	break;
	case 79:		result = 1.5;	break;
	case 78:		result = 1.4;	break;
	case 77:		result = 1.3;	break;

	case 76:		result = 1.2;	break;
	case 75:		result = 1.1;	break;
	case 74:		result = 1.0;	
	case 73:		result = 1.0;	break;

	}

	return result;
}

bool mainMenuInvalid() 
{
	return false;
}

bool mode1Invalid() 
{
	return false;
}

bool mode2Invalid()
{
	return false;
}

void displayTimer(int cnt) 
{
	// Create a 5-second timer
	// Iterate a Sleep(1000 function) five times.
	for(auto i = cnt; i > 0; --i) {
		cout << " Resuming operation in " << i;

		if (i == 1) {
			cout << " second.";
		}
		else {
			cout << " seconds.";
		}

		auto length = 34;

		while(length > 0) {
			cout << "\b";
			--length;
		}

		Sleep(1000);
	}
}

void marquee(string phrase)
{
	decltype(phrase.size()) length = phrase.size();

	cout << phrase;

	while(true) {
		unsigned int cnt = 0;

		Sleep(100);
		// Scroll to the right
		while(cnt < length) {
			cout << "\b";
			++cnt;
		}
		cout << " " << phrase;

		// If the last character of the string reached the end of the cmd window
		// Scroll to the left
	}
}

void pause(bool showOutput)
{
	if (showOutput) {
		cout << "Press ENTER to continue...";
	}
	cin.sync();
	cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
}

void displayConsoleWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	auto width = 0;
	// Check if there is are readable console values
	if(!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		cerr << "Cannot determine console size." << endl;
	}
	else {
		width = csbi.dwSize.X;

		cout << "The console is " << csbi.srWindow.Right - csbi.srWindow.Left << " wide" << endl;
	}

	cout << endl;
}

int getConsoleWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	auto width = 0;
	// Check if there is are readable console values
	if(!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		cerr << "Cannot determine console size." << endl;
		return -1;
	}
	else {
		width = csbi.dwSize.X;

		//width = csbi.srWindow.Right - csbi.srWindow.Left;

		//cout << "The console is " << csbi.srWindow.Right - csbi.srWindow.Left << " wide" << endl;
	}

	return width;
}

void displayIntro()
{
	vector<const string> message;

	message.push_back("Hello, User.");
	message.push_back("I will be your guide throughout this program session. :)");
	message.push_back("I hope this application will serve its purpose.");

	// Show letters one by one with a for-loop
	for(auto i = 0; i < message.size(); ++i) {

		// for (0, 79), the midpoints are (39, 40)
		// Method for placing text to the middle of console.
		for(auto a = 0; a < getConsoleWidth() / 2; ++a) {
			cout << " ";
		}

		for(auto b = message[i].size() / 2; b > 0; --b) {
			cout << "\b";
		}

		for(auto j = 0; j < message[i].size(); ++j) {
			// Store string to a temp output buffer
			auto output = message[i];

			cout << output[j];
			Sleep(60);

			// If a key is pressed in the middle of the intro sequence,
			// break the operation and proceed to the main menu.
			if(_kbhit() != 0) {
				return;
			}
		}

		cout << endl << endl;
		Sleep(1250);

	}

	Sleep(2250);
	/*
	cout << message[0] << endl << endl;
	Sleep(1500);
	cout << message[1] << endl << endl;
	Sleep(1500);
	cout << message[2] << endl << endl;
	*/
}

int main()
{
	// Testing displayTable(vector<double>) in the following conversion functions
	/*
	toPercentage(0);
	cout << endl;
	to4Scale(0);
	cout << endl;
	*/
	cout << endl << endl << endl << endl;
	displayIntro();

	bool flag = true;

	// Perform input routines and error checking, and only exit when the user wants to
	while(flag == true) {
		clearScreen(false);

		// Testing getConsoleWidth()
		// cout << getConsoleWidth();

		double input = 0;
		unsigned int mode = 0;

		/*
		// Marquee text
		thread t1Marquee(marquee, "Hello, User.");
		Sleep(5000);
		*/

		// Prompt for the mode. Mode 1 converts to percentage while Mode 2 converts to 4-scale
		// Mode 3 exits the program
		cout << endl << endl
			<< "Welcome to the Grade Converter - Silliman University edition. :)" << endl 
			<< "This is a simple console application that converts Your grades"
			<< endl << "between their 4-scale and percentage forms." 
			<< endl << endl << endl << "Menu" << endl << endl
			<< "1. 4-Scale to Percentage"	<< endl
			<< "2. Percentage to 4-Scale"	<< endl
			<< "3. Exit (or You can just click the 'x' button at the top right of this window)"	
			<< endl << endl
			<< "Input the number of Your choice and press ENTER. ";
		cin >> mode;									// 1\n
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		/* Move the cursor home */
		//clearScreen(true);

		// Mode 1 code block
		while(mode == 1) {
			// Clear screen first
			clearScreen(false);

			cout << endl << endl << "Type in the grade to convert (1.0 - 4.0): ";
			cin >> input;
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			// Error checker
			if(input >= 1.0 && input <= 4.0) {
				cout << endl << "\t\t"
					<< input << " => " << toPercentage(input) << "%" << endl
					<< endl << "Press ENTER to go back to the Menu. ";

				pause(false);

				mode = 0;
			}
			// Check if input is not an int
			else if(!cin >> (int) input) {
				cerr << "Your input isn't a number." << endl << endl;

				cin.clear();
				pause(true);
			}
			else {
				cerr << "Your input is not within range." << endl << endl;

				pause(true);
			}
		}
		// Mode 2 code block
		while(mode == 2) {
			// Clear screen first
			clearScreen(false);

			cout << endl << endl << "Type in the grade to convert (73 - 100): ";
			cin >> input;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			// Error checker
			if(input >= 73 && input <= 100) {
				cerr << endl << "\t\t"
					<< input << "% => " << to4Scale(input) << endl
					<< endl << "Press ENTER to go back to the Main menu. ";

				pause(false);

				mode = 0;
			}
			// Check if input is not an int
			else if(!cin >> (int) input) {
				cerr << "Your input isn't a number." << endl << endl;

				cin.clear();
				pause(true);
			}
			else {
				cout << "Your input is not within range." << endl << endl;

				pause(true);
			}
		}
		// Mode 3 code block
		while(mode == 3) {
			flag = false;

			// Clear the screen and show a final message
			clearScreen(false);

			cout << "Thank you for using this program! Now, press ENTER again to exit." << endl;

			pause(false);

			mode = 0;
			//system("pause");
		}
		// Invalid Input
		if(mode > 3) {
			cerr << endl << "No such mode exists." 
				<< endl;

			displayTimer(4);
		}
		// Invalid Input
		if(!cin >> mode) {
			cerr << endl << "Sorry, I can't process letters. No such mode exists." 
				<< endl;

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			displayTimer(4);
		}

	// finish_p.set_value();
	// t1Marquee.join();

	}

	return 0;			// Program performed successfully
}
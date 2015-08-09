// Boolean experimentations
// Note that there should only be one main() function within a created project

#include <iostream>
using namespace std;

bool accept()
{
	char ans = 0;

	cout << "Do you want to proceed? (y/n)	";
	cin	>> ans;

	if (ans == 'y') {
		return true;
	}

	return false;
}

bool accept4()
{
	char ans = 0;

	int tries = 4;

	while(tries >= 0) {

		cout << "Do you want to proceed? (y/n)	";
		cin	>> ans;

		switch(ans) {
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			cout << "Invalid input. You have " << tries;

			if (tries == 1) {
				cout << " try left.\n\n";
			}
			else {
				cout << " tries left.\n\n";
			}

			--tries;
		}
	}

	return false;

}

/*
int main()
{
	if (accept4() == true) {
		cout << "Proceeding...\n";
	}
	else {
		cout << "Terminating...\n";
	}
}
*/
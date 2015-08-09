#include <iostream>
using namespace std;

int count_x(char* p, char x)
{
	// counts the occurences of x in p[]
	// p is assumed to point to a zero-ter minated array of char (or to nothing)

	if (p == nullptr) {
		return 0;
	}

	int cnt = 0;

	for (; *p != 0; ++p) {
		if (*p == x) {
			++cnt;
		}
	}

	return cnt;
}

void op_word() {
	char word[10] = {'m', 'i', 's', 's', 'i', 'o', 'n'};

	cout << "Word of the day: ";
	for (auto letter : word) {
		cout << letter;
	}
	cout << " \n\n";
	cout << "Input a letter to search: ";

	char ltr;
	cin >> ltr;

	cout << "There are " << count_x(word, ltr) << " " << ltr << "'s in '" << word << "'.\n\n";
}

int main()
{
	//char word[10] = {'m', 'i', 's', 's', 'i', 'o', 'n'};
	op_word();

}
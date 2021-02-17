#include <iostream>
#include <locale>

using namespace std;

int rows, cols;

void main() {
	setlocale(LC_CTYPE, "RUSSIAN");
	do {
		cout << "Введите количество строк:  " << endl;
		cin >> rows;
	} while (rows <= 0);
	do {
		cout << "Введите количество столбцов:  " << endl;
		cin >> cols;
	} while (cols <= 0);
	int** arr;
	arr = new int* [rows];
}
#include <iostream>
#include <locale>

using namespace std;

int rows, cols;

void array_input(int** arr, int rows, int cols);
void out_array(int** arr, int rows, int cols);
int sum_first_row(int** arr);

int main() {
	setlocale(LC_CTYPE, "RUSSIAN");
	do {
		cout << "¬ведите количество строк:  " << endl;
		cin >> rows;
	} while (rows <= 0);
	do {
		cout << "¬ведите количество столбцов:  " << endl;
		cin >> cols;
	} while (cols <= 0);
	int** arr;
	arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	cout << "¬вод массива:" << endl;
	array_input(arr, rows, cols);

	out_array(arr, rows, cols);

	int sum = 0;
	sum = sum_first_row(arr);
	cout << "—умма первой строки:  " << sum << endl;

	return 0;
}

void array_input(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		cout << "¬ведите строку номер:" << "  " << i + 1 << endl;
		for (int j = 0; j < cols; j++)
		{
			cin >> *(*(arr + i) + j);
		}
	}
}

void out_array(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}
}


int sum_first_row(int** arr) {
	int sum = 0;
	for (int j = 0; j < cols; j++) {
		sum += arr[0][j];
		cout << sum;
	}
	return sum;
}

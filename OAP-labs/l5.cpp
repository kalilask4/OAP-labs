/***********************************************************************************
*                                                                                  *
*  L_5.									    	   *
*																					*
* Тема: Циклические процессы с использованием многомерных массивов. 				*
* Динамическое распределение памяти*												*
*																					*
* ЗАДАНИЕ 1:  																		*
* Написать программу, содержащую пользовательскую функцию, 							*
* решающую сформулированную ниже задачу. Программа печатает массив в виде таблицы, 	*
* ввод элементов массива производится в функции main(). Размеры массива N и M, 		*
* значения элементов массива вводятся с клавиатуры. Обращение к элементам массива	*
* выполняется только через косвенную адресацию, выделение памяти выполняется		*
* функцией new. Предусмотреть реакцию программы в случае, если исходные 			*
* данные не позволяют выполнить поставленную задачу.								*
* Вариант 6.																		*
* Задан двумерный массив М(N, M). 													*
* В массиве вычислить сумму значений элементов первой строки и вывести ее на экран.	*
* 																					*
* 																					*
*************************************************************************************/

#include <iostream>
#include <locale>

using namespace std;

int rows, cols;

void array_input(int** arr, int rows, int cols);
void array_out(int** arr, int rows, int cols);
int sum_first_row(int** arr);

int main() {
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
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	cout << "Ввод массива:" << endl;
	array_input(arr, rows, cols);

	array_out(arr, rows, cols);

	int sum = 0;
	sum = sum_first_row(arr);
	cout << "\nСумма первой строки:  " << sum << endl;

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[]arr;

	return 0;
}

void array_input(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		cout << "Введите строку номер:" << "  " << i + 1 << endl;
		for (int j = 0; j < cols; j++)
		{
			cin >> *(*(arr + i) + j);
		}
	}
}

void array_out(int** arr, int rows, int cols) {
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

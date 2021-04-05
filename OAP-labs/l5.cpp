/************************************************************************************
*                                                                                   *
*  L_5.																	    	    *
*																					*
* ����: ����������� �������� � �������������� ����������� ��������. 				*
* ������������ ������������� ������*												*
*																					*
* ������� 1:  																		*
* �������� ���������, ���������� ���������������� �������, 							*
* �������� ���������������� ���� ������. ��������� �������� ������ � ���� �������, 	*
* ���� ��������� ������� ������������ � ������� main(). ������� ������� N � M, 		*
* �������� ��������� ������� �������� � ����������. ��������� � ��������� �������	*
* ����������� ������ ����� ��������� ���������, ��������� ������ �����������		*
* �������� new. ������������� ������� ��������� � ������, ���� �������� 			*
* ������ �� ��������� ��������� ������������ ������.								*
* ������� 6.																		*
* ����� ��������� ������ �(N, M). 													*
* � ������� ��������� ����� �������� ��������� ������ ������ � ������� �� �� �����.	*
* 																					*
* 																					*
*************************************************************************************/
/*
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
		cout << "������� ���������� �����:  " << endl;
		cin >> rows;
	} while (rows <= 0);
	do {
		cout << "������� ���������� ��������:  " << endl;
		cin >> cols;
	} while (cols <= 0);
	int** arr;
	arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	cout << "���� �������:" << endl;
	array_input(arr, rows, cols);

	array_out(arr, rows, cols);

	int sum = 0;
	sum = sum_first_row(arr);
	cout << "\n����� ������ ������:  " << sum << endl;

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[]arr;

	return 0;
}

void array_input(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		cout << "������� ������ �����:" << "  " << i + 1 << endl;
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
*/
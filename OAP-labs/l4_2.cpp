/********************************************************************************
*   l4_2                                 										*
*	Задача 2																	*
*  Тема:  Циклические процессы с использованием одномерных массивов 			*
*  и функций пользователя. Связь массивов с указателями. Сортировка				*
*  																				*
*  1. Написать пользовательскую функцию, решающую указанную ниже задачу.		*
*  Массив создается в динамической области памяти функцией new.					*
*  При обращении к элементам массива воспользоваться взаимосвязью 				*
*  массивов с указателями.Предусмотреть реакцию программы на ситуации, 			*
*  при которых задача не имеет решения.											*
*  																				*
*  2. После решения основной задачи написать пользовательские функции,			*
*  реализующие сортировку методом пузырька и методом Хоара. Определить, 		*
*  какой метод работает быстрее.												*
*  																				*
*  																				*
*  В одномерном массиве, состоящем из n вводимых с клавиатуры элементов, 		*
*  вычислить:																	*
*  																				*
*  Вариант 6																	*
*  Сумму элементов массива, расположенных между первым и вторым отрицательными	*
*  элементами																	*
*                                                                               *
********************************************************************************/
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>              
#include <conio.h>
#include <stdlib.h>
//array lenght and range of values
#define ARRAY_SIZE 10 
#define ARRAY_START_RANGE -8 
#define ARRAY_END_RANGE 15 


int counter_bubble_sort, counter_Hoare;


void method_Hoare(int*, int, int);
void bubble_sort(int*, int);


void main()
{
	int* a, size, * tmpa;
	int i, j;
	int first_negative_number = 0, second_negative_number = 0, index_first_negative_number = 0, index_second_negative_number = 0, sum;
	int d1, d2;

	//printf("\n Enter the size of the array");
	//scanf("%d", &n);
	//printf("\n Enter start range ");
	//scanf("%d", &d1);
	//printf("\n Enter rnd range");
	//scanf("%d", &d2);

	size = ARRAY_SIZE;
	d1 = ARRAY_START_RANGE;
	d2 = ARRAY_END_RANGE;

	a = new int[size];
	tmpa = new int[size];
	if (!a || !tmpa) {
		printf("\n Not enough memory. Press any key...");
		_getch();
		exit(1);
	}

	for (i = 0; i < size; i++)
	{
		*(a + i) = rand() % (d2 - d1) + d1;
	}
	printf("\n");
	printf("Array created: \n");

	for (i = 0; i < size; i++)
	{
		printf("a[%d]=%d \n", i, *(a + i));
	}
	printf("\n");

	for (i = 0; i < size; i++)
	{
		*(tmpa + i) = *(a + i);
	}
	printf("-------------------------\n");

	//search negative numbers
	for (i = 0; i < size; i++)
	{
		if (a[i] < 0)
		{
			index_first_negative_number = i;
			first_negative_number = a[i];
			//printf("index_first_negative_number %d\t", i);
			//printf("first_negative_number=%d\t", first_negative_number);
			break;
		}
	}

	if (first_negative_number < 0)
	{
		for (j = index_first_negative_number + 1; j < size; j++)
		{
			if (a[j] < 0)
			{
				index_second_negative_number = j;
				second_negative_number = a[j];
				//printf("index_second_negative_number %d\t", j);
				//printf("second_negative_number=%d\t", second_negative_number);
				break;
			}

		}

		// culculate sum 
		if (first_negative_number < 0 && second_negative_number < 0)
		{
			printf("First negative number: %d \n", first_negative_number);
			printf("Second negative number: %d\n", second_negative_number);
			sum = 0;
			printf("sum = ");
			for (i = index_first_negative_number + 1; i < index_second_negative_number; i++)
			{
				sum = sum + a[i];
				printf("+ %d ", a[i]);
			}
			printf("\nSum beetween negative numbers = %d\n", sum);

			printf("-------------------------\n");
			printf("Bubble sort\n");
			bubble_sort(a, size);
			printf("Count of comparisons by Bubble sort method = %d\n", counter_bubble_sort);

			printf("-------------------------\n");
			printf("Hoare method sort\n");
			method_Hoare(a, 0, size - 1);
			for (i = 0; i < size; i++) {
				printf("a[%d] = %d (%d)\n", i, *(a + i), (a + i));
			}
			printf("Count by Hoare sort method = %d\n", counter_Hoare);
		}
		else
		{
			printf("No 2 negative numbers");
			_getch();
			exit(0);
		}

	}
	else
	{
		printf("No negative number.\n");
		_getch();
		exit(1);
	}
	system("pause");
}


void bubble_sort(int* arr, int size)
{
	int i, j;
	int tmp = 0;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (*(arr + j) > *(arr + j + 1)) {

				tmp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = tmp;
				counter_bubble_sort++;
			}

		}
	}
	printf("Sorted *(arr + i)\n");
	for (i = 0; i < size; i++) {
		printf("a[%d]=%d\n", i, *(arr + i));
	}
	printf("Sorted  (arr + i)\n");
	for (i = 0; i < size; i++) {
		printf("a[%d]=%d\n", i, (arr + i));
	}
}


void method_Hoare(int* arr, int left, int right)
{
	int i = left;
	int j = right;
	int tmp;
	int m = arr[(left + right) / 2];
	do
	{
		while (*(arr + i) < m)i++;
		while (*(arr + j) > m)j--;
		if (i <= j)
		{
			if (*(arr + i) > *(arr + j))
			{
				tmp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = tmp;
			}
			i++;
			j--;
		}
		counter_Hoare++;
	} while (i <= j);
	if (left < j) method_Hoare(arr, left, j);
	if (i < right) method_Hoare(arr, i, right);
}




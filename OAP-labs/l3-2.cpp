/********************************************************************************
*                                                                               *
*    L_3-2. Коцуба Д.П.															* 															    
*	1. Вычислить корни функции Y(x) на указанном интервале [a, b]. 			    *
*	Шаг принять равны (b-a)/20.												    *
*	2. Найдите корни уравнения итерационным методом. 						    *
*	Метод нахождения корня оформить в виде отдельной функции. 				    *
*	Выбрать точность eps = 10-4. 											    *
*	Параметры в функцию передать по значению и указателю.					    *
*	3. Найдите корни уравнения методом деления отрезка пополам.				    *
*	Передайте значения в функцию по значению и ссылке. 						    *
*	4. Посчитайте количество итераций, которое понадобится 					    *
*	для нахождения корней каждым из методов.								    *
*																			    *
*																			    *
*	Вариант 6.																	*
*   ln⁡( x)-5 〖sin〗^2⁡( x)														*
*	[2, 6]																		*
*																				*
********************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h>
#include <iostream>
#include <math.h>


double function(double x);
void iterative_calculation(double a, double* b);
void division_calculation(double a, double& b);

int count_iterative; 
int count_half_dividing;

int main() {
	double a = 2.0, b = 6.0; 
	double h = (b - a) / 20.0;
	double a_plus_h;

	printf("Calculation by method\niterative:\t half dividing:\n");
	for (; a <= b; a = a + h) {
		if (function(a) * function(a + h) < 0) {
			iterative_calculation(a, &b);
			a_plus_h = a + h;
			division_calculation(a, a_plus_h);
		}
	}
	printf("\nIterative method: %d operation(s).  \n", count_iterative);
	printf("Half dividing method: %d operation(s).\n", count_half_dividing);
	return 0;
}


double function(double x)
{
	double y = log(x) - 5.0 * pow(sin(x), 2);
	return y;
}


void iterative_calculation(double a, double* b)
{
	double eps = pow(10, -4);
	for (; a <= *b; a = a + eps)
	{
		count_iterative++;
		if ((function(a) * function(a + eps)) <= 0) {
			printf("%f\t", a);
			break;
		}
	}
}


void division_calculation(double a, double& b)
{
	double eps = pow(10, -4);
	while ((b - a) >= eps) {
		count_half_dividing++;

		if ((function(a) * function(a + (b - a) / 2)) <= 0)
		{
			b = b - (b - a) / 2;
		}
		else
		{
			a = a + (b - a) / 2;
		}
	}
	printf("%f\n", a);
}


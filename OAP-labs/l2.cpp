/********************************************************************************
*                                                                               *
*   L_2.																		*
*																				*
*	Задание 1																	*
*	Составить программу для расчета значений z1 и z2							*
*	(результаты должны совпадать).												*																	*										*
*  Вариант 6.																	*
*  z_1=cos⁡α+cos⁡2α+cos⁡6α+cos⁡7α,													*
*  z_2=4 cos⁡(α/2)⋅cos⁡(5/2)α⋅cos⁡4α.												*
*																				*
*	Задание 2																	*
*	Составить программу для расчета значения функции. 							*
*	Вариант 6.																	*
*	β=√(10(∛x+x^(y+2)))((arcsin)^2⁡z-|x-y|).									    *
*	x=0.01655, y=-2.75, z=0.15, res=-40.63										*
*																				*
*	Задание 3																	*
*	Составить программу для определения значения функции. 						*
*	Обязательно предусмотреть вывод сообщения о том, 							*
*	по какой ветви происходило вычисление значения аргумента функции х. 		*
*	Самостоятельно определить исключительные ситуации и предусмотреть 			*
*	диагностические сообщения, если нормальное завершение программы невозможно 	*
*	(например, деление на ноль).												*
*	Вариант6.																	*
*	y=2/3(sin)^2⁡x-3/4(cos)^2⁡⋅x												    *
*	x=z при z<0, x=sinz при z>=0												*
*																				*
*																				*
********************************************************************************/
#include <math.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void task_1();
void task_2();
void task_3();
void task_4();



int main(void) {
	
	//task_1();
	//task_2();
	//task_3();
	task_4();
	
	return 0;
}


void task_1() {
	double a, z1, z2;
	cout << "Enter a" << endl;
	cin >> a;
	z1 = cos(a) + cos(2 * a) + cos(6 * a) + cos(7 * a);
	z2 = 4 * cos(a / 2.) * cos(5. / 2. * a) * cos(4 * a);
	cout << " z1 = " << z1 << endl;
	cout << " z2 = " << z2 << endl;
}


void task_2() {
	setlocale(LC_CTYPE, "Russian");
	double answer, x, y, z;
	cout << "Введите через \"пробел\" 3 числа" << endl;
	cin >> x >> y >> z;
	answer = pow(10 * (pow(x, 1. / 3) + pow(x, y + 2)), 1. / 2) * (pow(asin(z), 2) - fabs(x - y));
	cout << "Результат = " << answer << endl;
}

void task_3() {
	setlocale(LC_CTYPE, "Russian");
	double x, y, z;
	cout << "Введите z " << endl;
	cin >> z;
	if (z < 0) {
		x = z;
		cout << "Результат при z<0: " << endl; // << x << y << endl;
	}
	else {
		x = sin(z);

		cout << "Результат при z>0: " << endl; //<< x << y << endl;
	}
	y = 2. / 3 * (pow(sin(x), 2)) - 3. / 4 * (pow(cos(x), 2));
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}

void task_4() {
	setlocale(LC_CTYPE, "Russian");
	double x, y, z, max1, max2, s, min1;
	bool repeat = true;
	while (repeat)
	{
	m1:
		cout << "Введите 3 числа: x, y, z " << endl;
		cin >> x >> y >> z;
		if (x == y or x == z or y == z) {
			cout << "Введите корректные данные. Не должно выполняться ни одно равенство: x=y, x=z, z=y" << endl;
			goto m1;
		}
		else
			max1 = y > z ? y : z;
		if (max1 == 0) {
			if (y > z) {
				cout << "Если y>z, то y не должен быть равен 0" << endl;
			}
			if (z > y) {
				cout << "Если z>y, то z не должен быть равен 0" << endl;
			}
			goto m1;
		}
		else {
			max2 = x > y ? x : y;
			min1 = max2 < max1 ? max2 : max1;
			s = min1 / max1;
			cout << "Результат = " << s << endl;
		}
		cout << "Повторить? (1-да, 0-нет)" << endl;
		cin >> repeat;
	}
}


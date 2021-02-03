#include <math.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void task_1();
void task_2();


int main(void) {
	
	//task_1();
	task_2();
	
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
	cout << "¬ведите через \"пробел\" 3 числа" << endl;
	cin >> x >> y >> z;
	answer = pow(10 * (pow(x, 1. / 3) + pow(x, y + 2)), 1. / 2) * (pow(asin(z), 2) - fabs(x - y));
	cout << "–езультат = " << answer << endl;
}


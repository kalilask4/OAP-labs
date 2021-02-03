#include <math.h>
#include <iostream>
#include<stdlib.h>

using namespace std;

void task_1();


int main(void) {
	
	task_1();
	
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

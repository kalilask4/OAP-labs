/*stdio.h Ц содержит стандартные функции файлового ввода - вывода;
conio.h Ц функции дл€ работы с консолью (клавиатура, экран монитора);
math.h Ц математические функции;
locale.h Ц дл€ выбора соответствующего €зыка. setlocale();
string.h Ц дл€ работы с различными видами строк;
time.h Ц дл€ конвертации между различными форматами времени и даты;
stdlib.h Ц дл€ выполнени€ множества операций, включа€ конвертацию, генерацию
псевдослучайных чисел, выделение пам€ти, поискаи сортировки;
process.h Ц дл€ очистки

#define _CRT_SECURE_NO_WARNINGS // дл€ возможности
использовани€ scanf
#define MAX_SIZE 100*/

#include<stdio.h>
#include<conio.h>

void input_output() {
	int a = 12, b = -20;
	char c = 'F';
	float f = 12.2341524;
	double d = 2e8;
	//char* string = r("Hello, World!");
	printf("1. Hello world \n");
	//printf("2. %s \n", string);
	printf("3. int a = %d, int b = %i \n", a, b);
	printf("4. floating point f = %f, exp f = %e \n", f, f);
	printf("5. double d = %f or %E \n", d, d);
	printf("6. haracter char c = %c, as number char c = % d \n", c, c);
	//printf("7. address of char c is - %p", c);
}


//int main() {
	
	//input_output();
	//_getch();
	//return 0;
//}
#include <locale>

int* find_min_element(int* array, int array_lenght);
void create_array(int* array, int array_lenght);

int main() {
	setlocale(LC_CTYPE, "Russian");
	int array1_lenght = 2, array2_lenght = 3;

	int* array1 = (int*)calloc(array1_lenght, sizeof(int));
	int* array2 = (int*)calloc(array2_lenght, sizeof(int));

	if (!array1 || !array2) {				
		printf_s("\nНедостаточно памяти! Нажмите любую клавишу\n\n");
		return(2);
	}

	create_array(array1, array1_lenght);
	create_array(array2, array2_lenght);

	int* min_elemrnt_array1 = find_min_element(array1, array1_lenght);
	int* min_element_array2 = find_min_element(array2, array2_lenght);

	int* fst_print;
	int* snd_print;
	int fst_size, snd_size, min_val, idx;

	if (*min_elemrnt_array1 == *min_element_array2) {
		printf("\nМинимальные значения равны (%i)\n\n", *min_elemrnt_array1);
		return 1;
	}
	else {
		if (*min_elemrnt_array1 < *min_element_array2) {
			fst_print = array1;
			snd_print = array2;
			fst_size = array1_lenght;
			snd_size = array2_lenght;
			min_val = *min_elemrnt_array1;
			idx = *(min_elemrnt_array1 + 1);
		}
		else {
			fst_print = array2;
			snd_print = array1;
			fst_size = array2_lenght;
			snd_size = array1_lenght;
			min_val = *min_element_array2;
			idx = *(min_element_array2 + 1);
		}
	}

	printf("\nНаименьшее значение %i (порядковый номер %i) содержит массив: \n\n", min_val, idx + 1);
	printf_s("\t[ ");

	for (int i = 0; i < fst_size; i++) {
	if (i == idx) printf_s(">");
	printf_s("%i ", *(fst_print + i));
	}
	printf_s("]\n\n\n");
	printf("\nВторой массив: \n\n");
	printf_s("\t[ ");
	for (int i = 0; i < snd_size; i++) printf_s("%i ", *(snd_print + i));
	printf_s("]\n\n");

	free(array1);
	free(array2);
	free(min_elemrnt_array1);
	free(min_element_array2);

	return 0;
}


void create_array(int* array, int array_lenght) {
	int i;
	for (i = 2; i < array_lenght; i++) {
		array + i;
	}

	printf_s("\n");
}


int* find_min_element(int* array, int lenght) {
	int i, idx = 0, min = *array;
	for (i = 1; i < lenght; i++) {
		if (min > *(array + i)) {
			min = *(array + i);
			idx = i;
		}
	}
	int* result = (int*)calloc(2, sizeof(int));
	*result = min;
	*(result + 1) = idx;

	return result;
}


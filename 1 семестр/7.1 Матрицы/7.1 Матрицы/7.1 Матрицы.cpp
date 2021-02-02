#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#define n 4
#define k 5
using namespace std;

#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

/*Вариант 9
1)Напишите функцию для работы со встроенным массивом
Количество строк, содержащих только различные элементы.
2)Напишите функцию для работы с двумерным массивом (Ввод/вывод в файл)
Количество строк, в которых нет подряд идущих одинаковых элементов.
*/

void ShowMatrix(int**, int, int);

void ShowMatrix(int[n][k]);

int ExecuteInnerMatrix(int[n][k]);

int ExecuteDynamicMatrix(int**, int, int);

void GetMatrix(int**);

int main(int*)
{
	int a, b, resInner, resDynam;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int innerMatrix[n][k] = { {6,4,3,2,8}, {10,32,21,54,10}, {7,6,5,5,3}, {8,9,10,3,2} };
	ShowMatrix(innerMatrix);
	std::ifstream file;
	cout << "\n  Открываю файл... \n"<< endl;
	file.open("Matrix.txt");
	if (file.is_open()) {
		file >> a >> b;
	}
	else {
		cout << "Нет файла :(";
		exit(1);
	}
	file.close();
	int** dynamicMatrix = new int*[a];
	GetMatrix(dynamicMatrix);
	ShowMatrix(dynamicMatrix, a, b);

	resInner = ExecuteInnerMatrix(innerMatrix);
	resDynam = ExecuteDynamicMatrix(dynamicMatrix, a, b);
	cout << "\n\nТолько различные элементы статичной матрицы содержатся в: " << resInner << " строках";
	cout << "\n\nИдущие подряд элементы в динамической матрице не встречаются в: " << resDynam << " строках";
	cout << "\n\nЗаписываю вывод динамической в output.txt...";
	std::ofstream filer;
	filer.open("output.txt", std::ios::out | std::ios::trunc);
	filer << resDynam;
	filer.close();
	for (int i = 0; i < a; i++) {
		delete[] dynamicMatrix[i];
	}
	delete[] dynamicMatrix;

	_CrtDumpMemoryLeaks();
	return(0);
}

void ShowMatrix(int** matrix, int maxI, int maxJ) {
	for (int i = 0; i < maxI; i++) {
		for (int j = 0; j < maxJ; j++) {
			cout << setw(4) << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void ShowMatrix(int matrix[n][k]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << setw(4) << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

int ExecuteDynamicMatrix(int** matrix, int maxI, int maxJ) {
	int counter = 0;
	for (int i = 0; i < maxI; i++) {
		int check = 1;
		for (int j = 0; j < (maxJ-1); j++) {
			if (matrix[i][j] == matrix[i][j + 1]) check = 0;
			if (check == 0) break;
		}
		counter += check;
	}
	return counter;
}

int ExecuteInnerMatrix(int matrix[n][k]){
	int counter = 0;
	for (int i = 0; i < n; i++) {
		int check = 1;
		for (int j = 0; j < k; j++) {
			for (int t = 0; t < j; t++) {
				if (matrix[i][t] == matrix[i][j]) {
					check = 0;
					break;
				}
			}
			if (check == 0) break;
		}
		counter += check;
	}
	return counter;
}

void GetMatrix(int** matrix) {
	int a;
	int b;
	std::ifstream file;
	file.open("Matrix.txt");
	file >> a >> b;
	for (int i = 0; i < a; i++) {
		matrix[i] = new int[b];
		for (int j = 0; j < b; j++) {
			file >> matrix[i][j];
		}
	}
	file.close();
}
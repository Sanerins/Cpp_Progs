#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip> 
#include <fstream>
using namespace std;
#undef max

char* DelSpacesCType(const char*, int);

string DelSpacesString(const string&);

int main(int*)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string input;
	char* inputC;
	int n;
	int ch;
	cout << "Задание 1: удаление ненужных пробелов \n\n";

	cout << "Введите 1, чтобы задать строки вручную, и 2, чтобы задать строки из файла \"strings.txt\"\n";
	cout << "В файле: 1 строка - размер, 2 строка - в стиле С, 3 - string \n";
	cin >> ch;
	if (ch == 1) {
		cout << "Введите строку типа string: ";
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, input);
		cout << "Введите количество элементов в строке типа C" << endl;
		cin >> n;
		while (n < 1 or std::cin.fail()) {
			std::cout << "Количество элементов введено некорректно ";
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cin >> n;
		}
		n++;
		inputC = new char[n];
		cout << "Введите строку типа C: ";
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.getline(inputC, n);
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	else {
		std::cout << "\nОткрываю файл...!\n";
		std::ifstream file;
		file.open("strings.txt");
		if (file.is_open()) {
			file >> n;
			file.close();
			file.open("strings.txt");
			getline(file, input);
			getline(file, input);
			n++;
			inputC = new char[n];
			for (int i = 0; i < (n-1); i++) {
				if (i == input.length()) break;
				inputC[i] = input[i];
				inputC[i+1] = '\0';
			}
			getline(file, input);
			file.close();
		}
		else {
			cout << "Файл не открылся :( ";
			exit(1);
		}
	}
	cout << "\nИзначальная string: " << "(" << input << ")";
	cout << "\nИзначальная строка типа С: " << "(" << inputC << ")\n\n";
	char* newInputC = DelSpacesCType(inputC, n);
	string newInput = DelSpacesString(input);
	cout << "\nString без ненужных пробелов: " << "(" << newInput << ")";
	cout << "\nСтрока типа С без ненужных пробелов: " << "(" << newInputC << ")\n";
	std::ofstream file;
	file.open("newStrings.txt", std::ios::out | std::ios::trunc);
	file << newInputC << "\n";
	file << newInput << "\n";
	file.close();
	cout << "Строки записаны в файл \"newStrings.txt\"";
	delete[] newInputC;
	delete[] inputC;
}

char* DelSpacesCType(const char* input, int length) {
	char* newStr = new char[length];
	char* newStrChar = newStr;
	while (*input == ' ') {
		++input;
	}
	while (*input) {
		if (*input == ' ') {
			if (!*(input+1)){

			}
			else if (*input == *(input + 1)) {

			}
			else {
				*newStrChar = *input;
				newStrChar++;
			}
		}
		else {
			*newStrChar = *input;
			newStrChar++;
		}
		++input;
	}
	*newStrChar = '\0';
	return (newStr);
}

string DelSpacesString(const string&input) {
	bool begining = true;
	string newStr("");
	for (unsigned int i = 0; i < input.length(); i++) {
		if (begining) {
			if (input[i] == ' ') {

			}
			else {
				newStr += input[i];
				begining = false;
			}
		}
		else if (input[i] == ' ') {
			if (input[i] == input[i + 1]) {

			}
			else if (i == (input.length()-1)) {

			}
			else {
				newStr += input[i];
			}
		}
		else {
			newStr += input[i];
		}
	}
	return newStr;
}
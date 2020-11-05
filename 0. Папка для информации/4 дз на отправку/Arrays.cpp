
#include <iostream>
#include <fstream>
#include <string>

int CinValid(int = 0);

void ShowArray(int*, int);

void ShowDoubleArray(int**, int);

int CountArrays();

void FileValidation();

void GetArrays(int**, int);

void RandomArray(int*, int);

void FileFiller(int count = 0);

int ExecuteTask(int*, int, bool=0);

int main(int*)
{
	setlocale(LC_ALL, "");
	std::cout << "Инициализирую заданный в коде массив из const...\n";
	const int N = 10; int n;
	int constArray[N] = {5, 6, 9, -10, -4, -8, -34, 0, 5, 8};
	std::cout << "Инициализирую динамический массив, пожалуйста, введите размер...\n";
	n = CinValid(1);
	int* dynamicArray = new int[n];
	RandomArray(dynamicArray, n);

	FileValidation();
	int amountOfArrays = CountArrays();
	int** textArray = new int*[amountOfArrays];
	GetArrays(textArray, amountOfArrays);
	std::cout << "\n\n---------\n";
	std::cout << "\nПолучены все необходимые данные. Приступаю к решению задания: \n";
	std::cout << "\nВ массиве целых чисел найти число отрицательных элементов, стоящих после максимального элемента(правее максимального) \n";
	std::cout << "\nВывожу массив из const...\n";
	ShowArray(constArray, N);
	std::cout << "\nДля массива из const...\n";
	std::cout << ExecuteTask(constArray, N) << "\n";
	std::cout << "\nВывожу динамический массив...\n";
	ShowArray(dynamicArray, n);
	std::cout << "\nДля динамического массива...\n";
	std::cout << ExecuteTask(dynamicArray, n) << "\n";
	std::cout << "\nВывожу массивы, считанные из файла...\n";
	ShowDoubleArray(textArray, amountOfArrays);
	std::cout << "\nДля массивов из файла...\n";
	for (int i = 0; i < amountOfArrays; i++) std::cout << ExecuteTask(textArray[i], textArray[i][0], 1) << "\n";

	delete[] textArray;
	delete[] dynamicArray;
}


int CinValid(int numberType) {
	int input;
	double inputDrob;
	std::cin >> inputDrob;
	input = inputDrob;
	if (numberType == 1) {
		while (input < 0 or std::cin.fail() or input != inputDrob) {
			std::cout << "\nВведено некорректное число\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cin >> inputDrob;
			input = inputDrob;
		}
	}
	else if (numberType == 2) {
		while (input < 1 or input > 2 or std::cin.fail() or input != inputDrob) {
			std::cout << "\nВведено некорректное число\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cin >> inputDrob;
			input = inputDrob;
		}
	}
	else {
		while (std::cin.fail() or input != inputDrob) {
			std::cout << "\nВведено некорректное число\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cin >> inputDrob;
			input = inputDrob;
		}
	}
	return(input);
}


void RandomArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = -50 + (rand() % 101);
	}
}

void ShowArray(int* array, int size) {
	std::cout << "\n";
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << "\n\n";
}



void FileValidation() {
	try {
		std::cout << "\nИшу файл в дериктории кода...!\n";
		std::ifstream file;
		file.open("textArray.txt");
		if (file.is_open()) {
			file.close();
			std::cout << "\nФайл успешно найден!\n";
		}
		else throw "\nНе удалось найти файл!\n";
	}
	catch (const char* fail) {
		std::cout << fail;
		std::cout << "\nСоздаю файл в директории кода...\n";
		std::ofstream file("textArray.txt");
		file.close();
		std::cout << "\nУспешно создан пустой файл!\n";
	}
}

int CountArrays() {
	int counter = 0;
	std::string line;
	try {
		std::ifstream file;
		file.open("textArray.txt");
		std::cout << "\nИщу данные внутри файла...\n";
		while(getline(file, line)) {
			counter += 1;
		}
		file.close();
		if (counter!=0) {
			int add;
			std::cout << "\nУспешно найдено массивов в файле:\n" << counter/2;
			std::cout << "\nЖелаете ввести данные дополнительно/заново?\n1.Да\n2.Нет\n\n";
			add = CinValid(2);;
			std::cout << "\n";
			if (add == 1) {
				FileFiller(counter / 2);
				return(CountArrays());
			}
			else return(counter / 2);
		}
		else throw "\nДанные в файле отсутствуют...\n";
	}
	catch(const char* fail){
		std::cout << fail;
		FileFiller();
		return(CountArrays());
	}
}

void FileFiller(int count) {
	int clear;
	int inputLength = 1, input = 0;
	int counter = count;
	std::cout << "\nИнициализирую протокол ввода информации в файл...\n";
	std::cout << "\nОчистить файл?\n1.Да\n2.Нет\n\n";
	clear = CinValid(2);;
	std::ofstream file;
	if (clear == 1) {
		file.open("textArray.txt", std::ios::out | std::ios::trunc);
		std::cout << "\nОчистка проведена успешно!\n";
		file.close();
		counter = 0;
	}
	file.open("textArray.txt", std::ios::out | std::ios::app);
	std::cout << "\nДля окончания ввода, введите длину массива, равную нулю\n";
	std::cout << "\nДля создания массива случайных чисел, введите отрицательную длину массива(длина массива будет модулем)\n";
	while (inputLength != 0) {
		counter += 1;
		std::cout << "\nВведите длину для массива " << counter << "\n\n";
		inputLength = CinValid();;
		if (inputLength > 0) {
			file << inputLength << "\n";
			for (int i = 0; i < inputLength; i++) {
				std::cout << "\n\nВведите элемент под номером " << i + 1 << "\n\n";
				input = CinValid();
				file << input << " ";
			}
			file << "\n";
		}
		if (inputLength < 0) {
			inputLength = -inputLength;
			file << inputLength << "\n";
			for (int i = 0; i < inputLength; i++) {
				input = -50 + (rand() % 101);
				file << input << " ";
			}
			std::cout << "\nМассив случайных символов сгенерирован успешно!\n\n";
			file << "\n";
		}
	}
	std::cout << "\nДанные успешно сохранены и занесены в файл!\n" << counter;
	file.close();
}




void GetArrays(int** array, int amount) {
	int size;
	std::string line;
	std::ifstream file;
	file.open("textArray.txt");
	for (int i = 0; i < amount; i++) {
		file >> size;
		int* newArray = new int[size+1];
		array[i] = newArray;
		array[i][0] = size;
		for (int j = 1; j <= size; j++) file >> array[i][j];
	}
}

void ShowDoubleArray(int** array, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 1; j <= array[i][0]; j++) {
			std::cout << array[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int ExecuteTask(int* array, int size, bool two) {
	int i = 0, max = INT_MIN, maxi = 0, counter = 0;
	if (two) {
		i += 1;
		size += 1;
	}
	for (i; i < size; i++) {
		if (array[i] > max) {
			maxi = i;
			max = array[i];
		}
	}
	for (i = maxi + 1; i < size; i++) if (array[i] < 0) counter++;
	return(counter);
}
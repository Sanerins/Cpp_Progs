#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip> 
#include <fstream>
using namespace std;
#undef max;
char numbers[] = "1234546789";

/*Вариант 5
Понятие вещественное определено следующим образом:
<вещественное> ::= <мантисса> <порядок> | <знак> <мантисса> <порядок>
<мантисса> ::= . <целое без знака> |<целое без знака> . <целое без знака>
<порядок> ::= E <знак> <целое без знака> | E <целое без знака>
<целое без знака> ::= <цифра> | <цифра> <целое без знака>
<цифра> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 |7 | 8 | 9
<знак> ::= + | -
*/

void CheckLines();

void CheckSign(string&);

void CheckMantissa(string&);

void CheckOrder(string&);

int main(int*)
{
	CheckLines();
	return(0);
}

void CheckLines() {
	string str;
	std::ifstream file;
	file.open("myStrings.txt");
	std::cout << "\nSearching for strings in myStrings.txt...\n";
	while (getline(file, str)) {
		try {
			cout << str << endl;
			CheckSign(str);
			CheckMantissa(str);
			CheckOrder(str);
			cout << "It's, indeed, a material number" << endl;
		}
		catch (char const* error) {
			cout << error << endl;
		}
	}
	file.close();
}

void CheckSign(string& str) {
	if (str.at(0) == '+' || str.at(0) == '-') {
		str.erase(0, 1);
	}
}

void CheckMantissa(string& str) {
	bool dot = 0;
	int N = str.length();
	for (unsigned int i = 0; i < N; i++) {
		if (strchr(numbers, str.at(0))) {
			str.erase(0, 1);
		}
		else if (!dot and str.at(0) == '.' and str.length()!=1) {
			if (strchr(numbers, str.at(1))) {
				dot = 1;
				str.erase(0, 1);
			}
			else throw "No digits after dot";
		}
		else if (dot and str.at(0) == 'E') {
			break;
		}
		else throw "Found inappropriate number in mantissa";
	}
	if (!dot) throw "There should be at least one dot in mantissa part";
}

void CheckOrder(string& str) {
	if (str.length() == 0 or str.length() == 1) throw "There is no order in this number";
	else if(str.at(0) != 'E') throw "There is no order in this number";
	else str.erase(0, 1);
	CheckSign(str);
	int N = str.length();
	for (unsigned int i = 0; i < N; i++) {
		if (strchr(numbers, str.at(0))) {
			str.erase(0, 1);
		}
		else throw "Found inappropriate number in order";
	}
}
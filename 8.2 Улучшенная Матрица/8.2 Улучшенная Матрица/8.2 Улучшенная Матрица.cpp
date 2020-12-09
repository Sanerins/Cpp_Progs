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

void CheckMaterial(string&);

void CheckMantissa(string&);

void CheckSign(string&);

void CheckWholeNumber(string&, bool end = 0);

void CheckDot(string&);

void CheckOrder(string&);

void CheckE(string&);

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
			CheckMaterial(str);
			cout << "It's, indeed, a material number" << endl;
		}
		catch (char const* error) {
			cout << error << endl;
		}
	}
	file.close();
}

void CheckMaterial(string& str) {
	CheckSign(str);
	CheckMantissa(str);
	CheckOrder(str);
}

void CheckMantissa(string& str) {
	CheckWholeNumber(str);
	CheckDot(str);
	CheckWholeNumber(str);
}

void CheckOrder(string& str) {
	CheckE(str);
	CheckSign(str);
	CheckWholeNumber(str, 1);
}

void CheckE(string& str) {
	if (str.length() < 2 or str.at(0) != 'E') throw "There is no order in this number or too many dots";
	else str.erase(0, 1);
}

void CheckSign(string& str) {
	if (str.at(0) == '+' || str.at(0) == '-') {
		str.erase(0, 1);
	}
}

void CheckWholeNumber(string& str, bool end) {
	if (str.length() == 1 and strchr(numbers, str.at(0))) {
		str.erase(0, 1);
	}
	else if (str.length() > 1 and strchr(numbers, str.at(0))) {
		str.erase(0, 1);
		CheckWholeNumber(str, end);
	}
	else if (str.length() > 1 and str.at(0) == '.' and !end) {

	}
	else if (str.length() > 1 and str.at(0) == 'E' and !end) {

	}
	else throw "Found inappropriate symbol in whole number sequence";
}

void CheckDot(string& str) {
	if (str.length() > 1 and strchr(numbers, str.at(1)) and str.at(0) == '.') {
		str.erase(0, 1);
	}
	else throw "Inappropriate dot initialization";
}
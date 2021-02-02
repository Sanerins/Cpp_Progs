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

void CheckWholeNumber(string&, bool dot = 0, bool needOrder = 1);

void CheckDot(string&);

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
			CheckWholeNumber(str);
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

void CheckWholeNumber(string& str, bool dot, bool needOrder) {
	//cout << str.at(0) << endl;
	if (strchr(numbers, str.at(0)) and str.length() == 1 and dot and !needOrder) {
		//cout << "Finish!!!" << endl;
		str.erase(0, 1);
	}
	else if (strchr(numbers, str.at(0)) and (!dot or !needOrder)) {
		//cout << "First part of mantissa" << endl;
		str.erase(0, 1);
		CheckWholeNumber(str, dot, needOrder);
	}
	else if (str.length() > 1 and strchr(numbers, str.at(0)) and (str.at(1) == 'E' or strchr(numbers, str.at(1)))) {
		//cout << "Second part of mantissa" << endl;
		str.erase(0, 1);
		CheckWholeNumber(str, dot, needOrder);
	}
	else if (!dot and str.at(0) == '.' and str.length() > 1) {
		//cout << "Called Dot" << endl;
		CheckDot(str);
	}
	else if ((dot and str.at(0) == 'E') and needOrder) {
		//cout << "Called Order" << endl;
		CheckOrder(str);
	}
	else throw "Found inappropriate symbol in number sequence";
}

void CheckDot(string& str) {
	if (strchr(numbers, str.at(1))) {
		str.erase(0, 1);
		CheckWholeNumber(str, 1);
	}
	else throw "No digits after dot";
}

void CheckOrder(string& str) {
	if (str.length() == 1 or str.length() == 0) throw "There is no order in this number";
	else if(str.at(0) != 'E') throw "There is no order in this number";
	else str.erase(0, 1);
	CheckSign(str);
	CheckWholeNumber(str, 1, 0);
}
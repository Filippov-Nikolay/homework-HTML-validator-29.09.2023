#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);

	ifstream in;

	string path;

	cout << "Введите путь: ";
	getline(cin, path);

	cout << path << endl;

	in.open(path, ios::in);


	int count = 0;
	int index = 0;
	char arrSymbol[256]{0};

	if (in) {
		do {
			char character;

			in.get(character);

			if (character == '<' || character == '>')
				arrSymbol[index++] = character;

			cout << character;
		} while (in);

		in.close();
	}

	cout << endl;

	// cout << index << endl;
	/*for (int i = 0; i < index; i++)
		cout << arrSymbol[i] << ' ';
	cout << endl;*/


	for (int i = 0; i < index; i++) {
		if (arrSymbol[i] != '<') {
			if (i == 0)
				count++;
			else if (arrSymbol[i - 1] == '>')
				count++;
		}

		if (arrSymbol[i] == '<')
			if (arrSymbol[++i] != '>')
				count++;
	}
	cout << endl;

	cout << "Кол-во ошибок: " << count << endl;

	return 0;
}

#include <iostream>
#include <time.h>
#include <string>
#include <thread>

using namespace std;

bool gameover = false;

void draw(const char map[3][3]) {
	;
	cout << "+---+---+---+                    Правила: первое значение означает ось X, второе ось Y" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "| ";
		for (int j = 0; j < 3; j++) {
			cout << map[i][j] << " | ";
		}
		cout << endl;
		cout << "+---+---+---+" << endl;
	}
}



int main() {
	setlocale(LC_ALL, "RU");

	char map[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			map[i][j] = ' ';
		}
	}

	while (!gameover) {
		system("cls");
		draw(map);
		int z, x;
		char c;
		cout << "Введите номер столбца: ";
		cin >> x;
		cout << "Введите номер строки: ";
		cin >> z;
		cout << "Введите X или O (буквами): ";
		cin >> c;
		if (z >= 0 && z < 3 && x >= 0 && x < 3 && map[z][x] == ' ') {
			map[z][x] = c;
		}
		else {
			cout << endl << "Error \n";
			system("pause");
		}
	}
	return 0;
}
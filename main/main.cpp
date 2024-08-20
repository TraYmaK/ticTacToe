#include <iostream>
#include <time.h>
#include <string>
#include <thread>

using namespace std;

bool gameover = false;

void draw(const char map[3][3]) {
	;
	cout << "Правила: первое значение означает ось X, второе ось Y" << endl << endl;
	cout << "+---+---+---+" << endl;
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
		if (z >= 0 && z < 3 && x >= 0 && x < 3 && map[z][x] == ' ' && (c == 'X' || c == 'x' || c == 'O' || c == 'o')) {
			map[z][x] = c;
		}
		else {
			cout << endl << "Error \n";
			system("pause");
		}
		if ((map[0][0] == 'x' && map[0][1] == 'x' && map[0][2] == 'x') ||
			(map[1][0] == 'x' && map[1][1] == 'x' && map[1][2] == 'x') ||
			(map[2][0] == 'x' && map[2][1] == 'x' && map[2][2] == 'x') ||
			(map[0][0] == 'x' && map[1][0] == 'x' && map[2][0] == 'x') ||
			(map[0][1] == 'x' && map[1][1] == 'x' && map[2][1] == 'x') ||
			(map[0][2] == 'x' && map[1][2] == 'x' && map[2][2] == 'x') ||
			(map[0][0] == 'x' && map[1][1] == 'x' && map[2][2] == 'x') ||
			(map[0][2] == 'x' && map[1][1] == 'x' && map[2][0] == 'x')) {
			system("cls");
			draw(map);
			cout << endl << "Игрок X победил!\n";
			system("pause");
			gameover = true;
		}
		if ((map[0][0] == 'o' && map[0][1] == 'o' && map[0][2] == 'o') ||
			(map[1][0] == 'o' && map[1][1] == 'o' && map[1][2] == 'o') ||
			(map[2][0] == 'o' && map[2][1] == 'o' && map[2][2] == 'o') ||
			(map[0][0] == 'o' && map[1][0] == 'o' && map[2][0] == 'o') ||
			(map[0][1] == 'o' && map[1][1] == 'o' && map[2][1] == 'o') ||
			(map[0][2] == 'o' && map[1][2] == 'o' && map[2][2] == 'o') ||
			(map[0][0] == 'o' && map[1][1] == 'o' && map[2][2] == 'o') ||
			(map[0][2] == 'o' && map[1][1] == 'o' && map[2][0] == 'o')) {
			system("cls");
			draw(map);
			cout << endl << "Игрок O победил!\n";
			system("pause");
			gameover = true;
		}
	}
	return 0;
}
﻿#include <iostream>
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



void winnerO(const char map[3][3]) {
	system("cls");
	draw(map);
	cout << endl << "Игрок O победил!\n";
	system("pause");
	gameover = true;
}



void winnerX(const char map[3][3]) {
	system("cls");
	draw(map);
	cout << endl << "Игрок X победил!\n";
	system("pause");
	gameover = true;
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
		for (int i = 0; i < 3; i++) {
			if ((map[i][0] == 'x' && map[i][1] == 'x' && map[i][2] == 'x') || (map[i][0] == 'X' && map[i][1] == 'X' && map[i][2] == 'X')) {
				winnerX(map);
			}
			else if ((map[0][i] == 'x' && map[1][i] == 'x' && map[2][i] == 'x') || (map[0][i] == 'X' && map[1][i] == 'X' && map[2][i] == 'X')) {
				winnerX(map);
			}
			else if ((map[i][0] == 'o' && map[i][1] == 'o' && map[i][2] == 'o') || (map[i][0] == 'O' && map[i][1] == 'O' && map[i][2] == 'O')) {
				winnerO(map);
			}
			else if ((map[0][i] == 'o' && map[1][i] == 'o' && map[2][i] == 'o') || (map[0][i] == 'O' && map[1][i] == 'O' && map[2][i] == 'O')) {
				winnerO(map);
			}
		}
		if ((map[0][0] == 'x' && map[1][1] == 'x' && map[2][2] == 'x') || (map[0][0] == 'X' && map[1][1] == 'X' && map[2][2] == 'X') ||
			(map[2][0] == 'x' && map[1][1] == 'x' && map[0][2] == 'x') || (map[2][0] == 'X' && map[1][1] == 'X' && map[0][2] == 'X')) {
			winnerX(map);
		}
		else if ((map[0][0] == 'o' && map[1][1] == 'o' && map[2][2] == 'o') || (map[0][0] == 'O' && map[1][1] == 'O' && map[2][2] == 'O') ||
			(map[2][0] == 'o' && map[1][1] == 'o' && map[0][2] == 'o') || (map[2][0] == 'O' && map[1][1] == 'O' && map[0][2] == 'O')) {
			winnerO(map);
		}
	}
	return 0;
}
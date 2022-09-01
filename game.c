#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

typedef struct board {
	int width;
	int height;
	int blocks[100][100];
}map;

void gotoxy(int x, int y);
void CursorView();
void drawBoard(int mapType);
map settingMap(int mapType);

int main() {
	drawBoard(1);

}

void gotoxy(int x, int y) { //커서 이동
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void drawBoard(int mapType) {
	char q;
	map m = settingMap(mapType);
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;

	int turn = 1;

	int act = 3;
	while (1) {
		
		while (1) {
			system("cls");
			gotoxy(0, 0);
			for (int i = 0; i < m.height; i++) {
				for (int j = 0; j < m.width; j++) {
					if (x1 == j && y1 == i) {
						printf("@ ");
					}
					else if (x2 == j && y2 == i) {
						printf("& ");
					}
					else if (m.blocks[i][j] == 0) {
						printf("* ");
					}
				}
				printf("\n");
			}


			q = _getch();
			if (q == -32) {
				q = _getch();
				switch (q) {
				case 75:
					if (turn == 1) {
						if (x1 != 0) {
							x1--;
						}
					}
					else {
						if (x2 != 0) {
							x2--;
						}
					}
					break;
				case 77:
					if (turn == 1) {
						if (x1 != m.width - 1) {
							x1++;
						}
					}
					else {
						if (x2 != m.width - 1) {
							x2++;
						}
					}
					break;
				case 72:
					if (turn == 1) {
						if (y1 != 0) {
							y1--;
						}
					}
					else {
						if (y2 != 0) {
							y2--;
						}
					}
					break;
				case 80:
					if (turn == 1) {
						if (y1 != m.height - 1) {
							y1++;
						}
					}
					else {
						if (y2 != m.height - 1) {
							y2++;
						}
					}
					break;
				}
			}
			
		}
	}
	
}

map settingMap(int mapType) {
	map m;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			m.blocks[i][j] = 0;
		}
	}
	if (mapType == 1) {
		m.height = 10;
		m.width = 20;
	}
	return m;
}
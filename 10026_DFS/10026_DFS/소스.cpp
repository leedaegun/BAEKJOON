#include<iostream>
using namespace std;


char map[101][101];
int check[101][101];
int moveX[4] = { 0,0,-1,1 };
int moveY[4] = { -1,1,0,0 };
int n;
void DFS(int,int);
bool isInside(int, int);
void init();
int main() {
	int count = 0;
	int count2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] != 1) {
				DFS(i, j);
				count++;
			}
		}
	}
	init();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] != 1) {
				DFS(i, j);
				count2++;
			}
		}
	}
	cout << count << endl;
	cout << count2 << endl;
	return 0;
}
void DFS(int x,int y) {
	check[x][y] = 1;
	for (int i= 0; i < 4; i++) {
		int dx = x + moveX[i];
		int dy = y + moveY[i];
		if (map[x][y]==map[dx][dy]&&isInside(dx,dy)&&check[dx][dy]!=1) {
			DFS(dx, dy);
		}
	}
}
bool isInside(int x, int y) {
	if (x >= 0 && x < n&&y >= 0 && y < n)return true;
	else false;
}
void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			check[i][j] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'R') {
				map[i][j] = 'G';
			}
		}
	}

}
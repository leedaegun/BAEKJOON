#include<iostream>
using namespace std;

//2018.12.19
//14502 ¿¬±¸¼Ò DFS
int map[9][9];
int copyMap[9][9];
int moveX[4] = { 0,0,1,-1 };
int moveY[4] = { -1,1,0,0 };

int n, m,ans;

void DFS(int, int, int);
bool isInside(int, int);
void paint(int, int);
void cal();
int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				DFS(i,j,1);
				map[i][j] = 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
void DFS(int x,int y,int count) {
	if (count == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				copyMap[i][j] = map[i][j];
			}
		}

		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (copyMap[i][j] == 2) {
					paint(i, j);
				}
			}
		}
		cal();
	}
	else {
		for (int i = x-1; i < n; i++) {
			for (int j = y-1; j < m; j++) {
				if (map[i][j] == 0) {
					map[i][j] = 1;
					DFS(i, j,count+1);
				}
			}
		}
	}
	map[x][y] = 0;
	--count;
}
void paint(int x,int y) {
	for (int i = 0; i < 4; i++) {
		int dx = x + moveX[i];
		int dy = y + moveY[i];
		if (copyMap[dx][dy] == 0&&isInside(dx,dy)) {
			copyMap[dx][dy] = 3;
			paint(dx, dy);
		}
	}
}
bool isInside(int x, int y) {
	if (x >= 0 && x < n&&y >= 0 && y < m)return true;
	else return false;
}
void cal() {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copyMap[i][j] == 0) {
				++count;
			}
		}
	}
	if (count > ans) {
		ans = count;
	}


}
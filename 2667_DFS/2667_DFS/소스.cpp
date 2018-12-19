#include<iostream>
#include<algorithm>
using namespace std;

//2018.12.19
//2667번 단지번호붙이기
//DFS
int N;
int check[26*26];
int map[26][26];
int c[26][26];
int moveX[4] = {-1,1,0,0};
int moveY[4] = { 0,0,-1,1 };

void DFS(int, int, int);
bool isRight(int, int);

int main() {
	int count=0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//cin >> map[i][j];
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]==1&&c[i][j]!=1) {
				count++;
				DFS(i, j, count+1);
				}
		}
	}
	sort(check, check + count);
	cout << count << endl;
	for (int i = 0; i < count; i++) {
		cout << check[i] << endl;
	}
	return 0;
}

void DFS(int x,int y,int count) {
	int a, b;
	check[count-2]++;
	c[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		a = x+moveX[i];
		b = y+moveY[i];
		if (c[a][b]!=1&&isRight(a,b)&&map[a][b]==1) {
			DFS(a, b,count);
		}
		
	}
}

bool isRight(int x,int y) {
	if (x >= 0 && x < N && y >= 0 && y < N)return true;
	else return false;
}
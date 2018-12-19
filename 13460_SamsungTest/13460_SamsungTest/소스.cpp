#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//2018.08.17
//samsung 첫문제 구슬 탈출
// 못풀겟다... 코드 이해도 못하겠..

#define INF 0x7fffffff
char arr[11][11];
int bx, by;
int rx, ry;
int n, m;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int move(int);
bool  priority_inspect(int);
int dfs(int);
int main() {

	

	cin >> n >> m;
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B') {
				bx = i;
				by = j;
			}
			else if (arr[i][j] == 'R') {
				rx = i;
				ry = j;
			}
		}
	}
	int ret = dfs(0);

	return 0;
}
int dfs(int depth) {
	if (depth == 10)return INF;
	int brx = rx;
	int bry = ry;
	int bbx = bx;
	int bby = by;
	int ret = INF;

	for (int i = 0; i < 4; i++) {
		int tmp = move(i);
		if (tmp == 1)return depth + 1;
		else if (tmp == 2) {
			int tmp2 = dfs(depth + 1);
			if (ret > tmp2)ret = tmp2;
		}
		rx = brx;
		ry = bry;
		bx = bbx;
		by = bby;
	}
	return ret;
}

int move(int d) {
	bool red_zero = 0, blue_zero = 0;
	bool red_stop = 0, blue_stop = 0;
	bool red_prio = priority_inspect(d);
	int nrx;
	int nry;
	int nbx;
	int nby;

	//둘다 못움직일 때 까지 와일
	while (!blue_stop || !red_stop) {

		if (!red_stop) {
			nrx = rx + dx[d];
			nry = ry + dy[d];

			if (nrx < 0 || nry < 0 || nrx >= m || nry >= n || map[nrx][nry] == '#') red_stop = 1;
			else if (map[nrx][nry] == 'O') {
				red_stop = 1;
				red_zero = 1;
			}
			else {
				rx = nrx;
				ry = nry;
			}
		}

		if (!blue_stop) {
			nbx = bx + dx[d];
			nby = by + dy[d];

			if (nbx < 0 || nby < 0 || nbx >= m || nby >= n || map[nbx][nby] == '#') blue_stop = 1;
			else if (map[nbx][nby] == 'O') {
				blue_stop = 1;
				blue_zero = 1;
			}
			else {
				bx = nbx;
				by = nby;
			}
		}
	}

	//공의 위치가 같을 때
	if (rx == bx && ry == by) {
		if (d == 0) {
			if (red_prio) bx++;
			else rx++;
		}
		else if (d == 1) {
			if (red_prio) bx--;
			else rx--;
		}
		else if (d == 2) {
			if (red_prio) by++;
			else ry++;
		}
		else {
			if (red_prio) by--;
			else ry--;
		}
	}

	if (blue_zero) return 0; // 블루 제로 들어감
	else if (red_zero) return 1; // 레드 제로 들어감
	else return 2; // 제로 발견 못함
}

bool priority_inspect(int d) {//레드가 높으면 1 아니면 0
	switch (d) {
	case 0:
		if (rx < bx) return 1;
		else return 0;
		break;
	case 1:
		if (rx > bx) return 1;
		else return 0;
		break;
	case 2:
		if (ry < by) return 1;
		else return 0;
		break;
	case 3:
		if (ry > by) return 1;
		else return 0;
		break;
	}
}
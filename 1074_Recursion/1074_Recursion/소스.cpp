#include<iostream>
#include<math.h>
using namespace std;

int N, r, c,cnt;
void recursion(int, int, int);

//2018.08.16
//재귀 Z 1074
//어렵지만 답을 보고 이해는 감
//분할을 잘해야함
int main() {
	

	cin >> N >> r >> c;

	recursion(0,0, pow(2, N));
	return 0;
}

void recursion(int x,int y, int j) {

	if (x == r&&y == c) {
		cout << cnt << endl;
		return;
	}

	if (r < x + j && r >= x && c < y + j && c >= y) {
		recursion(x, y, j / 2);
		recursion(x, y + j / 2, j / 2);
		recursion(x + j / 2, y, j / 2);
		recursion(x + j / 2, y + j / 2, j / 2);
	}

	else cnt += j*j;

}
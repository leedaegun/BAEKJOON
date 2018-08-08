#include<iostream>
using namespace std;

//2018.08.08
//6603 DFS 로또
//전체경우의 수를 뽑고 idx가 6일때 바로 출력하기
int a[13];
int b[13];
int k;
void dfs(int, int);
int main() {

	while (scanf("%d", &k) > 0) {//입력 값 0일때 종료
		a[13] = {};
		for (int i = 0; i < k; i++)
			scanf("%d", &a[i]);
		dfs(0, 0);//0,0에서 시작
		cout << endl;
	}
	return 0;
}

void dfs(int start,int idx) {
	if (idx == 6) {//깊이 6일때 탈출
		for (int i = 0; i < 6; i++)cout << b[i]<<" ";
		cout << endl;
		return;
	}
	for (int i = start; i < k; i++) {
		b[idx] = a[i];
		dfs(i + 1, idx + 1);
	}
}
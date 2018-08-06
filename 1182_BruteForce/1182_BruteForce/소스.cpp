#include<iostream>
using namespace std;

//2018.08.06
//부르트포스 1182 부분집합의 합
//dfs bfs 깊이우선탐색 너비우선탐색
int n, s;
int cnt;
int sum;
int a[21];
void dfs(int, int);
int main() {
	
	cin >> n>>s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		
	}
	dfs(1, 0);// 인덱스 1일때는 수동적으로 두번 넣어줌
	dfs(1, a[0]);

	if (s == 0)cnt--;
	cout << cnt << endl;
	
	return 0;
}

void dfs(int idx, int sum) {

	if (idx >= n) {
		if (sum == s) cnt++;//끝까지가서 경우를 세야함 안그럼 중복 카운트됨
		return;
	}
	dfs(idx + 1, sum);
	dfs(idx + 1, sum + a[idx]);
}
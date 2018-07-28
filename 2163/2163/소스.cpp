#include<iostream>
using namespace std;

//208.07.28
//dp 2163 초콜릿 자르기
int dp[301][301];
int main() {
	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			dp[i][j] = i*j - 1;

	cout << dp[N][M] << endl;
	return 0;
}
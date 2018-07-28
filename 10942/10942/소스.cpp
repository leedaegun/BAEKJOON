#include<iostream>
using namespace std;


int dp[2000];
int m[2000][2000];

//2018.07.26
//dp 펠린드롬
//printf,scanf 때문에 시간초과 cin,cout쓰지말자
int main() {


	int M, N;
	int n, s;
	cin >> N;//홍준이가 적을 자연수 개수
	for (int i = 1; i <= N; i++) {
		scanf("%d", &dp[i]);//자연수 개수 입력
	}
	for (int i = 1; i <= N; i++) {
		m[i][i] = 1;
		if (i + 1 <= N) {
			if (dp[i] == dp[i + 1]) m[i][i + 1] = 1;
		}
	}

	for (int k = 3; k <= N; k++)
	{
		for (int i = 1; i <= N - k + 1; i++)
		{
			int j = i + k - 1;
			if (dp[i] == dp[j] && m[i + 1][j - 1])
				m[i][j] = 1;
		}
	}

	cin >> M;//명우가 질문할 개수
	for (int i = 0; i <M; i++) {
		scanf("%d %d", &n, &s);//위치 입력
							   //cout << m[n][s] << endl;
		printf("%d \n", m[n][s]);
	}

	return 0;
}


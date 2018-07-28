#include<iostream>
#include<algorithm>
using namespace std;

int dp[1000000];

//2018.07.25
//dp 1로 만들기
int main() {

	int N;


	cin >> N;

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;  //규칙 3번 : 1을 뺀다
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);   //규칙 2번 : 2로 떨어지는 경우
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);   //규칙 1번 : 3로 떨어지는 경우
		}

	}
	cout << dp[N] << endl;
	return 0;
}
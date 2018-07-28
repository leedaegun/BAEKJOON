#include<iostream>
using namespace std;

int dp[30][30];

//2018.07.22
//dp 1010 다리놓기

int main() {
	int N, M, T;


	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			dp[0][i] = i + 1;

		}

		if (N == M) {
			cout << 1 << endl;
			continue;
		}

		else if (N > M) {
			cout << "error" << endl;
			break;
		}


		else {
			for (int i = 1; i < N; i++) {

				for (int j = i; j < M; j++) {

					dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];


				}
			}
		}
		cout << dp[N - 1][M - 1] << endl;

	}
	return 0;
}
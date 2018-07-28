#include<iostream>
using namespace std;


//2018.07.20
//dp
int max(int a, int b)
{
	return a > b ? a : b;
}

int m[2][100000];
int dp[2][100000];

int main() {
	int T, n;


	cin >> T;

	for (int k = 1; k <= T; k++) {

		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 2; j <= n + 1; j++)
				cin >> m[i][j];

		for (int i = 2; i <= n + 1; i++) {
			dp[0][i] = max(max(dp[0][i - 1], dp[1][i - 1] + m[0][i]), dp[1][i - 2] + m[0][i]);
			dp[1][i] = max(max(dp[1][i - 1], dp[0][i - 1] + m[1][i]), dp[0][i - 2] + m[1][i]);
		}


		if (dp[0][n + 1] > dp[1][n + 1])
			cout << dp[0][n + 1] << endl;
		else
			cout << dp[1][n + 1] << endl;


	}


	return 0;
}
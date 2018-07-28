#include<iostream>
using namespace std;

//2018.07.2\
// dp 1965 상자넣기
//lis 최종증가수열도 같이 이해해야 풀수있는문제
int a[1000];
int dp[1000];

int main() {
	int max, n;
	max = 0;
	//scanf("%d", &n);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		//scanf("%d", &a[i]);
		cin >> a[i];

	}
	/*
	for (int i = 1; i <= n; i++) {

	for (int j = dp[i - 1]; j <= i - 1; j++) {
	//cout << " dp[i-1] : " << dp[i - 1] << " n-1 : " << n - 1 << endl;
	if (a[j] < a[i]) {
	//cout << "a[j] : "<< a[j] << "a[n]"<< endl;
	dp[i] = dp[i - 1] + 1;
	break;
	}
	else dp[i] = dp[i - 1];
	}

	cout << "dp [ " << i << " ] : " << dp[i] << endl;
	}*/
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && dp[i] < dp[j] + 1) {

				dp[i] = dp[j] + 1;

			}
		}
		if (max < dp[i])max = dp[i];
	}



	printf("%d \n", max);

	return 0;
}
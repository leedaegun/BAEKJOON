#include<iostream>
using namespace std;
int dp[1001];


//2018.07.31
//dp 조짜기
//답을 봐도 잘 모르겠음
int main() {
	int N;
	int a[1001];

	cin >> N;
	for (int i = 1; i <= N; i++) {

		cin >> a[i];
		int maxi = 0, mini = 10000;
		for (int j = i; j; j--) {
			if (a[j] > maxi) maxi = a[j];
			if (a[j] < mini) mini = a[j];
			if (dp[i] < dp[j - 1] + maxi - mini) dp[i] = dp[j - 1] + maxi - mini;
		}
	}
	cout << dp[N] << endl;
	return 0;
}
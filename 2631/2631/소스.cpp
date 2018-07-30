#include<iostream>
using namespace std;
//2018.07.30
//dp 2631 줄세우기
//LIS를 찾으면 금방 푸는 문제지만
//이 아이디어를 떠올리지 못함

int main() {
	int N,max;
	int a[200];
	int dp[200] = {};

	cin >> N;

	for (int i = 1; i <=  N; i++) {
		cin >> a[i];
	}
	max = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && dp[i] < dp[j] + 1) {
				dp[i]++;
			}
		}
		if (max < dp[i]) max = dp[i];
	}

	cout << N - max << endl;
	return 0;
}
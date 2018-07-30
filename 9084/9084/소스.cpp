#include<iostream>
using namespace std;

//2018.07.30
//dp 9084 동전

//변수좀 똑바로보자

int main() {

	int T,N,M;
	int money[20];

	cin >> T;
	for (int i = 1; i <= T; i++) {

		cin >> N;
		for (int j = 1; j <= N; j++) { 
			cin >> money[j]; 
		}
		cin >> M;

		int dp[10000] = {0};//버퍼 초기화 필수!!
		dp[0] = 1;

		for (int k = 1; k <= N; k++) {
			for (int g = money[k]; g <= M; g++) {
				dp[g] += dp[g - money[k]];
			}
		}
		//cout << endl;
		cout<< dp[M] << endl;
	}

	return 0;
}
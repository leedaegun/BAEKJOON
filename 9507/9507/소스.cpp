#include<iostream>
using namespace std;

//2018.07.26
//dp 9507¹ø Generations of Tribbles

long long dp[68];
long long koong(int);

int main() {
	int n;
	int t;

	cin >> t;
	for (int i = 0; i<t; i++) {
		cin >> n;
		cout << koong(n) << endl;
	}


	return 0;
}


long long koong(int n) {

	if (dp[n] != 0)return dp[n];
	else {
		if (n < 2) return dp[n] = 1;
		else if (n == 2)return dp[n] = 2;
		else if (n == 3)return dp[n] = 4;
		else {
			for (int i = 4; i <= n; i++) {
				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
			}
			return dp[n];
		}
	}


}
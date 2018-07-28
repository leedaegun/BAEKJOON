#include<iostream>

using namespace std;

//2018.07.28
//dp 1912 ¿¬¼ÓÇÕ

int number[100000];
int Dp[100000];

int main() {
	int N, maxSum, finalSum;
	//finalSum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> number[i];
	}
	/*
	for (int i = 1; i <= n; i++) {
	maxSum = a[i];
	cout << "init maxSum : " << maxSum << endl;
	for(int j=i;j<=n;j++){
	maxSum = max(maxSum, maxSum + a[j + 1]);
	cout << "a[ j + 1 ] :" << a[j + 1] << endl;
	cout << "in loop maxSum : " << maxSum << endl;
	}
	dp[i] = maxSum;
	cout << "dp [ " << i << " ] : " << dp[i] << endl;
	finalSum = max(dp[i],finalSum);
	cout << "finalSum : " << finalSum << endl;
	}
	cout << finalSum << endl;
	*/
	for (int i = 1; i <= N; i++)
	{

		if (Dp[i - 1] + number[i] > number[i]) {
			Dp[i] = Dp[i - 1] + number[i];
		}
		else
		{
			Dp[i] = number[i];
		}

	}
	maxSum = Dp[1];
	for (int i = 2; i <= N; i++)
		if (maxSum < Dp[i])
			maxSum = Dp[i];

	cout << maxSum << endl;

	return 0;
}
#include<iostream>
#include<math.h>
using namespace std;

//int min(int, int);
int Dp[100000] = { 0 };

//2018.07.23
//dp 1699 제곱수의 합

int main() {
	int N;
	cin >> N;
	/*
	for (int i = 1; i <= (int)pow(N,0.5); i++) {
	dp[i*i] = 1;
	}
	//cout << (int)pow(N, 0.5) << endl;

	for (int i = 1; i <= N; i++) {
	for (int j = int(i / 2); j >= 0 ; j--) {
	if(dp[i]==0){ dp[i] = 100000; }
	//cout << "i : "<< i<<"j : " << j << endl;
	//cout << "before dp[" << i << "] : " << dp[i] << endl;;
	//cout << "계산식 : " << dp[i - j] + dp[j] << endl;
	//dp[i] = min(dp[i] ,dp[i - j] + dp[j]);
	if (dp[i] > dp[i - j] + dp[j]){dp[i] = dp[i - j] + dp[j]; }
	//cout << "min : " << min(dp[i], dp[i - j] + dp[j]) << endl;
	//cout << "dp[" << i << "] : " << dp[i]<<endl;
	}
	//cout << endl;
	}*/
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j*j <= i; j++) {
			if (Dp[i] > Dp[i - j*j] + 1 || Dp[i] == 0)
				Dp[i] = Dp[i - j*j] + 1;
		}
	}

	cout << Dp[N] << endl;


	return 0;
}
/*
int min(int x, int y) {
if (x <= y)return x;
else return y;
}*/
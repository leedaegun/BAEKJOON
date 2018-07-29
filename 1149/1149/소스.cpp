#include<iostream>
#include<algorithm>


//2018.07.29
//dp 1149 RGB°Å¸®
/*
int dp[1000];
int red[1000];
int green[1000];
int blue[1000];
int a[1000];

int main() {
	
	int N;

	std::cin >> N;
	
	for (int i = 1; i <= N; i++) {
		//scanf("%d %d %d", &red[i], &green[i], &blue[i]);
		std::cin >> red[i] >> green[i] >> blue[i];
		//std::cout<< red[i] << green[i] << blue[i];
	}
	int min = std::min(red[1],blue[1]);
	a[1] = std::min(min, green[1]);

	a[1] = min;
	dp[1] = a[1];
	//std::cout << "a[ 1 ] : " << a[1] << std::endl;
	
	for (int i = 2; i <= N; i++) {
		
	
		if (a[i-1] == red[i-1]) {
			//std::cout << "red" << std::endl;
			if(green[i]>blue[i]){
				dp[i] = dp[i - 1]+blue[i];
				//std::cout << dp[i] << std::endl;
			}
			else {
				dp[i] = dp[i - 1] + green[i];
				//std::cout << dp[i] << std::endl;
			}
			
		}
		else if (a[i-1] == green[i-1]) {
			//std::cout << "green" << std::endl;
			if (red[i]>blue[i]) {
				dp[i] = dp[i - 1] + blue[i];
			}
			else {
				dp[i] = dp[i - 1] + red[i];
			}
		}
		else if (a[i-1] == blue[i-1]) {
			if (green[i]>red[i]) {
				//std::cout << "blue" << std::endl;
				dp[i] = dp[i - 1] + red[i];
			}
			else {
				dp[i] = dp[i - 1] + green[i];
			}
		}
		a[i] = dp[i] - dp[i - 1];
		//std::cout << "a[ " << i << " ] : " << a[i] << std::endl;
	}
	
	std::cout << dp[N] << std::endl;
	return 0;
}*/
using namespace std;

int D[1001][4], A[1001][4], N;

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++)

		for (int j = 1; j <= 3; j++)

			cin >> A[i][j];//color cost

	//init
	D[1][1] = A[1][1];

	D[1][2] = A[1][2];

	D[1][3] = A[1][3];

	for (int i = 2; i <= N; i++)

		for (int j = 1; j <= 3; j++)

		{

			//calculate cost

			D[i][1] = min(D[i - 1][2], D[i - 1][3]) + A[i][1];

			D[i][2] = min(D[i - 1][1], D[i - 1][3]) + A[i][2];

			D[i][3] = min(D[i - 1][1], D[i - 1][2]) + A[i][3];

		}
	//min
	cout << min(D[N][1], min(D[N][2], D[N][3]));


}

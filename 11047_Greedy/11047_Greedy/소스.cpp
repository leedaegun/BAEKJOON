#include<iostream>
using namespace std;


//2018.08.04
//11047 greedy 동전 0
//생각보다 답은 단순하다.
//복잡하게 생각하지 말자
long a[11];
int cnt;
//void cal(int, int);
int main() {
	int n, k;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		//cin >> a[i];
		scanf("%d", &a[i]);
		//cout << a[i];
	}
	cnt = 0;
	//cal(n, k);
	for (int i = n; i > 0; i--) {
		cnt += k / a[i];
		k %= a[i];
	}
	cout << cnt << endl;
	return 0;
}
/*
void cal(int n,int k) {

	for (int i = 0; i < n; i++) {
		if (k <= a[i]) {
			//cout << "a[i-1] : " << a[i-1] << " ";
			for (int j = 1; j <= i; j++) {
				while (k >= a[i - j]) {
					//cout << "a[i-j] : " << a[i - j] << " ";
					k = k - a[i - j];
					//cout << "k : " << k << endl;
					cnt++;
				}
			}
			
			//cout << "cnt : " << cnt << endl;
			
			//if (k == 0)return;
			//n = i - 1;
			//break;
		}
	}

}*/
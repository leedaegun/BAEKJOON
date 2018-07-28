#include<iostream>
using namespace std;

//2018.07.19 DP

int main() {
	int T;
	int n;
	int m[11] = {};
	m[0] = 0;
	m[1] = 1;
	m[2] = 2;
	m[3] = 4;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;

		for (int k = 4; k <= n; k++) {

			m[k] = m[k - 1] + m[k - 2] + m[k - 3];
		}

		cout << m[n] << endl;


	}


	return 0;
}

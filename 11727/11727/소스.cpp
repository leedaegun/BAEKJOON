#include<iostream>
using namespace std;
//2018.07.20
//dp
int main() {

	int n;
	int m[1000] = { 0 };

	m[0] = 1;
	m[1] = 1;


	cin >> n;

	for (int i = 2; i <= n; i++) {
		m[i] = (m[i - 1] + m[i - 2] * 2) % 10007;
	}

	cout << m[n] << endl;

	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

//2018.08.04
//greedy 11399 ATM
//처음으로 한방에 맞춤
int p[1000];
int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> p[i];
	}
	sort(p, p + t);
	int sum = 0;
	for (int i = 0; i < t; i++) {
		sum += p[i]*(t-i);
	}

	cout << sum << endl;

	return 0;
}
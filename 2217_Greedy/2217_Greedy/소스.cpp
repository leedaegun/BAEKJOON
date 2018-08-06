#include<iostream>
#include<algorithm>
using namespace std;


//2018.08.06
//greedy 2217 로프
//한방통과!!
int n[100001];
int main() {
	int testcase;
	int max = 0;
	//int min = 100001;
	cin >> testcase;
	for (int i = 1; i <= testcase; i++) {
		cin >> n[i];
		//scanf("%d", &n[i]);
	}
	sort(n, n + testcase+1);
	for (int i = testcase; i > 0; i--) {
		if (max < n[i]*(testcase-i+1))max = n[i]* (testcase - i+1);
	}
	cout << max << endl;
	return 0;
}
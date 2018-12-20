#include<iostream>
using namespace std;
//2018.12.20
//전화상담
int mem[10001][2];
int time[10001];
int main() {
	int testcase,n,k,l;
	int anw=0;
	cin >> testcase;
	while (testcase > 0) {
		cin >> n >> k >> l;
		for (int i = 0; i < n; i++) {
			cin >> mem[i][0]>>mem[i][1];//원하는 상단시간 불만/min
		}

		testcase--;
	}
	return 0;
}
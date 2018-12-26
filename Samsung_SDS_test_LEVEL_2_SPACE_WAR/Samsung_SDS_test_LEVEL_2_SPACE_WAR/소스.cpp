#include<iostream>
#include<algorithm>
#define llong_max 4000000000
using namespace std;

long n, m, b;
long long arrayData[1000001][2];
long long copyData[1000001][2];

void copy();
void reset();
int main() {
	int count = 1;
	int testcase;
	cin >> testcase;
	while (testcase > 0) {
		cin >> n >> m >> b;
		for (int i = 0; i < m; i++) {
			cin >> arrayData[i][0] >> arrayData[i][1];
		}
		long long ans = 0;
		long long min = llong_max;
		int countN = 0;
		copy();
		for (int i = 0; i < m; i++) {
			if (arrayData[i][1] < 1)continue;
			if (arrayData[i][0] >= b) {
				ans += arrayData[i][0];
				arrayData[i][1]--;
				countN++;
				if (countN == n) {
					countN = 0;
					//cout << "i:" << i << endl;
					//cout << "중간 ans" << ans << endl;
					if (min > ans)min = ans;
					ans = 0; reset();
				}
				
			}
			else {
				for (int j = i; j < m; j++) {
					if (i == j&&arrayData[i][1] < 2)continue;
					if (arrayData[i][0] + arrayData[j][0] >= b&& arrayData[j][1] >= 1 && arrayData[i][1] >= 1) {
						
						arrayData[i][1]--;
						arrayData[j][1]--;
						
						ans += arrayData[i][0] + arrayData[j][0];
						countN++;
						if (countN == n) {
							countN = 0;
							//cout << "i : " << i << "j : " << j << endl;
							//cout << "중간 ans" << ans << endl;
							if (min > ans)min = ans;
							ans = 0; reset();
						}
						
					}
				}
			}
		}
		
		if (min == llong_max)min = -1;
		cout << "#" << count++ <<" "<< min << endl;
		testcase--;
	}
	return 0;
}
void copy() {

	for (int i = 0; i < n; i++) {
		copyData[i][1] = arrayData[i][1];
		copyData[i][0] = arrayData[i][0];
	}
}
void reset() {
	for (int i = 0; i < n; i++) {
		arrayData[i][1] = copyData[i][1];
		arrayData[i][0] = copyData[i][0];
	}
}
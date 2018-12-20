#include<iostream>
#include<algorithm>
using namespace std;

int n,t;
int num[1000001];
int main() {
	cin >> t;
	int count = 1;
	int ans,copyN;
	while (t > 0) {
		cin >> n;
		copyN = n;
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		sort(num, num + n);
		while (n > 1) {
			if (n % 2 == 1) {//È¦¼ö
				for (int i = 0; i < n; i = i + 2) {
					if (i != n - 1) {
						num[i / 2] = num[i] + num[i + 1];
						ans += num[i / 2];
					}
					else
						num[n / 2 ] = num[n - 1];
					for (int j = 0; j < n; j++) {
						cout << num[j] << " ";
					}
					cout << endl;
				}
				n = n / 2 + 1;
			}
			else {
				for (int i = 0; i < n; i = i + 2) {
					num[i / 2] = num[i] + num[i + 1];
					ans += num[i / 2];
					for (int j= 0; j < n; j++) {
						cout << num[j] << " ";
					}
					cout << endl;
				}
				n = n / 2 ;
			}
			
			sort(num, num + n);
		}
		for (int i = 0; i < copyN; i++) {
			num[i] = 0;
		}
		cout << "#" << count++  << " " << ans << endl;
		t--;
		
	}
	return 0;
}
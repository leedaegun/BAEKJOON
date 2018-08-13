#include<iostream>
#include<algorithm>
using namespace std;
long long a[500000], b[500000];

//2018.08.13
//숫자카드 10815 이분탐색
//loop 조건땜시 시간걸림
int main() {
	int n, m;
	int left, mid, right;
	bool ok;

	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++)cin >> b[i];

	sort(a, a + n);
	//for (int i = 0; i < n; i++)cout << a[i];
	
	for (int i = 0; i < m; i++) {
		left = 0;
		right = n-1;
		mid = (left + right) / 2;
		//cout << "mid : " << mid << endl;;
		ok = false;
		while(left<=right){
			//cout << "while" << endl;
			// 
			//cout << "b[" << i << "] : " << b[i]<<endl;
			//cout << "a[" << mid << "] : " << a[mid] << endl;
			if (b[i] > a[mid]) {
				left = mid + 1;
				//cout << "left : " << left << endl;
				mid = (left + right) / 2;
			}
			else if(b[i] < a[mid]){
				right = mid - 1;
				//cout << "right : " << right << endl;
				mid = (left + right) / 2;
			}
			else { 
				ok = true;
				//cout << "1" << " ";
				break;
			}
			//cout << "mid : " << mid << endl;
		}
		
		if(ok)cout << "1" << " ";
		else cout << "0" << " ";
		
	}
	cout << endl;
	

	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

int k[10];

//2018.08.05
//부르트포스 일곱 난쟁이 2309
//중간에 확인하려고 하는 출력문
//제출할때 제거 잘하자

int main() {
	int fake1, fake2;
	int sum = 0;
	for (int i = 1; i <= 9; i++) {
		cin >> k[i];
		sum += k[i];
	}
	
	for (int i = 1; i <= 9; i++) {
		
		//cout << "sum1 : " << sum << endl;
		for (int j = i+1; j <= 9; j++) {
			if (sum - k[j]-k[i] == 100) {
				//cout << "sum2 : " << sum << endl;
				fake1 = k[i];
				fake2 = k[j];
				break;
			}
		}
	}
	
	
	//cout << fake1 << " "<< fake2 << endl;
	sort(k, k+10);
	for (int i = 1; i <= 9; i++) {
		if ((k[i] != fake1) && (k[i] != fake2)) {
			cout << k[i] << endl;
		}
	}
	return 0;
}
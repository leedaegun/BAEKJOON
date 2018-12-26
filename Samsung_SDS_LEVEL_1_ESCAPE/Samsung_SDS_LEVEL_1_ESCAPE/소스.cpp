#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int car[51];
int carColorNum[51];

long long fac(int n) {
	int res, i;

	if (n == 1)
		return n;
	else {
		res = n;
		for (i = n - 1; i > 0; i--)
			res *= i;
		return res;
	}
}
int main() {
	int carNum, carColor;
	int testcase;
	int count = 1;
	cin >> testcase;

	while (testcase > 0) {
		int badCarNum = 0;
		bool pass=true;
		string s,t;
		cin >> carColor >> carNum;

		for (int i = 1; i <= carNum; i++) {
			cin >> carColorNum[i];
			if (carColorNum[i] != 0) {
				for (int j = 0; j < carColorNum[i]; j++) {
					
					t += to_string(i);;
					badCarNum++;
				}
			}
		}
		
		int tmp_car;
		for (int i = 1; i <= carColor; i++) {
			
			cin >> tmp_car;
			s += to_string(tmp_car);
			car[tmp_car]++;
		}
		for (int i = 1; i <= badCarNum; i++) {
			//cout << car[i] <<" "<< carColorNum[i] << endl;
			if (car[i] < carColorNum[i]) {
				//cout << car[i] << carColorNum[i] << endl;
				pass = false;
				break;
			}
		}
		if (pass) {
			//long long cnt = fac(badCarNum);
			long long cnt = 100000;
			while (cnt--) {

				random_shuffle(t.begin(), t.end());

				if (s.find(t) >= 0 && s.find(t)<s.size())break;
			}
			if (s.find(t)>s.size())cout << "#" << count++ << " " << "0" << endl;
			else cout << "#" << count++ << " " << s.find(t) + 1 << endl;

		}
		else {
			cout << "#" << count++ << " " << "0" << endl;
		}
		testcase--;
		s.clear();
		t.clear();
		for (int i = 0; i <=51; i++) {
			 car[i] = carColorNum[i] =0;
			
		}
	}
	return 0;
}
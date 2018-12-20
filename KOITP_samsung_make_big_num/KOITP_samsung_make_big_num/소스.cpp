#include<iostream>
#include<algorithm>
using namespace std;

//2018.12.20
//KOITP 삼성 큰수 만들기
int array_num[100001];
int main() {
	int testcase,num,plus,minus,anw;
	int count = 1;
	cin >> testcase;
	while (testcase > 0) {
		
		cin >> num >> plus >> minus;
		for (int i = 0; i < num; i++) {
			cin >> array_num[i];
		}
		sort(array_num + 1, array_num + num);
		anw = array_num[0];
		//cout << "init ans : " << anw << endl;
		for (int i = 1; i < num; i++) {
			if (i <= minus)anw -= array_num[i];
			else anw += array_num[i];
			//cout << "ans : " << anw << endl;
		}
		cout << "#" << count++ << " " << anw << endl;
		testcase--;
	}
	return 0;
}
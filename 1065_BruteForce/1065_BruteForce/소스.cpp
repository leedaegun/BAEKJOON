#include<iostream>
using namespace std;


//2018.08.05
//���Ʈ ���� 1065 �Ѽ�
//�� ���� ����
int main() {
	int n;
	int a, b, c;
	int cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a = i / 100;
		b = (i % 100) / 10;
		c = i % 10;
		
		if (a == 0) cnt++;
		else{
			//cout << a << " ";
			//cout << b << " ";
			//cout << c << endl;
			if ((a - b) == (b - c)) {
				//cout << i << " " << a << " " << b << " " << c << endl;
				cnt++;
			}
		}
		
	}
	cout << cnt << endl;
	
	return 0;
}
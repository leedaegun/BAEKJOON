#include<iostream>
using namespace std;
//2018.12.20
//��ȭ���
int mem[10001][2];
int time[10001];
int main() {
	int testcase,n,k,l;
	int anw=0;
	cin >> testcase;
	while (testcase > 0) {
		cin >> n >> k >> l;
		for (int i = 0; i < n; i++) {
			cin >> mem[i][0]>>mem[i][1];//���ϴ� ��ܽð� �Ҹ�/min
		}

		testcase--;
	}
	return 0;
}
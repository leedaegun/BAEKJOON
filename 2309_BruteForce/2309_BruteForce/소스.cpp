#include<iostream>
#include<algorithm>
using namespace std;

int k[10];

//2018.08.05
//�θ�Ʈ���� �ϰ� ������ 2309
//�߰��� Ȯ���Ϸ��� �ϴ� ��¹�
//�����Ҷ� ���� ������

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
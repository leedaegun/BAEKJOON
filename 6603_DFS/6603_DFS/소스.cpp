#include<iostream>
using namespace std;

//2018.08.08
//6603 DFS �ζ�
//��ü����� ���� �̰� idx�� 6�϶� �ٷ� ����ϱ�
int a[13];
int b[13];
int k;
void dfs(int, int);
int main() {

	while (scanf("%d", &k) > 0) {//�Է� �� 0�϶� ����
		a[13] = {};
		for (int i = 0; i < k; i++)
			scanf("%d", &a[i]);
		dfs(0, 0);//0,0���� ����
		cout << endl;
	}
	return 0;
}

void dfs(int start,int idx) {
	if (idx == 6) {//���� 6�϶� Ż��
		for (int i = 0; i < 6; i++)cout << b[i]<<" ";
		cout << endl;
		return;
	}
	for (int i = start; i < k; i++) {
		b[idx] = a[i];
		dfs(i + 1, idx + 1);
	}
}
#include<iostream>
using namespace std;

//2018.08.06
//�θ�Ʈ���� 1182 �κ������� ��
//dfs bfs ���̿켱Ž�� �ʺ�켱Ž��
int n, s;
int cnt;
int sum;
int a[21];
void dfs(int, int);
int main() {
	
	cin >> n>>s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		
	}
	dfs(1, 0);// �ε��� 1�϶��� ���������� �ι� �־���
	dfs(1, a[0]);

	if (s == 0)cnt--;
	cout << cnt << endl;
	
	return 0;
}

void dfs(int idx, int sum) {

	if (idx >= n) {
		if (sum == s) cnt++;//���������� ��츦 ������ �ȱ׷� �ߺ� ī��Ʈ��
		return;
	}
	dfs(idx + 1, sum);
	dfs(idx + 1, sum + a[idx]);
}
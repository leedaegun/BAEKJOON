#include<iostream>
using namespace std;


int dp[2000];
int m[2000][2000];

//2018.07.26
//dp �縰���
//printf,scanf ������ �ð��ʰ� cin,cout��������
int main() {


	int M, N;
	int n, s;
	cin >> N;//ȫ���̰� ���� �ڿ��� ����
	for (int i = 1; i <= N; i++) {
		scanf("%d", &dp[i]);//�ڿ��� ���� �Է�
	}
	for (int i = 1; i <= N; i++) {
		m[i][i] = 1;
		if (i + 1 <= N) {
			if (dp[i] == dp[i + 1]) m[i][i + 1] = 1;
		}
	}

	for (int k = 3; k <= N; k++)
	{
		for (int i = 1; i <= N - k + 1; i++)
		{
			int j = i + k - 1;
			if (dp[i] == dp[j] && m[i + 1][j - 1])
				m[i][j] = 1;
		}
	}

	cin >> M;//��찡 ������ ����
	for (int i = 0; i <M; i++) {
		scanf("%d %d", &n, &s);//��ġ �Է�
							   //cout << m[n][s] << endl;
		printf("%d \n", m[n][s]);
	}

	return 0;
}


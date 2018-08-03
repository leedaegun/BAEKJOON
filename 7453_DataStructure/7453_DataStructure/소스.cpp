#include<iostream>
#include<algorithm>
using namespace std;
long long AB[16000], CD[16000];

//2018.08.03
//�ڷᱸ�� 7453 ���� 0�� �� ����
/*- ���� BS���� mid�� �������� ���� ũ�� left = mid+1, ������ right = mid-1�� �Űܰ���.

- ������ ���⼭�� upper bound, lower bound�� ã�� ���� ��ǥ�̹Ƿ� �Űܰ��� �ʴ´�.

- ù ��° while�������� ������ �� ��ó��, 40���� ������ 40���� ũ�� ���� �ִ� ������ ã����, �� ���� lower bound

- �� ��° while�������� 40 �߿��� ���� ū ���� ã�Ƽ� upper bound�� ����.

- �ߺ��� ����ؾ��ϴ� ������ BS�� Upper, Lower Bound �����ϴ� ��ų�� �� �̿��� �� �˾ƾ߰ڴ�.*/
int main() {
	long A[4001], B[4001], C[4001], D[4001];

	int n;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB[idx] = A[i] + B[j];
			CD[idx++] = C[i] + D[j];
		}
	}

	sort(CD, CD + n*n);    // BS�� ã�� ���� �迭�� ����

	long long count = 0;
	long left = 0, right = n*n;

	for (int i = 0; i < n * n; i++) {    // AB�迭�� ó������ N*N��°���� BS�� ���� ã�´�.

		while (left < right) {
			long long mid = (left + right) / 2;
			if (AB[i] + CD[mid] < 0) left = mid + 1;
			else right = mid;
		}
		long lower_bound = right;
		//cout << "lower_bound"<<right << endl;
		left = 0, right = n*n;

		while (left < right) {
			long long mid = (left + right) / 2;

			if (AB[i] + CD[mid] <= 0) left = mid + 1;
			else right = mid;
		}
		long upper_bound = right;
		//cout << "upper_bound" << right << endl;
		count += upper_bound - lower_bound;
		left = 0, right = n*n;
	}
	printf("%lld\n", count);
	return 0;
}
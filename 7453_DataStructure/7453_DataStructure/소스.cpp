#include<iostream>
#include<algorithm>
using namespace std;
long long AB[16000], CD[16000];

//2018.08.03
//자료구조 7453 합이 0인 네 정수
/*- 보통 BS에서 mid를 기준으로 값이 크면 left = mid+1, 작으면 right = mid-1로 옮겨간다.

- 하지만 여기서는 upper bound, lower bound를 찾는 것이 목표이므로 옮겨가지 않는다.

- 첫 번째 while문에서는 위에서 든 예처럼, 40보다 작지만 40보단 크지 않은 최대 정수를 찾으면, 그 값을 lower bound

- 두 번째 while문에서는 40 중에서 가장 큰 값을 찾아서 upper bound로 설정.

- 중복을 고려해야하는 문제는 BS로 Upper, Lower Bound 설정하는 스킬을 잘 이용할 줄 알아야겠다.*/
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

	sort(CD, CD + n*n);    // BS로 찾을 기준 배열만 정렬

	long long count = 0;
	long left = 0, right = n*n;

	for (int i = 0; i < n * n; i++) {    // AB배열의 처음부터 N*N번째까지 BS로 쌍을 찾는다.

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
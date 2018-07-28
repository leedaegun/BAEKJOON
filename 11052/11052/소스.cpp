#include<iostream>
#include<math.h>
using namespace std;

//2018.07.19
//dp �ؾ
int main() {

	int N;
	int max[1000] = { 0 };
	int p[1000];
	cin >> N;
	p[0] = 0;
	for (int i = 1; i <= N; i++) {

		cin >> p[i];
	}

	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= i; j++) {

			if (max[i] < p[j] + max[i - j]) {
				max[i] = p[j] + max[i - j];
			}
		}
	}

	cout << max[N] << endl;

	return 0;
}
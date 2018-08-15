#include<iostream>
#include<algorithm>
using namespace std;

int A[51],B[51];

int main() {
	int n, s;
	s = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	sort(A, A + n);
	sort(B, B + n);
	
	for (int i = 0; i < n; i++) {
		s +=A[i] * B[n-i-1];
	}
	
	cout << s<<endl;
	return 0;
}


#include<iostream>
#include<string>
using namespace std;

char map[1001];
int main() {
	int testcase;
	int count = 1;
	cin >> testcase;
	string s;
	while (testcase > 0) {
		int tmp_case;
		cin >> tmp_case;
		for (int i = 0; i < tmp_case; i++) {
			cin >> map[i];
			if (i == 0) {
				s = map[0];
				continue;
			}
			if (s.front() <= map[i]) 
				s = map[i] + s;
			else 
				s = s + map[i];
			
		}

	
		cout << "#" << count++ << " "<< s <<endl;
		s.clear();
		testcase--;
	}

	return 0;
}
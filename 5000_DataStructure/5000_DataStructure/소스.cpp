#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

//2018.08.02
//�ڷᱸ�� 7785 ȸ�翡 �ִ� ���
//set �ڷᱸ�� ���

set<string> st;

int main() {
	

	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string name, state;
		cin >> name >> state;
		
		if (state == "enter") {
			st.insert(name);
		}
		else {
			st.erase(name);
		}
	}


	for (set<string>::reverse_iterator it = st.rbegin(); it != st.rend(); it++) {
		printf("%s \n",(*it).c_str());
	}
	return 0;
}
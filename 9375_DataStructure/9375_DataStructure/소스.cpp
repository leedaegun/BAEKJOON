#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main() {
	int n,m;

	cin >> n;

	for (int i = 0; i < n; i++) {
		map<string, int> info;
		//map<string, int> id;
		//map<int, string> back;
		int count=0;
		cin >> m;//¿Ê °¡Áþ¼ö
		
		for(int j=0;j<m;j++){
			string name, wear;
			cin >> name >> wear;
			info[wear]++;
			/*
			info[wear].push_back(name);
			if (!id.count(wear)) {
				id[wear] = count;
				back[count] = wear;
				count++;
			}*/	
		}
		long long result = 1;
		/*
		for (int j = 0; j < (1 << count); j++) {
			long long add = 1;
			for (int k = 0; k < count; k++) {
				if (j&(1 << k)) {
					add *= (long long)info[back[k]].size();
				}
			}
			result += add;
		}*/

		for (map<string, int>::iterator it = info.begin(); it != info.end(); it++) {
			result *= (long long)(it->second + 1);
		}
		cout << result - 1<<endl;
		

	}
	return 0;
}
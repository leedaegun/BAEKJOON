#include<iostream>
using namespace std;
#define max 200000 

long long mapX[max];
long long mapY[max];
int check[max];
int main() {
	int testcase;
	int count = 1;
	cin >> testcase;

	while (testcase > 0) {
		int tmp_case,x,y;
		cin >> tmp_case;

		for (int i = 0; i < tmp_case; i++) {
			cin >> mapX[i] >> mapY[i];
		}
		
		for (int i = 0; i < tmp_case; i++) {
			for (int j = i+1; j < tmp_case; j++) {
				if(mapX[i]<mapX[j]&& mapY[i]<mapY[j]){
					mapX[j] = mapY[j] = 0;
				}
				else if (mapX[i]==mapX[j] && mapY[i]<mapY[j]) {
					mapX[j] = mapY[j] = 0;
				}
				else if (mapX[i]<mapX[j] && mapY[i]==mapY[j]) {
					mapX[j] = mapY[j] = 0;
				}
			}
		}
		
		
		cout << "#" << count++ <<" ";
		for (int i = 0; i < tmp_case; i++) {
			cout << mapX[i] << " "<< mapY[i];
		}
		cout << endl;
		testcase--;
	}
	return 0;
}
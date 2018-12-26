#include<iostream>
#include<queue>
using namespace std;
int n, m, k, s;
void bfs(int, int);
int dis;
int map[1001][1001];
int check[1001];
int distance[1001];
int point[11];
int main() {
	
	int testcase;
	int count = 1;
	cin >> testcase;

	while (testcase>0) {
		dis = 0;
		cin >> n >> m >> k >> s;
		//init
		for (int i = 0; i < k; i++) {
			cin >> point[i];
		}
		for (int i = 0; i<m; i++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = map[y][x] = 1;
		}
		bfs(s, point[0]);
		for (int i = 1; i < k-1; i++) {
			bfs(point[i], point[i + 1]);
		}
		bfs(point[k - 1], s);
		cout << "#" << count << " " << dis << endl;
		testcase--;
	}
	return 0;
}
void bfs(int start, int next) {
	
	int tmp_dis=dis;
	queue<int> q;
	check[start] = 1;
	q.push(start);
	while (!q.empty()) {
		start = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (map[start][i]==1&&check[i] != 1) 
			{
				cout << start << "->"<<i;
				tmp_dis++;
				q.push(i);
				check[i] = 1;
				if (i == next) {
					dis = tmp_dis;

					cout << "next : " << next;
					cout << "  dis : " << dis << " ";
					return;
				}
			}
			
		}
	}
}

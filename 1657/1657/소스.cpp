#include<iostream>
using namespace std;


//2018.07.31
//dp 1657 두부장수 장홍준


int main() {

	int N, M;
	char m[16][16];
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> m[i][j];
		}
	}

	return 0;
}
/*#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
int d[14*14][1<<14];
char a[22][22];
int b[6][6]={
    {10,8,7,5,0,1},
    { 8,6,4,3,0,1},
    { 7,4,3,2,0,1},
    { 5,3,2,2,0,1},
    { 0,0,0,0,0,0},
    { 1,1,1,1,0,0}
};
int n,m;
int f(int u, int s) {
    if(u >= n*m){
        if(u == n*m && s == 0)return 0;
        return -1234567890;
    }
    if (d[u][s] != -1) return d[u][s];
    int ans = f(u+1, (s<<1) & ((1<<m)-1));
    int x = u/m;
    int y = u%m;
 
    if(!(s & (1<<m-1))){
        if(!(s & (1<<m-2)) && y < m-1) //가로
            ans = max(ans, b[a[x][y]-'A'][a[x][y+1]-'A'] + f(u+2, (s<<2) & ((1<<m)-1)));
        if(x < n-1) //세로
            ans = max(ans, b[a[x][y]-'A'][a[x+1][y]-'A'] + f(u+1, ((s<<1)+1) & ((1<<m)-1)));
    }
    return d[u][s] = ans;
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i ++) scanf("%s",a[i]);
    memset(d,-1,sizeof(d));
    printf("%d",f(0,0));
    return 0;
	}*/
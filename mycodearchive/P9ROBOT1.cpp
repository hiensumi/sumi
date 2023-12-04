// hiensumi is on the sky
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<time.h>
#include<utility>
#include<vector>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define name ""
#define non 5000+1
#define pog 1000000000+7
#define db double
#define mask(i) (1LL<<(i))
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
typedef pair<int, int> ii;
struct point{
	int x, y;
	point operator- (const point& a)const{
		return {(x - a.x), (y - a.y)};
	}
	int operator* (const point& a)const{
		return x * a.y - y * a.x;
	}
};
struct edge{
	int u, v, c;
};
/*int find(int u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
}
bool join(int u, int v) {
    int paru = find(u), parv = find(v);
    if (paru == parv) return false;
    par[parv] = paru;
    return true;
}*/	
const int MOD = 1e9 + 7;
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e6 + 5;
int n, m, a[25][25], f[25][25], dd[25][25];
int hcn(int x,int y, int u, int v){
	return f[u][v] - f[x-1][v] - f[u][y-1] + f[x-1][y-1];
}
int inside(int x, int y){
	return (1 <= x and x <= n and 1 <= y and y <= m);
}
int trulyinside(int x, int y, int u, int v){
	// return (1 < x and x < n and 1 < y and y < m);
	if(!inside(x,y) or !inside(u,v)) return 0;	
	if(x == 1 and y == 1) return 0;
	if(u == n and v == m) return 0;
	return 1;
}
void block(int x, int y, int u, int v){
	fod(i,x,u) fod(j,y,v) a[i][j] = 1;
}
void unblock(int x, int y, int u, int v){
	fod(i,x,u) fod(j,y,v) a[i][j] = 0;
}
int di1[] = {-1,1,0,0};
int di2[] = {0,0,-1,1};
void DFS(int x, int y){
	dd[x][y] = 1;
	fod(i,0,3){
		int u = x + di1[i], v = y + di2[i];
		if(!dd[u][v]){
			if(a[u][v] == 0 and inside(u,v)) DFS(u,v);
		}
	}
}
bool dfs(){
	memset(dd, 0, sizeof dd);
	DFS(1,1);
	return dd[n][m] == 1;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(".inp", "r")){
		freopen(".inp", "r", stdin);
	    freopen(".out", "w", stdout);
	}
	else if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n >> m;
	swap(m,n);
	fod(i,1,n) fod(j,1,m){
		char c; cin >> c;
		a[i][j] = (c != '.');
	}
	fod(i,1,n) fod(j,1,m) f[i][j] = a[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
	fod(k,1,max(n,m)){
		fod(i,1,n) fod(j,1,m){
			if(i == 1 and j == 1) continue;
			if(i == n and j == m) continue;
			if(trulyinside(i,j,i + k- 1, j + k - 1)){
				int q = hcn(i,j,i+k-1,j+k-1);
				if(q == 0){
					block(i,j,i+k-1,j+k-1);
					if(!dfs()){
						cout << k << endl;
						cerr << "\nTime: " << clock() << "ms\n";
						cerr << "Code now ->قَمَر \n";
						return 0;
					}
					else{
						unblock(i,j,i+k-1,j+k-1);
					}
				}
			}
		}
	}
	cout << "Impossible";
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "Code now ->قَمَر \n";
	return 0;
}

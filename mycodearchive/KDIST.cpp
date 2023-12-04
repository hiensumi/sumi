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
const int oo = 1e18 + 1 + 2 + 3 + 4 + 5 + 12345678910;
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
const int base = 1e5 + 5;
int n, m, p[base][22], h[base], k, mark[base],dd[base];
vector <int> special, adj[base];
void dfs(int u, int pu){
	for(int v : adj[u]){
		if(v == pu) continue;
		h[v] = h[u] + 1;
		p[v][0] = u;
		fod(j,1,log2(n)){
			p[v][j] = p[p[v][j-1]][j-1];
		}
		dfs(v,u);
	}
}
void DFS(int u, int pu){
	for(int v : adj[u]){
		if(v == pu) continue;
		h[v] = h[u] + 1;
		DFS(v,u);
	}
}
int lca(int u, int v){
    if (h[u] < h[v]) swap(u,v);
    int k = h[u] - h[v];
    for(int j = 0; (1 << j) <= k; j++) if(k & (1 << j)) u = p[u][j];
    if (u == v) return u;
    int d = log2(h[u]);
    fok(j,d,0) if (p[u][j] != p[v][j]){
        u = p[u][j]; v = p[v][j];
    }
    return p[u][0];
}
int dist(int u, int v){
	return h[u] + h[v] - 2 * h[lca(u,v)];
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
	cin >> n >> m >> k;
	fod(i,1,n-1){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	fod(i,1,m){
		int x; cin >> x;
		special.pb(x);
	}
	DFS(1,0);
	int lowest1 = 1;
	fod(i,1,n){
		if(h[lowest1] < h[i]){
			lowest1 = i;
		}
	}
	h[lowest1] = 0;
	DFS(lowest1,0);
	int lowest2 = lowest1;
	fod(i,1,n){
		if(h[lowest2] < h[i]) lowest2 = i;
	}
	int nearest1 = 0, nearest2 = 0;
	h[1] = 0;
	dfs(1,0);
	for(int x : special){
		if(dist(nearest1,lowest1) > dist(x,lowest1)) nearest1 = x;
	}
	for(int x : special){
		if(dist(nearest2,lowest2) > dist(x,lowest2)) nearest2 = x;
	}
	int cnt = 0;
	fod(i,1,n){
		int ma = max(dist(i,nearest1), dist(i,nearest2));
		if(ma <= k){
			cnt++;
		}
	}
// this algo is wrong. move to KDIST_ALGO2
	cout << cnt;
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "Code now ->قَمَر \n";
	return 0;
}

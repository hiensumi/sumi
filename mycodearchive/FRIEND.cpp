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
#define BITpos(a,i) (a & mask(i))
#define pb push_back
#define el '\n'
#define odd(i) (i & 1LL)
using namespace std;
void read(){}
void read(long long& a){scanf("%lld",&a);}
void read(long& a){scanf("%ld",&a);}
void read(double& a){scanf("%lf",&a);}
void read(float& a){scanf("%f",&a);}
void read(string& a){cin>>a;}
template<typename x,typename y>void read(pair<x,y>& a){ read(a.first),read(a.second);}
template<typename x>void read(x& a){for(auto  &i : a) read(i);}
template<typename x,typename... y>void read(x& a,y&... b){read(a);read(b...);}
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
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 2e5 + 5;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
int n, h[base], par[base][21], LG2[base];
struct bg{
	int v, c1, c2;
};
vector <bg> adj[base];
void dfs(int u, int p){
	for(bg x : adj[u]){
		int v = x.v;
		if(v == p) continue;
		h[v] = h[u] + 1;
		par[v][0] = u;
		fod(j,1,LG2[n]){
			par[v][j] = par[par[v][j-1]][j-1];
		}
		dfs(v,u);
	}
}
int lca(int u, int v){
    if (h[u] < h[v]) swap(u,v);
    int k = h[u] - h[v];
    for(int j = 0; (1 << j) <= k; j++) if(k & (1 << j)) u = par[u][j];
    if (u == v) return u;
    int d = LG2[h[u]];
    fok(j,d,0) if (par[u][j] != par[v][j]){
        u = par[u][j]; v = par[v][j];
    }
    return par[u][0];
}
int ans = 0, dp[base];
// int dp[base], start[base], stop[base], counter[base];
void dfs2(int u, int p){
	for(bg x : adj[u]){
		int v = x.v;
		if(v == p) continue;
		dfs2(v,u);
		dp[u] += dp[v];
		ans += min(dp[v] * x.c1, x.c2);
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	else if(fopen(".inp", "r")){
		freopen(".inp", "r", stdin);
	    freopen(".out", "w", stdout);
	}
	cin >> n;
	fod(i,1,n-1){
		int u, v, c1, c2;
		cin >> u >> v >> c1 >> c2;
		adj[u].pb({v,c1,c2});
		adj[v].pb({u,c1,c2});
	}
	LG2[1] = 0;
	fod(i,2,n) LG2[i] = LG2[i/2] + 1;
	dfs(1,0);
	fod(u,1,n-1){
		int v = u + 1;
		int x = lca(u,v);
		dp[u]++;
		dp[v]++;
		dp[x] -= 2;
	}
	dfs2(1,0);
	cout << ans;
	kill();
}

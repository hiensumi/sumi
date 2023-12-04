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
	int x, y, id;
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
inline int bp(int x, int y){int ans = 1; while(y > 0){ if(y & 1) ans *= x; x *= x; y >>= 1;} return ans;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e5 + 5;
int n, m, h[base], p[base][22], mark[base], dd[base * 10], f[base], cnt = 0;
vector <int> adj[base], loc, tri[base], where;
void dfs(int u){
	dd[u] = 1;
	for(int v : tri[u]){
		if(dd[v]) continue;
		h[v] = h[u] +  1;
		p[v][0] = u;
		fod(j,1,log2(n)){
			p[v][j] = p[p[v][j-1]][j-1];
		}
		dfs(v);
	}
}
int lca(int u, int v){
	if(h[u] < h[v]) swap(u,v);
	int k = h[u] - h[v];
	for(int j = 0; (1 << j) <= k; j++) if(k & (1 << j)) u = p[u][j];
	if(u == v) return u;
	int d = log2(h[u]);
	fok(j,d,0) if(p[u][j] != p[v][j]){
		u = p[u][j];
		v = p[v][j];
	}
	return p[u][0];
}
void dpp(int u, int dad){
	dd[u] = 1;
	for(int v : adj[u]){
		if(dd[v]) continue;
		if(mark[v]){
			mark[dad] = 0;
			dpp(v,v);
		} 
	}
}
bool cmp(int u, int v){
	return h[u] < h[v];
}
void ddd(int u){
	dd[u] = 1;
	f[u] += mark[u];
	for(int v : adj[u]){
		if(dd[v]) continue;
		ddd(v);
		f[u] += f[v];
	}
}
void fff(int u){
	dd[u] = 1;
	// cout << u << " ";
	where.pb(u);
	for(int v : adj[u]){
		if(dd[v]) continue;
		if(f[v] > 0){
			tri[u].pb(v);
			tri[v].pb(u);
			cnt++;
			fff(v);
		}
	}
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
	cin >> n >> m;
	fod(i,1,m){
		int x; cin >> x;
		mark[x] = 1;
	}
	fod(i,1,n-1){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dpp(0,n + 2);
	fod(i,1,n){
		if(mark[i]) loc.pb(i);
	}
	sort(loc.begin(), loc.end(), cmp);
	memset(dd,0,sizeof dd);
	ddd(loc[0]);
	memset(dd,0,sizeof dd);
	fff(loc[0]);
	memset(dd,0,sizeof dd);
	dfs(loc[0]);
	int random = where[0], id = 0, ma = -1e18;
	fod(j,1,where.size()-1){
		if(ma < dist(random,where[j])){
			id = j;
			ma = dist(random,where[j]);
		}
	}
	int res = -1e18, newid = 0;
	fod(j,0,where.size() - 1){
		res = max(res, dist(where[id],where[j]));
	}
	// cnt++;
	// cout << res << " " << cnt;
	// cout << f[0];
	// cout << endl;
	cout << 2 * cnt - res;
	// cout << res << " " << cnt;
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n";
	return 0;
}
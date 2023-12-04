// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
#include "bits/stdc++.h"
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define mask(i) (1LL<<(i))
#define BITpos(a,i) ((a >> i) & 1LL)
#define pb push_back
#define el '\n'
#define odd(i) (i & 1LL)
using namespace std;
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
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
/*int find(int u) { if (par[u] == u) return u; return par[u] = find(par[u]);}
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true; }*/ 
const ll INF = 1e18, base = 2e5 + 5e4 + 19, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
int n, q, num_child[base], h[base], p[base][21], f[base], g[base], dp[base], s[base];

// f[v] là số lượng đường đi thuộc cây con nhánh u (u cha v) mà đường đi không qua v
// g[u] là số lượng đùowng đi thuộc cây nhánh u phải đi qua u
// formula:
// f[v] = g[u] - (num_child[v] * (num_child[u] - num_child[v]))
// g[u] = g[u] + num_child[u] * num_child[v]
vector <int> adj[base];
void inp(){
	cin >> n >> q;
	fod(i,1,n-1){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
}
void dfs(int u, int par, int dummy){
	for(int v : adj[u]){
		if(v == par) continue;
		h[v] = h[u] + 1;
		p[v][0] = u;
		fod(j,1,log2(n)){
			p[v][j] = p[p[v][j-1]][j-1];
		}
		dfs(v,u,dummy);
		g[u] += num_child[u] * num_child[v];
		num_child[u] += num_child[v];
	}
}
int a, b;
int lca(int u, int v){
    if (h[u] < h[v]) swap(u,v);
    int k = h[u] - h[v];
    for(int j = 0; (1 << j) <= k; j++) if(k & (1 << j)){
    	 u = p[u][j];
    }
    if (u == v) return u;
    int d = log2(h[u]);
    fok(j,d,0){
    	if (p[u][j] != p[v][j]){
        	u = p[u][j]; v = p[v][j];
    	}
    }
    return p[u][0];
}
void dfs1(int u, int p){
	for(int v : adj[u]){
		if(v != p){
			f[v] = g[u] - (num_child[v] * (num_child[u] - num_child[v]));
 			dp[v] = dp[u] + f[v];
 			dfs1(v,u);
 		}
	}
}
int jump(int u, int par){
	int k = h[u] - h[par] - 1;
	if(k < 0) return 0;
    for(int j = 0; (1 << j) <= k; j++) if(k & (1 << j)){
        u = p[u][j];
    }
    return u;
}
namespace sub_task2{
	void solve(){
		fod(i,1,n) num_child[i] = g[i] = 1;
		dfs(1,0, INF);
		dfs1(1,0);
		// cout << jump(5,1) << el;
		while(q--){
			int u, v; cin >> u >> v;
			int x = lca(u,v);
			a = jump(u,x); b = jump(v,x);
			if(u == v){
				cout << g[u] + num_child[u] * (n - num_child[u]) << el;
				continue;
			}
			
			int nhanh_a = 0, nhanh_b = 0, od = 0;
			if(a != 0){
				nhanh_a = g[u] + dp[u] - dp[a];
				od += num_child[a] * (n - num_child[a]);
			}
			if(b != 0){
				nhanh_b = g[v] + dp[v] - dp[b];
				od += num_child[b] * (n - num_child[a] - num_child[b]);
			}
			cout << nhanh_a + nhanh_b - od + g[x] + num_child[x] * (n - num_child[x]) << el;
		}
		
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	  freopen(name".inp", "r", stdin);
	  freopen(name".out", "w", stdout);
	}
	int Test = 1; if(multitest) cin >> Test;
	while(Test--){
		inp();
		sub_task2 :: solve();
	}
	kill();
}
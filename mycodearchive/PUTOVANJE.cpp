// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
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
#define all(v) v.begin(), v.end()
#define odd(i) (i & 1LL)
using namespace std;
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { int tmp = x; mul(tmp, Inv(y, mod), mod); return tmp;}
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
struct point{int x, y;};
struct edge{int u, v, c1, c2;};
//int find(int u){if (lab[u] < 0) return u; return lab[u] = find(lab[u]);}
// bool join(int u, int v){u = find(u);v = find(v);if(u == v) return 0;if(lab[u] > lab[v]) swap(u,v);lab[u] += lab[v];lab[v] = u;}
const ll INF = 1e18, base = 2e5 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
struct DL{
	int v, c1, c2;
};
int n, h[base], par[base][21];
vector <DL> adj[base];
vector <edge> e;
void dfs(int u){
	for(auto [v,c1,c2] : adj[u]){
		if(v == par[u][0]) continue;
		h[v] = h[u] + 1;
		par[v][0] = u;
		fod(j,1,18){
			par[v][j] = par[par[v][j-1]][j-1];
		}
		dfs(v);
	}
}
int lca(int u, int v){
    if (h[u] != h[v]) {
    	if (h[u] < h[v]) swap(u,v);
		int k = h[u] - h[v];
		for (int tmp = k; tmp > 0; tmp ^= tmp & -tmp) {
			int j = __builtin_ctz(tmp & -tmp);
			u = par[u][j];
		}
    }
    if (u == v) return u;
    int d = __lg(h[u]);
    fok(j,d,0) if (par[u][j] != par[v][j]){
        u = par[u][j]; v = par[v][j];
    }
    return par[u][0];
}
void inp(){
	cin >> n;
	fod(i,1,n-1){
		int u, v, c1, c2;
		cin >> u >> v >> c1 >> c2;
		e.pb({u,v,c1,c2});
		adj[u].pb({v,c1,c2});
		adj[v].pb({u,c1,c2});
	}
}

namespace sub_task1{
    int pass[base], res = 0;
    void DFS(int u){
    	for(auto [v,c1,c2] : adj[u]){
    		if(v == par[u][0]) continue;
    		DFS(v);
    		pass[u] += pass[v];
    		res += min(pass[v] * c1, c2);
    	}
    }
    void solve(){
    	dfs(1);
    	fod(u,1,n-1){
    		int v = u + 1;
    		int x = lca(u,v);
    		pass[u]++;
    		pass[v]++;
    		pass[x]-=2;
    	}
    	DFS(1);
    	cout << res;
    }	
    
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(name".inp", "r")){
      freopen(name".inp", "r", stdin);
      freopen(name".out", "w", stdout);
    }
    int Test = 1; if(multitest) cin >> Test;
    init();
    while(Test--){
        inp();
        sub_task1 :: solve();
    }
    kill();
}

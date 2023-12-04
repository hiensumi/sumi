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
struct edge{int u, v, c;};
/*int find(int u) { if (par[u] == u) return u; return par[u] = find(par[u]);}
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true; }*/ 
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!

int n, q;
vector <int> adj[base];
int tour[base], st[base] , en[base], m = 0, h[base], par[base][21], rmq[base][21];
void dfs(int u, int p){
	tour[++m] = u ;
	st[u] = m;
	for(int v : adj[u]){
		if(v != p ){
			h[v] = h[u] + 1;
			par[v][0] = u;
			fod(j,1,log2(n)) par[v][j] = par[par[v][j-1]][j-1];
			dfs(v,u);
		}
	}
	en[u] = m;
}
int lca(int u, int v){
	if(h[u] < h[v]) swap(u,v);
	int k = h[u] - h[v];
	fod(j,0,log2(n)) if(k & mask(j)) u = par[u][j];
	if(u == v) return u;
	int d = log2(h[u]);
	fok(j,d,0) if(par[v][j] != par[u][j]){
		u = par[u][j];
		v = par[v][j];
	}
	return par[u][0];
}
int lg[base], mq[base][21];
int get(int l, int r){
	if(l > r) return INF;
	int k = lg[r - l + 1];
	return lca(rmq[l][k], rmq[r - mask(k) + 1][k]);
}
void init(){
	fod(i,1,n) rmq[i][0] = tour[i];
	fod(i,2,n) lg[i] = lg[i/2] + 1;
	fod(j,1,log2(n)){
		fod(i,1,n - mask(j) + 1){
			rmq[i][j] = lca(rmq[i][j], rmq[i + mask(j-1)][j-1]);
		}
	}
}
void inp(){
	cin >> n >> q;
	fod(i,1,n-1){
		int u, v; cin >>u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
}

namespace sub_task1{
	void solve(){
		dfs(1,0);
		while(q--){
			int l, r; cin >> l >> r;	
			// int 
			cout << l << " " << r << el;
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
	init();
	while(Test--){
		inp();
		sub_task1 :: solve();
	}
	kill();
}
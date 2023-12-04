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
const ll INF = 1e18, base = 2e5 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!

int n, q;
vector <int> adj[base];
int tour[base], st[base] , en[base], m = 0, h[base], par[base][22];
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
int lg[base], rmq[base][22];
int mi[base][22], ma[base][22];
int get(int l, int r){
	if(l > r) return INF;
	int k = lg[r - l + 1];
	return lca(rmq[l][k], rmq[r - mask(k) + 1][k]);
}
int getmi(int l, int r){
	if(l > r) return INF;
	int k = lg[r - l + 1];
	return min(mi[l][k], mi[r - mask(k) + 1][k]);
}
int getma(int l, int r){
	if(l > r) return -INF;
	int k = lg[r - l + 1];
	return max(ma[l][k], ma[r - mask(k) + 1][k]);
}
void init(){
	// memset(mi, 0x3f, sizeof mi);
	
}
void inp(){
	cin >> n >> q;
	fod(i,2,n){
		int x; cin >> x;
		adj[i].pb(x);
		adj[x].pb(i);
		
	}
	
	dfs(1,0);
	fod(i,1,n) rmq[i][0] = i;

	fod(i,1,n) mi[i][0] = st[i], ma[i][0] = st[i];
	
	fod(i,2,n) lg[i] = lg[i/2] + 1;
	fod(j,1,21){
		for(int i = 1; i + mask(j) - 1 <= n; i++){
			rmq[i][j] = lca(rmq[i][j-1], rmq[i + mask(j-1)][j-1]);
			mi[i][j] = min(mi[i][j-1], mi[i + mask(j-1)][j-1]);
			ma[i][j] = max(ma[i][j-1], ma[i + mask(j-1)][j-1]);
		}
	}

}

namespace sub_task1{
	void solve(){
		while(q--){
			int l, r; cin >> l >> r;	
			int left = getmi(l, r);
			int right = getma(l,r);
			// cout << left << " " << right << el;
			int x1 = get(l,tour[left] - 1);
			int x2 = get(tour[left] + 1, r);
			bool ch1 = (x1 == INF);
			bool ch2 = (x2 == INF);

			int res = -INF;
			if(ch1 == 0 and ch2 == 1) maxi(res, h[x1]);
			else if(ch2 == 0 and ch1 == 1) maxi(res, h[x2]);
			else maxi(res, h[lca(x1,x2)]);

			int trace = res;

			x1 = get(l, tour[right] - 1);
			x2 = get(tour[right] + 1, r);
			ch1 = (x1 == INF);
			ch2 = (x2 == INF);
			if(ch1 == 0 and ch2 == 1) maxi(res, h[x1]);
			else if(ch2 == 0 and ch1 == 1) maxi(res, h[x2]);
			else maxi(res, h[lca(x1,x2)]);

			if(res == trace){
				cout << tour[left] << " " << res << el;
			}
			else{
				cout << tour[right] << " " << res << el;
			}

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
		sub_task1 :: solve();
	}
	kill();
}
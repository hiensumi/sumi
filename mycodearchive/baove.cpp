// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
#include "bits/stdc++.h"
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define int long long
#define fi first
#define se second
#define mask(i) (1LL<<(i))
#define BITpos(a,i) ((a >> i) & 1LL)
#define pb push_back
#define el '\n'
#define odd(i) (i & 1LL)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
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
struct point{int x, y;};
struct edge{ int u, v, c;};
/*int find(int u) { if (par[u] == u) return u; return par[u] = find(par[u]);}
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true;
}*/ 
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
int n, par[5007], f[5007][5007], rc[5007][5007];
vector <int> adj[5007];
void init(){}
void bfs(int s){
	queue <int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(par[v] == -1 and rc[u][v] > f[u][v]){
				par[v] = u;
				q.push(v);
			}
		}
	}	
}
void maxflow(int s, int t){
	while(1){
		memset(par, -1, sizeof par);
		int addflow = INF;
		par[s] = 0;
		bfs(s);
		if(par[t] == -1) break;
		for(int u = t; u != s; u = par[u]){
			addflow = min(addflow, rc[par[u]][u] - f[par[u]][u]);
		}
		for(int u = t; u != s; u = par[u]){
			f[u][par[u]] -= addflow;
			f[par[u]][u] += addflow;
		}
	}
}
void add_e(int u, int v, int w){
	rc[u][v] += w;
	adj[u].pb(v);
	adj[v].pb(u);
}
void inp(){
	cin >> n;
	int u = -1, v = -1, c = -1;
	while(cin >> u >> v >> c){
		add_e(u,v,c);
		u = -1; v = -1; c = -1;
	}
}
namespace sub_task1{
	
	void solve(){
		int s = n, t = 1;
		maxflow(s,t);
		int res= 0;
		// for(int v : adj[t]) res += f[v][t];
		fod(i,1,n) res += f[i][1];		
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
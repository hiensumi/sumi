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
void init(){
    
}
int n, m, res = 0, stt = 0, S , dd[base], trace[base], low[base], num[base], tplt[base], val[base];
vector <ii> adj[base];
stack <int> st;
void dfs(int u){
	low[u] = num[u] = ++stt;
	st.push(u);
	for(auto [v,w] : adj[u]){
		if(dd[v]) continue;
		if(num[v]) low[u] = min(low[u], num[v]);
		else{
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
	}
	if(low[u] == num[u]){
		int x = 0;
		res++;
		do{
			x = st.top();
			st.pop();
			dd[x] = 1;
			tplt[x] = res;
		}while(x != u);
	}
}
int f[base], p[base];
int calc(int w){
	int j = upper_bound(p + 1, p + (int) 1e5 + 1, w ) - p - 1;
	return (j + 1) * w - f[j];
}
void inp(){
	fod(i,1,1e5) p[i] = i * (i + 1)/2;
	fod(i,1,1e5) f[i] = f[i-1] + i * (i + 1) / 2;
	cin >> n >> m >> S;
	fod(i,1,m){
		int u, v, w ; cin >> u >> v >> w;
		// w = calc(w);
		adj[u].pb(ii(v,w));
	}
	dfs(S);
}
int dp[base];
stack <int> topo;
vector <ii> g[base];
int ans = 0;
void dfs2(int u){
	dd[u] = 1;
	for(auto [v,w] : g[u]){
		if(dd[v] == 0) dfs2(v);
	}
	topo.push(u);
}
namespace sub_task1{
    void solve(){
 		fod(u,1,n){
 			for(auto [v,w] : adj[u]){
 				int paru = tplt[u], parv = tplt[v];
 				if(paru == parv){
					val[paru] += calc(w);				
 				}
 				else{
 					g[paru].pb(ii(parv, w));
 				}
 			}
 		}
 		memset(dd, 0, sizeof dd);
 		fod(i,1,res) dp[i] = val[i];
 		fod(i,1,res) if(dd[i] == 0) dfs2(i);
    	while(topo.size()){
    		int u = topo.top(); topo.pop();
    		maxi(ans, dp[u]);
    		for(auto [v,w] : g[u]){
    			maxi(dp[v], dp[u] + w + val[v]);
    		}
    	}
    	cout << ans;
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
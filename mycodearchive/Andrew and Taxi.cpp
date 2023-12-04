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
struct edge{int u, v, c, id;};
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
int n, m, dd[base];
vector <int> adj[base];
edge e[base];
vector <int> pichi;
stack <int> topo;
int id[base];
bool dfs(int u){
	dd[u] = 1;
	int ch = 1;
	for(int v : adj[u]){
		if(dd[v] == 1) return 0;
		if(dd[v] == 0){
			ch = (ch and dfs(v));
		}
	}
	topo.push(u);
	dd[u] = 2;
	return ch;
}
bool check(int x){
	memset(dd, 0, sizeof dd);
	fod(i,1,n) adj[i].clear();
	topo = stack<int>();
	int cnt = 0;
	fod(i,1,m){
		if(e[i].c <= x){
			continue;
		}
		adj[e[i].u].pb(e[i].v);
	}
	int res = 1;
	fod(i,1,n) if(dd[i] == 0) res = (res and dfs(i));
	while(!topo.empty()){
		id[topo.top()] = ++cnt;
		topo.pop();
	}
	return res;
}
// map <pair<pair<int,int>,int>, int> mp;
void inp(){
	cin >> n >> m;
	fod(i,1,m){
		int u, v, c; cin >> u >> v >> c;
		e[i] = {u,v,c,i};
		pichi.pb(c);
	}
}

namespace sub_task1{
	void solve(){
		pichi.pb(-INF);
		pichi.pb(0);
		sort(all(pichi));
		int l = 1, r = m + 1, ans = 0;
		while(l <= r){
			int mid = l + r >> 1;
			if(check(pichi[mid])){
				r = mid - 1;
				ans = pichi[mid];
			}
			else l = mid + 1;
		}
		if(check(ans)){
			vector <int> res;
			fod(i,1,m) if(id[e[i].u] > id[e[i].v]) res.pb(e[i].id);
			cout << ans << " " << res.size() << el;
			for(int x : res) cout << x << " ";
			kill();
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
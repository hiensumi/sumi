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
int n, a[205][205];
void init(){
	
	
}
void inp(){
	cin >> n;
	fod(i,1,n) fod(j,1,n) cin >> a[i][j];
}


namespace sub_task1{
	int par[405], dd[405];
	vector <int> adj[base];
	void load_graph(int limit){
		fod(i,1,n) adj[i].clear();
		fod(i,1,n) fod(j,1,n) if(a[i][j] <= limit) adj[i].pb(j);
	}
	bool konig(int u){
		if(dd[u]) return 0;
		dd[u] = 1;
		for(int v : adj[u]){
			if(par[v] == 0 or konig(par[v])){
				par[v] = u;
				return 1;
			}
		}
		return 0;
	}
	bool check(int lim){
		load_graph(lim);
		memset(par, 0, sizeof par);
		fod(i,1,n){
			fod(j,1,n) dd[j] = 0;
			konig(i);
		}
		int res = 0;
		fod(i,1,n) res += (par[i] != 0);
		return res == n;
	}
	void solve(){
		int l = 0, r = INF, ans = -1;
		while(l <= r){
			int mid = l + r >> 1LL;
			if(check(mid)) r = mid - 1, ans = mid;
			else l = mid + 1;
		}
		cout << ans << el;
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
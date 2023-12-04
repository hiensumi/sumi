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
#define all(v) v.begin(), v.end()
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
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true;
}*/ 
const ll INF = 1e18, base = 5e4 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
int n, m, s;
vector <int> adj[base];
void init(){
	
	
}
void inp(){
	cin >> n >> m >> s;
	fod(i,1,m){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
}


namespace sub_task1{
	int dis[base];
	bitset <base> sp[base], num_way[base];
	
	void bfs(){
		memset(dis, -1, sizeof dis);
		dis[s] = 0;
		num_way[s][s] = 1;
		queue <int> q;
		q.push(s);
		while(q.size()){
			int u = q.front(); q.pop();
			sp[dis[u]][u] = 1;
			num_way[u][u] = 1;
			for(int v : adj[u]){
				if(dis[v] == -1){
					dis[v] = dis[u] + 1;
					num_way[v] = num_way[u];
					q.push(v);
				}
				else if(dis[v] == dis[u] + 1){
					num_way[v] = num_way[v] | num_way[u];
				}
			}
		}
	}
	bitset <base> new_p;
	void calc(int t, int d){
		if(dis[t] < d) return void(cout << 0 << el);
		new_p = num_way[t] & sp[d];
		if(new_p.count() != 1) return void(cout << -1 << el);
		cout << new_p._Find_first() << el;
	}
	void solve(){
		int q; cin >> q;
		bfs();
		while(q--){
			int t, d; cin >> t >> d;
			calc(t,d);
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
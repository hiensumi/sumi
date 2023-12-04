// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
// #include <bits/stdc++.h>
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
#include<ctime>
#include<utility>
#include<vector>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define mask(i) (1LL<<(i))
#define BITpos(a,i) (a & mask(i))
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
const ll INF = 1e18;
const int base = 1e6 + 5;
const bool multitest = 1;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
namespace solution{
	int n, m, st[base], en[base], val[base], last = 0, a[base];
	vector <int> adj[base];	
	void inp(){
		cin >> n >> m;
		fod(i,1,n-1){
			int u, v; cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		fod(i,1,m){
			cin >> a[i];
		}
	}
	int timeDfs = 0, h[base];
	void dfs(int u, int p){
		st[u] = ++timeDfs;
		for(int v : adj[u]){
			if(v == p) continue;
			h[v] = h[u] + 1;
			dfs(v,u);
		}
		en[u] = ++timeDfs;
	}
	void sub2(){
		int res = 0;
		dfs(1,0);
		vector <int> leaf;
		leaf.pb(-INF);
		fod(u,1,n) if(st[u] + 1 == en[u]) leaf.pb(h[u] - h[1]);
		sort(leaf.begin(), leaf.end());
		vector <int> pre(n + 1);
		int sz = leaf.size() - 1;
		fod(i,1,sz) pre[i] = pre[i-1] + leaf[i];
		a[0] = 0;
		fod(i,0,m-1){
			int j = lower_bound(leaf.begin(), leaf.end(), a[i+1] - a[i]) - leaf.begin();
			res += (j - 1) * (a[i+1] - a[i]) - pre[j - 1]; 
		}
		cout << res << el;
		fod(i,1,2 * n) st[i] = en[i] = 0;
		fod(i,1,n) h[i] = 0, adj[i].clear();
		leaf.clear();
			
	}
	void solve(){
		inp();
		sub2();
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	  freopen(name".inp", "r", stdin);
	  freopen(name".out", "w", stdout);
	}
	else if(fopen(".inp", "r")){
	freopen(".inp", "r", stdin);
	  freopen(".out", "w", stdout);
	}
	int Test = 1; if(multitest) cin >> Test;
	while(Test--) solution :: solve();
	kill();
}
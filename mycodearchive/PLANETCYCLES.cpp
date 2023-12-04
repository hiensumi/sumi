// hiensumi is on the sky
// #pragma GCC optimize("O3")
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
#include<time.h>
#include<utility>
#include<vector>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define name ""
#define non 5000+1
#define pog 1000000000+7
#define db double
#define mask(i) (1LL<<(i))
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
typedef pair<int, int> ii;
struct point{
	int x, y, id;
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
const int MOD = 1e9 + 7;
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bp(int x, int y){int ans = 1; while(y > 0){ if(y & 1) ans *= x; x *= x; y >>= 1;} return ans;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 2e5 + 5;
int dd[base], num[base],n, low[base], sz[base], stt = 0, res = 0, tp[base], inp[base], vao[base], more[base], f[base];
vector <int> adj[base], g[base];
stack <int> st;
void dfs(int u, int p){
	stt++;
	low[u] = num[u] = stt;
	st.push(u);
	for(int v : adj[u]){
		if(dd[v] and v == p) continue;
		if(num[v] != 0) low[u] = min(low[u], num[v]);
		else{
			dfs(v,p);
			low[u] = min(low[u], low[v]);
		}
	}
	int x;
	if(low[u] == num[u]){
		res++;
		do{
			x = st.top(); st.pop();
			dd[x] = 1;
			tp[x] = res;
			sz[res]++;
		}while(x != u);
	}
}
void DFS(int u, int p){
	for(int v : g[u]){
		if(v == p or v == 0) continue;
		DFS(v,u);
		more[u] = sz[v] + more[v];
	}
}
signed main(){
	if(fopen(".inp", "r")){
		freopen(".inp", "r", stdin);
	    freopen(".out", "w", stdout);
	}
	else if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n;
	fod(i,1,n){
		int x;
		cin >> x;
		if(x != i){
			inp[i] = x;
			adj[i].pb(x);
		}
	}
	fod(i,1,n){
		if(num[i] == 0){
			dfs(i,0);
		}
	}
	fod(i,1,n){
		int u = tp[i], v = tp[inp[i]];
		if(u != v){
			vao[v]++;
			// g[u] = v;
			g[u].pb(v);
		}
	}
	more[0] = 0;
	fod(i,1,res) f[i] = sz[i];
	// fod(i,1,res){
	// 	if(vao[i] == 0) DFS(i,0);
	// }
	fod(i,1,n) cout << f[tp[i]] + more[tp[i]] << " ";
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n";
	return 0;
}
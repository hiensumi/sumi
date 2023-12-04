// hiensumi is on the sky
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
#define int long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define name ""
#define non 5000+1
#define pog 1000000000+7
#define db double
#define mask(i) (1LL<<(i))
#define pb push_back
#define el '\n'
using namespace std;
void read(){}
void read(long long& a){scanf("%lld",&a);}
void read(long& a){scanf("%ld",&a);}
void read(double& a){scanf("%lf",&a);}
void read(float& a){scanf("%f",&a);}
void read(string& a){cin>>a;}
template<typename x,typename y>void read(pair<x,y>& a){ read(a.first),read(a.second);}
template<typename x>void read(x& a){for(auto  &i : a) read(i);}
template<typename x,typename... y>void read(x& a,y&... b){read(a);read(b...);}
const int oo = 1e18 + 1 + 2 + 3 + 4 + 5 + 12345678910;
typedef pair<int, int> ii;
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
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e5 + 5;
// dont use write like write("abc"). use it like write(x). x is the string variable
// dont use write like write(5). use it like write((int) 5). write(1e18) or any other float variables is fine
int n, m, q, c[base], p[base][21], h[base], lg2[base], sec[base];
vector <int> adj[base];
struct multis{
	int n = 12, a[12];
	multis(){
		memset(a,0x3f,sizeof a);
	}
	int size(){
		int res = 0;
		// fod(i,0,10){
		//     if(a[i] <= m) res++;
		//     else break;
		// }
		res = upper_bound(a,a+11,m) - a - 1;
		return res;
	}
	void push(int x){
		a[10] = x;
		sort(a, a + 10 + 1);
	}
}pq[base][21];
multis merge(multis a, multis b){
	// fod(i,0,10) a.push(b.a[i]);
	// return a;
	if(a.size() > b.size()) swap(a,b);
	fod(i,0,a.size()) b.push(a.a[i]);
	return b;
}
void dfs(int u, int par, int branch){
	for(int v : adj[u]){
		if(v == par) continue;
		h[v] = h[u] + 1;
		p[v][0] = u;
		fod(j,1,lg2[n]){
			p[v][j] = p[p[v][j-1]][j-1];
			pq[v][j] = merge(pq[v][j-1], pq[p[v][j-1]][j-1]);
		}
		if(u == 1) dfs(v,u,v);
		else dfs(v,u,branch);
	}
}
int lca(int u, int v){
    if (h[u] < h[v]) swap(u,v);
    int k = h[u] - h[v];
    for(int j = 0; (1 << j) <= k; j++){
    	if(k & (1 << j)) u = p[u][j];
    }
    if (u == v) return u;
    int d = lg2[h[u]];
    fok(j,d,0) if (p[u][j] != p[v][j]){
        u = p[u][j]; v = p[v][j];
    }
    return p[u][0];
}
multis get(int u, int k){
	multis res;
    // int k = h[u] - h[cha];
    for(int j = 0; (1 << j) <= k; j++) if(k & (1 << j)){
    		res = merge(res, pq[u][j]);
            u = p[u][j];
    }
    return res;
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
	cin >> n >> m >> q;
	fod(i,1,n-1){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	fod(i,1,m){
		cin >> c[i];
		pq[c[i]][0].push(i);
	}
	lg2[1] = 0;
	fod(i,2,n) lg2[i] = lg2[i/2] + 1;
	dfs(1,0,0);
	while(q--){
		int u, v, a;
		cin >> u >> v >> a;
		int x = lca(u,v);
		multis ms1, ms2;
		ms1 = merge(ms1,get(u,h[u] - h[x]));
		ms2 = merge(ms2,get(v,h[v] - h[x] + 1));
		multis res = merge(ms1,ms2);
		int id = 0;
		while(id < a and res.a[id] <= m) id++;
		cout << id << " ";
		fod(i,0,id-1) cout << res.a[i] << " ";
		cout << el;
	}
	kill();
}

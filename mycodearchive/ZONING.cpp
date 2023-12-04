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
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
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
const int MOD = 1e9 + 7;
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e6 + 5;
int n, m, power[base], par[base], f[base], dd[base];
vector <int> adj[base], deg, x;
vector <ii> ping;
set <ii> s;
int find(int u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
}
void join(int u, int v) {
    int paru = find(u), parv = find(v);
    if (paru == parv) return;
    par[parv] = paru;
    f[paru] += f[parv];
}
void del(){
	ii v = *s.begin();
	deg.pb(v.fi);
	x.pb(v.se);
	int u = v.se;
	dd[u] = 1;
	for(int k : adj[u]) if(!dd[k]){
		s.erase({power[k],k});
		power[k]--;
		s.insert({power[k],k});
	}
	s.erase({power[u], u});
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(".inp", "r")){
		freopen(".inp", "r", stdin);
	    freopen(".out", "w", stdout);
	}
	else if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n >> m;
	fod(i,1,m){
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	int res = -1e18;
	fod(i,1,n) par[i] = i;
	fod(i,1,n) power[i] = adj[i].size();
	fod(i,1,n) s.insert({power[i],i});
	fod(i,1,n) f[i] = 1;
	fod(i,1,n) del();
	memset(dd ,0 , sizeof dd);
	reverse(deg.begin(), deg.end());
	reverse(x.begin(), x.end());
	memset(dd,0,sizeof dd);
	fod(i,0,x.size() - 1){
		int u = x[i];
		dd[u] = 1;
		for(int v : adj[u]) if(dd[v] == 1){
			join(u,v);
			// cout << deg[i] << " " << f[find(u)] << endl;
			res = max(res, deg[i] * (f[find(u)]));
		}
	}
	cout << res;
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "Code now ->قَمَر \n";
	return 0;
}

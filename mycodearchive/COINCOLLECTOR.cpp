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
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e6 + 5;
int n, m, a[base], f[base], dd[base], h[base], low[base], num[base], stt = 0, res = 0, ans = 0, tp[base], w[base], vao[base];
vector <int> adj[base], inp[base];
vector <int> g[base];
stack <int> st;
void tj(int u){
	stt++;
	low[u] = num[u] = stt;
	st.push(u);
	for(int v : adj[u]){
		if(dd[v]) continue;
		if(num[v] != 0) low[u] = min(low[u], num[v]);
		else{
			tj(v);
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
			// w[res] += a[x];
		}while(x != u);
	}
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
	fod(i,1,n) cin >> a[i];
	fod(i,1,m){
		int u,v; cin >> u >> v;
		adj[u].pb(v);
		// adj[v].pb(u);
	}
	fod(i,1,n) if(num[i] == 0) tj(i);
	fod(i,1,n){
		w[tp[i]] += a[i];
		int u = tp[i];
		for(int pp : adj[i]){
			int v = tp[pp];
			if(u != v){
				vao[v]++;
				g[u].pb(v);
			}
		}
	}
	queue <int> q;
	fod(i,1,res){
		if(vao[i] == 0) q.push(i);
	}
	while(q.size()){
		int u = q.front();
		q.pop();
		f[u] += w[u];
		ans = max(ans, f[u]);
		for(int v : g[u]){
			vao[v]--;
			f[v] = max(f[v], f[u]);
			if(vao[v] == 0) q.push(v);
		}
	}
	cout << ans;
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "Code now ->قَمَر \n";
	return 0;
}
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
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 5e5 + 5;
// dont use write like write("abc"). use it like write(x). x is the string variable
// dont use write like write(5). use it like write((int) 5). write(1e18) or any other float variables is fine
int n, m, a[base], start, mark[base], p;
int dd[base], num[base], low[base], stt = 0, res = 0, tp[base], vao[base], need = 0;
ll dp[base], weight[base];
stack <int> revtopo;
vector <int> adj[base], g[base], inp[base];
stack <int> s;
void dfs(int u){
	stt++;
	num[u] = low[u] = stt;
	s.push(u);
	for(int v: adj[u]) if(dd[v]==0){
		if(num[v]!=0)	low[u]=min(low[u],num[v]);
		else {
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
	}
	ll x;
	if(low[u]==num[u]){
		res++;
		do{
			x=s.top();
			s.pop();
			tp[x]=res;
			weight[res] += a[x];
			// cout << res << " ";
			dd[x]=1;
		} while(x!=u);
	}
}
void DPP(int u) {
    dd[u] = 1;
    for (auto v : g[u]){
    	if(!dd[v]){
    		// cout << u << " " << v << endl;
    		DPP(v);
    	}
    }
    revtopo.push(u);
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
		int u,v;
		cin >> u >> v;
		inp[v].pb(u);
		adj[u].pb(v);
	}
	fod(i,1,n) cin >> a[i];
	int xp;
	cin >> start >> xp;
	fod(i,1,xp){
		int u; cin >> u;
		mark[u] = 1;
	}
	fod(i,1,n){
		if(num[i] == 0) dfs(i);
	}
	fod(i,1,n){
		for(int z : inp[i]){
			int u = tp[i], v = tp[z];
			if(u == v) continue;
			vao[v]++;
			g[v].pb(u);
			// cout << u << " " << v << endl;
		}
	}
	fod(i,1,res) dd[i] = 0;
	fod(i,1,res) if (!dd[i]) DPP(i);
    ll ans = 0;
    dp[tp[start]] = weight[tp[start]];
    while(revtopo.top() != tp[start]){
    	revtopo.pop();
    }
    while(revtopo.size()){
    	int u = revtopo.top(); revtopo.pop();
    	for (auto v : g[u]) dp[v] = max(dp[v], dp[u] + weight[v]);
    }
	fod(i,1,n)if(mark[i]){
		ans = max(ans, dp[tp[i]]);
	}
	cout << ans;
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n";
	return 0;
}

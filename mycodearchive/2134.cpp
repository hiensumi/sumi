// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#pragma GCC optimize("O3")
#include "bits/stdc++.h"
using namespace std; 
// #define            int  long long
#define             ll  long long 
#define             db  double 
#define             ve  vector 
#define             vi  vector<int>
#define            vll  vector<ll>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            pii  pair<int,int>
#define            pll  pair<ll,ll>
#define             mp  make_pair 
#define             fi  first 
#define             se  second
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
#define     fod(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    fok(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define         all(a)  a.begin(),a.end()  
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        mask(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define pra(a,n) fod(_i,1,n)cout<<a[_i]<<el;cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<el; cout<<el; 
#define DEBUG(a) cout << #a << " = " << a << el;
struct point{int x, y;};
struct edge{int u, v, c;};
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "Etnallirb Anul\n"; exit(0);}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
#define name ""
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 2e5 + 5, INF = 1e18, multitest = 0, endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n, q, val[base], par[base], h[base], sz[base], head[base];
int in[base], out[base], timedfs = 0;
ve <vi> g;
template<class T> struct Seg {
    const T ID = -1; T comb(T a, T b) { return max(a,b); }
    int n; vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T get(int l, int r) {	// max on interval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};
Seg <int> ST;
// hld 
void dfs(int u, int p){
	sz[u] = 1;
	for(int v : g[u]) if(v != p){
		h[v] = h[u] + 1;
		par[v] = u;
		dfs(v,u);
		sz[u] += sz[v];
	}
}
void dfs_hld(int u, int p, int r){
	in[u] = ++timedfs;	
	head[u] = r;
	int heavy = -1;
	for(int v : g[u]){
		if(v != p){
			if(heavy == -1 or sz[v] > sz[heavy]) heavy = v;
		}
	}
	if(heavy == -1) return;
	dfs_hld(heavy,u,r);
	for(int v : g[u])if(v != p){
		if(v != heavy) dfs_hld(v,u,v);
	}
}
void inp(){
	cin >> n >> q;
	fod(i,1,n) cin >> val[i];
	g.resize(n + 1);
	fod(i,1,n-1){
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0);
	dfs_hld(1,0,1);
}

namespace sub1{
	int query(int u, int v){
		int res = 0;
		while(head[u] != head[v]){
			if(h[head[u]] < h[head[v]]) swap(u,v);
			int ret = ST.get(in[head[u]], in[u]);
			u = par[head[u]];
			maxi(res, ret);
		}
		
		if(h[u] < h[v]) swap(u,v);
		// assert(in[v] <= in[u]);
		int ret = ST.get(in[v],in[u]);
		maxi(res, ret);
		
		return res;
	}
    void solve(){
    	ST.init(n + 1);
		fod(i,1,n) ST.upd(in[i], val[i]);
		while(q--){
			int type; cin >> type;
			if(type == 1){
				int x, v; cin >> x >> v;
				ST.upd(in[x], v);
			}
			else{
				int u, v; cin >> u >> v;
				cout << query(u,v) << " ";
			}
		}
    }	
}
namespace sub2{
	
	void solve(){
		
	}
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); srand(time(0)); 
    if(fopen(name".inp", "r")){
      freopen(name".inp", "r", stdin);
      freopen(name".out", "w", stdout);
    }
    int Test = 1; if(multitest) cin >> Test;
    init();
    while(Test-- or endless){
        inp();
        sub1 :: solve();
        sub2 :: solve();
    }
    kill();
}


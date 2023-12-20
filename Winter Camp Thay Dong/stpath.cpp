// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#include "bits/stdc++.h"
using namespace std; 
#define            int  long long
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
struct point{int x, y;};
struct edge{int u, v, c;};
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
#define name ""
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e5 + 5, INF = 1e18, multitest = 0, endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n, m, q, lab[base], f[base], h[base];
ve <pii> g[base];
void inp(){
	cin >> n >> m >> q;
	fod(i,1,m){
		int u, v, c; cin >> u >> v >> c;
		g[u].pb(mp(v,c));
		g[v].pb(mp(u,c));
	}
}

namespace sub1{
   	int dd[base], par[base][21], LG[base];
   	vi bad;
   	void dfs(int u, int p){
   		par[u][0] = p;
		fod(j,1,LG[n]){
			par[u][j] = par[par[u][j-1]][j-1];
		}
   		dd[u] = 1;
		for(pii x : g[u]){
			int v = x.fi, w = x.se;
			if(v == p) continue;
			if(dd[v]){
				bad.pb(u);
				bad.pb(v);
				continue;	
			}
			f[v] = f[u] + w;
			h[v] = h[u] + 1;
			dfs(v,u);
		}
   	}
   	int lca(int u, int v){
		if(h[u] < h[v]) swap(u,v);
		int k = h[u] - h[v];
		fod(j,0,LG[n]) if(k & mask(j)) u = par[u][j];
		if(u == v) return u;
		int d = LG[h[u]];
		fok(j,d,0) if(par[u][j] != par[v][j]) u = par[u][j], v = par[v][j];
		return par[u][0];
	}
	int dis[51][base], used[base];
	void dji(int s, int *dis){
		queue <int> q;
	    fod(i,1,n) dis[i] = 1e18, used[i] = 0;
	    q.push(s);
	    dis[s] = 0;
	    used[s] = 1;
	    while (!q.empty()) {
	        int u = q.front();
	        q.pop();
	        used[u] = 0;
	        for(auto v : g[u]) {
	            int to = v.fi, w = v.se;
	            if (dis[to] > dis[u] + w) {
	                dis[to] = dis[u] + w;
	                if (!used[to]) {
	                    q.push(to);
	                    used[to] = 1;
	                }
	            }
	        }
	    }
	}
    void solve(){
    	fod(i,2,n) LG[i] = LG[i/2] + 1;
    	dfs(1,0);
    	
    	uni(bad);
    	int sz = SZ(bad) - 1;
    	
    	fod(i,0,sz) dji(bad[i], dis[i]);
    	
    	while(q--){
    		int u, v; cin >> u >> v;
    		int ans = f[u] + f[v] - 2 * f[lca(u,v)];
    		
    		fod(i,0,sz){d
    			mini(ans, dis[i][u] + dis[i][v]);
    		}
    		
    		cout << ans << el;
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
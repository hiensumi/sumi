// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
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
struct point{int x, y;};
struct edge{int u, v, c;};
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
#define name "TDL"
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e5 + 5, INF = 1e18, multitest = 0, endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n, m, U, V, f[base], h[base], par[base][21], LG[base];
ve <vi> g;
pii cons;
void inp(){
	cin >> n;
	g.resize(n + 1);
	fod(i,1,n-1){
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	cin >> m;
	if(m == 1) cin >> U;
	else cin >> U >> V;
}

namespace sub1{
 	void dfs(int u, int p){
 		for(int v : g[u]){
 			if(v == p) continue;
 			dfs(v,u);
 		}
 		sort(all(g[u]), [&](int x, int y){
 			return f[x] > f[y];
 		});
 		
 		int cnt = 0;
 		for(int v : g[u]){
 			if(v == p) continue;
 			if(mp(u,v) == cons or mp(v,u) == cons) continue;
 			cnt++;
 			maxi(f[u], f[v] + cnt);
  		}
 	}  
 	void DFS(int u, int p){
 		for(int v : g[u]){
 			if(v == p ) continue;
 			h[v] = h[u] + 1;
 			par[v][0] = u;
 			
 			
 			DFS(v,u);
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
	
	vi st;
	int calc(int pos){
		cons = mp(st[pos], st[pos+1]);
		
		int ans = 0;
		fod(i,1,n) f[i] = 0;
		dfs(U,0);
		maxi(ans, f[U]);
		
		fod(i,1,n) f[i] = 0;
		dfs(V,0);
		maxi(ans, f[V]);
		
		return ans;
	}
	int dist(int u, int v){
		int x = lca(u,v);
		return h[u] + h[v] - 2 * h[x];
	}
    void solve(){
    	fod(i,2,n) LG[i] = LG[i/2] + 1;
    	if(m == 1){
			dfs(U,0);
			cout << f[U] << el;
			kill();
		}
		else{
			DFS(1,0);
			fod(j,1,20) fod(i,1,n) par[i][j] = par[par[i][j-1]][j-1];
			fod(i,1,n) if(dist(U,i) + dist(i,V) == dist(U,V)) st.pb(i);
			
			sort(all(st), [&] (int a, int b){
				return dist(a,U) < dist(b,U);
			});
			
			if(SZ(st) == 2){
				cout << calc(0);
				kill();
			}
			
			// st.insert(st.begin(), 0);
			
			int l = 0, r = SZ(st) - 2, ans = 2e9;
			fod(i,1,80){
				if(l > r) break;
				int m1 = l + (r - l) / 3;
				int m2 = r - (r - l) / 3;
				
				int x1 = calc(m1), x2 = calc(m2);
				
				if(x1 < x2) r = m2;
				else l = m1;
				mini(ans, x1);
				mini(ans, x2);
			}
			
			fod(i,-5,5) if(l + i >= 0 and l + i <= SZ(st) - 2) mini(ans, calc(l + i));
			
			cout << ans;
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
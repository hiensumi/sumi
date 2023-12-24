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
#define name ""
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e6 + 5, INF = 1e18, multitest = 0, endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n, q,  LG[base];
ve <vi> g;
void inp(){
	cin >> n >> q;
	g.resize(n + 1);
	fod(i,1,n-1){
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	fod(i,2,2 * n) LG[i] = LG[i/2] + 1;
}

namespace sub1{
    int qr[base], a[base], b[base], h[base], in[base], out[base], tour[base], timeDFS = 0;
    pii mi[base][21]; 
	void dfs(int u, int p) {
	    tour[++timeDFS] = u;
	    in[u] = timeDFS;
	    out[u] = timeDFS;
	    for(int v : g[u]) if(v != p){
	    	h[v] = h[u] + 1;
	    	dfs(v,u);
	    }
	    if(u != 1){
	    	tour[++timeDFS] = p;
	    	out[p] = timeDFS;
	    }
	}
    vi old; int dd[base];
    pii get(int l, int r){
    	int k = LG[r - l + 1];
    	return min(mi[l][k], mi[r - mask(k) + 1][k]);
    }
    int lca(int u, int v){
    	if(in[u] > in[v]) swap(u,v);
    	// cout << in[u] << " " << in[v] << el;
    	return tour[get(in[u], in[v]).se];
    }
    int dist(int u, int v){
    	return h[u] + h[v] - 2 * h[lca(u,v)];
    }
    void solve(){
    	dfs(1,0);
    	fod(i,1,q) cin >> qr[i], dd[qr[i]] = 1; fod(i,1,n) if(dd[i] == 0) old.pb(i);
    	// fod(i,1,timeDFS){
    		// cout << tour[i] << " ";
    	// }
    	// cout << el;
    	fod(i,1,timeDFS){
    		// cout << h[tour[i]] << " ";
    		mi[i][0] = {h[tour[i]], i};
    	}
    	fod(j,1,LG[timeDFS]) fod(i,1,timeDFS - mask(j) + 1){
    		mi[i][j] = min(mi[i][j-1], mi[i + mask(j - 1)][j-1]);
    	}
    	// cout << el;
    	// cout << lca(3,5) << el;
    	// kill();
    	
    	if(q == 1) return void(cout << 0 << " " << 0 << el);
    	int x = qr[1], y = qr[2];
    	int cur = dist(x,y); b[1] = 0; b[2] = cur;	
    	fod(i,3,q){
    		int u = qr[i];
    		int n1 = dist(x,u), n2 = dist(y,u);
    		int ma = max({n1,n2,cur});
    		if(ma == n1){
    			y = u;
    			cur = n1;
    		}
    		else if(ma == n2){
    			x = u;
    			cur = n2;
    		}
    		
    		b[i] = ma;
    	}
    	cur = 0;
    	x = old.back(), y = 0;
    	for(int z : old) if(maxi(cur, dist(x,z))) y = z;
    	cur = 0;
    	for(int z : old) if(maxi(cur, dist(y,z))) x = z;
    	
    	a[q] = cur;
    	fok(i,q-1,1){
    		int u = qr[i+1];
    		int n1= dist(x,u), n2 = dist(y,u);
    		int ma = max({n1,n2,cur});
    		if(ma == n1){
    			y = u;
    			cur = n1;
    		}
    		else if(ma == n2){
    			x = u;
    			cur = n2;
    		}
    		
    		a[i] = ma;
    	}
    	fod(i,1,q) cout << a[i] << " " << b[i] << el;
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
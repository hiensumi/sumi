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
#define pra(a,n) fod(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 
struct point{int x, y;};
struct edge{int u, v, c,id;};

//int find(int u){if (lab[u] < 0) return u; return lab[u] = find(lab[u]);}
//bool join(int u, int v){u = find(u);v = find(v);if(u == v) return 0;if(lab[u] > lab[v]) swap(u,v);lab[u] += lab[v];lab[v] = u; return 1;}
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
#define name ""
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 3e5 + 5, INF = 1e18, multitest = 0; int endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n, m;
edge e[base], tmp[base];
void inp(){
	cin >> n >> m;
	fod(i,1,m){
		int u, v, c; cin >> u >> v >> c;
		e[i] = edge{u,v,c,i};
		tmp[i] = edge{u,v,c,i};
	}
}

namespace sub1{
   	int lab[base];
   	int find(int u){
   		return (lab[u] < 0) ? u : lab[u] = find(lab[u]);
   	}
   	bool join(int u, int v){
   		u = find(u); v = find(v);
   		if(u == v) return 0;
   		if(lab[u] > lab[v]) swap(u,v);
   		lab[u] += lab[v];
   		lab[v] = u;
   		return 1;
   	}
   	bool cmp(edge a, edge b){
   		return a.c < b.c;
   	}
    void solve(){
    	sort(e + 1, e + m + 1, cmp);
    	
    	fod(i,1,m){
    		fod(i,1,n) lab[i] = -1;
    		ll res = 0, cnt = 0;
    		fod(j,1,m) if(e[j].id != i){
    			if(join(e[j].u, e[j].v)) res += 1ll * e[j].c, cnt++;
    		} 
    		
    		if(cnt == n- 1) cout << res << el;
    		else cout << -1 << el;
    	}
    }	
}
namespace sub2{
	int lab[base], dd[base];
   	int find(int u){
   		return (lab[u] < 0) ? u : lab[u] = find(lab[u]);
   	}
   	bool join(int u, int v){
   		u = find(u); v = find(v);
   		if(u == v) return 0;
   		if(lab[u] > lab[v]) swap(u,v);
   		lab[u] += lab[v];
   		lab[v] = u;
   		return 1;
   	}
   	bool cmp(edge a, edge b){
   		return a.c < b.c;
   	}
   	int h[base];
   	ve <ve <pii> > g;
    
    int tour[base], in[base], out[base], timeDFS = 0, LG[base];
    pii mi[base][21]; 
	void dfs(int u, int p) {
	    tour[++timeDFS] = u;
	    in[u] = timeDFS;
	    out[u] = timeDFS;
	    for(auto [v,w] : g[u]) if(v != p){
	    	h[v] = h[u] + 1;
	    	dfs(v,u);
	    }
	    if(u != 1){
	    	tour[++timeDFS] = p;
	    	out[p] = timeDFS;
	    }
	}
    pii get(int l, int r){
    	int k = LG[r - l + 1];
    	return min(mi[l][k], mi[r - mask(k) + 1][k]);
    }
    int lca(int u, int v){
    	if(in[u] > in[v]) swap(u,v);
    	// cout << in[u] << " " << in[v] << el;
    	return tour[get(in[u], in[v]).se];
    }
    
    void solve(){
    	fod(i,2,3e5) LG[i] = LG[i/2] + 1;
    	sort(e + 1, e + m + 1, cmp);
		
		ll res = 0;
		ve <edge> bad;
		fod(i,1,n) lab[i] = -1;
		g.resize( n + 1);	
		fod(i,1,m){
			if(join(e[i].u, e[i].v)){
				// cout << e[i].u << " " << e[i].v << " " << e[i].c << el;
				 res = 1ll * res + 1ll * e[i].c, dd[e[i].id] = 1, g[e[i].u].pb(mp(e[i].v, e[i].c)), g[e[i].v].pb(mp(e[i].u, e[i].c));
			}
			else bad.pb(e[i]);
		}
		
		dfs(1,0);
		fod(i,1,timeDFS){
    		mi[i][0] = {h[tour[i]], i};
    	}
    	fod(j,1,LG[timeDFS]) fod(i,1,timeDFS - mask(j) + 1){
    		mi[i][j] = min(mi[i][j-1], mi[i + mask(j - 1)][j-1]);
    	}
    	
		fod(i,1,m){
			if(!dd[i]) cout << res << el;
			
			else {
				int paru = tmp[i].u, parv = tmp[i].v;
				if(h[paru] > h[parv]) swap(paru,parv);
				
				ll ans = 1ll* res - 1ll * tmp[i].c;
				int miss = 2e9;
				
				for(edge x : bad){
					int u = x.u, v = x.v, c = x.c;
					
					if(lca(parv, v) == parv and lca(parv, u) != parv){
						mini(miss, c);
					}
				
					swap(u,v);
					
					if(lca(parv, v) == parv and lca(parv, u) != parv) {
						mini(miss, c);
					}
				}
				
				if(miss == INF) cout << -1 << el;
				else cout << 1ll * ans + 1ll * miss << el;
			}
		}
	}
}
namespace sub3{
	
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
        // sub2 :: solve();
        if(n <= 200 and m <= 500) sub1 :: solve();
       	else if(m <= n + 100) sub2 :: solve();
        if(endless) endless--;
    }
    kill();
}
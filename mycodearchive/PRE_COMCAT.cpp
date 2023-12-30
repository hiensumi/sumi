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
struct edge{int u, v, c;};

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
const ll base = 1e6 + 5, INF = 1e18, multitest = 0; int endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n;
ve <vi> g;
bool c1 = 1;
ve <edge> e;
void inp(){
	cin >> n;
	g.resize(n + 1);
	fod(i,1,n-1){
		int u, v; cin >> u >> v;
		if(v - u != 1) c1 = 0;
		g[u].pb(v);
		g[v].pb(u); 
		e.pb(edge{u,v,0});
	}
}

namespace sub1{
	int w[base], dd[base];
    void solve(){
    	int cur = n - 2 - (n % 2), diff = -2; 
    	fod(i,2,n){
    		w[i] = cur;
    		if(cur == 0){
    			cur = -1;
    			diff = 2;
    		}
    		cur += diff;
    	}
    	// fod(i,2,n) cout << w[i] << " ";
    	// cout << el;
    	int res = 0;
    	fod(i,1,n){
    		cur = 0;
    		fod(j,i + 1,n){
    			dd[w[j]] = 1;
    			while(dd[cur]) cur++;
    			res += cur;
    			// cout << i << " " << j << " " << cur << el;		
    		}
    		
    		fod(j,0,cur) dd[j] = 0;
    	}
    	
    	cout << res << el;
    }	
}
namespace sub2{
	int h[base], par[base][21];
	void dfs(int u, int p){
	    for(int v : g[u]) if(v != p){
	        h[v] = h[u] + 1;
	        par[v][0] = u;
	        fod(j,1,20) par[v][j] = par[par[v][j-1]][j-1];
	        dfs(v,u);
	    }
	}
	int lca(int u, int v){
	    if(h[u] < h[v]) swap(u,v);
	    int k = h[u] - h[v];
	    fok(j,20,0) if(k & mask(j)) u = par[u][j];
	    if(u == v) return u;
	    k = lg(h[u]);
	    fok(j,k,0) if(par[u][j] != par[v][j]) u = par[u][j], v = par[v][j];
	    return par[u][0];
	}
    int color[base], a[10][10], dd[10];
    int path(int u, int v){
        int x = lca(u,v);
        memset(dd, 0, sizeof dd);
        for(int i = u; i != x; i = par[i][0]){
            dd[a[i][par[i][0]]] = 1;
        }
        for(int i = v; i != x; i = par[i][0]){
            dd[a[i][par[i][0]]] = 1;
        }
        fod(i,0,10){
            if(dd[i] == 0) return i;
        }
    }
    int res = 0;
    void solve(){
        dfs(1,0);
        fod(i,1,n-1) color[i] = i - 1;
        do{
            memset(a , 0, sizeof a);
            fod(i,1,n-1){
                int u = e[i-1].u, v = e[i-1].v; 
                a[u][v] = color[i];
                a[v][u] = color[i];  
            }
            int ans = 0;
            fod(i,1,n) fod(j,i+1,n){
                ans += path(i,j);
            }
            maxi(res, ans);
        }while(next_permutation(color + 1, color + n));
    
        cout << res;
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
        if(c1) sub1 :: solve();
        else if(n <= 8) sub2 :: solve();
        if(endless) endless--;
    }
    kill();
}
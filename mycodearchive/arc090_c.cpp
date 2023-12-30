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
int n, m, S, T;
ve <ve<pii> >g;
ve <edge> hn;
void inp(){
	cin >> n >> m >> S >> T;
	g.resize(n + 1);
	fod(i,1,m){
		int u, v, c; cin >> u >> v >> c;
		g[u].pb(mp(v,c));
		g[v].pb(mp(u,c));
		hn.pb({u,v,c});
	}
}

namespace sub1{
	vi trace;
   	int dis[3][base], dp[3][base], vst[base];
	void dji(int *dis, int u){
		trace.clear();
		fod(i,1,n) dis[i] = INF, vst[i] = 0;
		priority_queue<pii> pq;
		dis[u] = 0;
		pq.push(mp(dis[u], u));
		while(!pq.empty()){
			int u = pq.top().se, val = -pq.top().fi;
			pq.pop();
			if(dis[u] < val or vst[u]) continue;
			vst[u] = 1;
			trace.pb(u);
			for(auto [v,w] : g[u]){
				if(mini(dis[v], dis[u] + w)){
					pq.push(mp(-dis[v], v));
				}
			}
		}
	}
	void calc(int *dp, int *dis, int u){
		dp[u] = 1;
		for(int u : trace){
			for(auto [v,w] : g[u]){
				if(dis[u] + w == dis[v]){
					(dp[v] += dp[u]) %= MOD;
				}
			}
		}
	}
    void solve(){
    	dji(dis[1], S);
    	calc(dp[1], dis[1], S);
    	
    	dji(dis[2], T);
    	calc(dp[2], dis[2], T);
    	
    	int res = (dp[1][T] % MOD * dp[2][S] % MOD + MOD) % MOD, D = dis[1][T];
    	
    	fod(i,1,n){
    		if(dis[1][i] == dis[2][i] and dis[1][i] + dis[2][i] == D) (res -= (bpow(dp[1][i],2) * bpow(dp[2][i],2)) % MOD - MOD) %= MOD;
    	}
    	
    	for(auto [u,v,c] : hn){
    		if(dis[1][u] + dis[2][v] + c == D and dis[1][u] * 2 < D and dis[2][v] * 2 < D) (res -= (bpow(dp[1][u],2) * bpow(dp[2][v],2)) % MOD - MOD) %= MOD;
    		swap(u,v);
    		if(dis[1][u] + dis[2][v] + c == D and dis[1][u] * 2 < D and dis[2][v] * 2 < D) (res -= (bpow(dp[1][u],2) * bpow(dp[2][v],2)) % MOD - MOD) %= MOD;
    	}
    	
    	cout << res << el;
    	
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
        if(endless) endless--;
    }
    kill();
}
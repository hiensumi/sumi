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
int n, m, k;
pii S, T;
ve <pii> dir = { mp(0,0), mp(-1,0), mp(1,0), mp(0,-1), mp(0,1)};
ve < ve< ve<ld > > > dp;
ve < ve< ve<bool> > > dd;
ve < vi > a;
void inp(){
	cin >> n >> m >> k;
	dp.resize(n + 1, ve <ve<ld>>(m + 1, ve<ld>(6,INF)));
	dd.resize(n + 1, ve <ve<bool>>(m + 1, ve<bool>(6)));
	a.resize(n + 1, vi (m + 1));
	cin >> S.fi >> S.se >> T.fi >> T.se;
	fod(i,1,n) fod(j,1,m){
		char c; cin >> c;
		a[i][j] = (c == '@');
	}
}

namespace sub1{
	struct DL{
		int x, y, cd;
		DL(int x, int y, int cd){
			this->x = x;
			this->y = y;
			this->cd = cd;	
		}
	};
	#define pdl pair<ld,DL>
	struct cmp{
		bool operator() (pdl a, pdl b){
			return a.fi > b.fi;
		}
	};
	bool nt(int x, int y){
		return 1 <= x and x <= n and 1 <= y and y <= m;
	}
	int rot(int dir){
		if(dir == 4) return 1;
		if(dir == 1) return 3;
		if(dir == 3) return 2;
		if(dir == 2) return 4;
	}
   	void dji(int u, int v){
   		priority_queue <pdl, ve <pdl>, cmp> pq;
   		fod(i,1,4){
   			pq.push(mp(0.0, DL(u,v,i)));
   			dp[u][v][i] = 0.0;
   		}
   		
   		while(!pq.empty()){
   			pdl X = pq.top(); pq.pop();
   			ld cost = X.fi; DL Y = X.se;
   			int u = Y.x, v = Y.y, cd = Y.cd;
   			// cout << u << " " << v << el;
   			if(dp[u][v][cd] != cost or dd[u][v][cd]) continue;
   			dd[u][v][cd] = 1;
 			int sd = cd;
 			int x = u + dir[sd].fi, y = v + dir[sd].se;
 			if(nt(x,y) and a[x][y] == 0){
 				if(mini(dp[x][y][sd], dp[u][v][cd] + (ld) 1 / k)){
 					pq.push(mp(dp[x][y][sd], DL(x,y,sd)));
 				}
 			}
 			
 			fod(nd,1,4) if(nd != sd){
 				int x = u + dir[nd].fi, y = v + dir[nd].se;
 				// cout << x << " " << y << el;
	 			if(nt(x,y) and a[x][y] == 0){
	 				if(mini(dp[x][y][nd], ceil(dp[u][v][cd]) + (ld) 1 / k)){
	 					pq.push(mp(dp[x][y][nd], DL(x,y,nd)));
	 				}
	 			}
 			}
 			  			
   		}
   	}
    void solve(){
    	dji(S.fi, S.se);
    	int res = INF;
    	fod(i,1,4){
    		mini(res, (int) ceil(dp[T.fi][T.se][i]));
    		// cout << setprecision(6) << fixed << dp[T.fi][T.se][i] << el;
    	}
    	if(res != INF) cout << res;
    	else cout << -1;
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
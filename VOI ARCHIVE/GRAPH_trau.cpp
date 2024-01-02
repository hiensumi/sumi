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
#define name "GRAPH"
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e6 + 5, INF = 1e18, multitest = 0; int endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n, b, a[base];
void inp(){
	cin >> n >> b;
	fod(i,1,n) cin >> a[i];
}

namespace sub1{
	struct DL{ int u, v ; } ;
   	ve <DL> zx;
   	map <vi, int> diff;
    void solve(){
    	int res= 0 ;
    	fod(i,1,n) fod(j,i+1,n) zx.pb(DL{i,j});
    	
    	int tt = mask(SZ(zx)) - 1;
    	fod(x,0,tt){
    		vi f; f.resize(n + 1);
    		vi deg; deg.resize(n + 1);
    		for(int tmp = x; tmp ; tmp ^= (tmp & -tmp)){
    			int i = ctz(tmp) ;
    			int u = zx[i].u, v = zx[i].v;
    			if(v < u) f[u]++;
    			else f[v]++;
    			deg[u]++; deg[v]++;
    		}
    		bool ch = 0;
    		fod(i,1,n){
    			if(deg[i] > b){ch = 1; break; }
    			if(f[i] != a[i] and a[i] != -1){
    				ch = 1; break;
    			}
    		}
    		
    		if(ch == 1){diff[f] = 2; continue;}
    		if(ch == 0 and diff[f] == 0) diff[f] = 1;	
    	}
    	
    	for(pair<vi,int> x : diff){
    		if(x.se == 1){
    			res++;
    		}
    	}
    	cout << res;
    }	
}
namespace sub2{
	bool calc(){
		vi max_deg; max_deg.resize(n + 1);
		int cnt = 0;
		fok(i,n,1) max_deg[i] = a[i] + cnt, cnt += (a[i] > 0);
		fod(i,1,n) if(max_deg[i] > b) return 0;
		return 1;
	}
	void solve(){
		int pos = - 1;
		fod(i,1,n) if(a[i] == -1) pos = i;
		int res = 0;
		fod(i,0,pos - 1){
			a[pos] = i;
			res += calc();
		}
		
		cout << res;
	}
}
namespace sub3{
	int dp[2005][2005];
	
	void solve(){
		
		fok(i,n,1) fok(k,n - i, 0){
			if(a[i] > 0){
				if(a[i] + k <= b and a[i] < i) dp[i-1][k + 1] = dp[i][k];
				continue;
			}
			else if(a[i] == 0){
				dp[i-1][k] = dp[i][k];	
			}
			if(k <= b) dp[i-1][k] += dp[i][k], dp[i-1][k + 1] = dp[i][k] + min(i - 1, b - k);
		}	
		int res = 0;
		fod(i,0,n-1) res += dp[1][i];
		
		cout << res << el;
	}
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); srand(time(0)); 
    if(fopen(name".inp", "r")){
      freopen(name".inp", "r", stdin);
      freopen(name".ans", "w", stdout);
    }
    int Test = 1; if(multitest) cin >> Test;
    init();
    while(Test-- or endless){
        inp();
        sub1 :: solve();
        // if(n <= 6) sub1 :: solve();
        // else if(n <= 200) sub2 :: solve();
        if(endless) endless--;
    }
    kill();
}
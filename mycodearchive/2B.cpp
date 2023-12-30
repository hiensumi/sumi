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
int n, a[1001][1001];
pii pos = mp(-1,-1);
void inp(){
	cin >> n;
	fod(i,1,n) fod(j,1,n) cin >> a[i][j];
	fod(i,1,n) fod(j,1,n) if(a[i][j] == 0){
		pos = mp(i,j);
	}
}

namespace sub1{
	int dp[2][1001][1001];
	char trace[2][1001][1001];
    pii cnt(int x){
    	int c2 = 0, c5 = 0;
    	while(x % 2 == 0 and x) c2++, x /= 2;
    	while(x % 5 == 0 and x) c5++, x /= 5;
     	return mp(c2,c5);
     }
    void solve(){
    	memset(dp, 0x3f, sizeof dp);
    	dp[0][0][1] = dp[1][1][0] = 0;
    	fod(i,1,n) fod(j,1,n) if(a[i][j] != 0){
    		auto [c2, c5] = cnt(a[i][j]);
    		if(mini(dp[0][i][j], dp[0][i-1][j])) trace[0][i][j] = 'D';
    		if(mini(dp[0][i][j], dp[0][i][j-1])) trace[0][i][j] = 'R';
    		
    		if(mini(dp[1][i][j], dp[1][i-1][j])) trace[1][i][j] = 'D';
    		if(mini(dp[1][i][j], dp[1][i][j-1])) trace[1][i][j] = 'R';
    		
    		dp[0][i][j] += c2;
    		dp[1][i][j] += c5;
    	}
    	
    	int res = min(dp[0][n][n], dp[1][n][n]);
    	if(res > 0 and pos.fi != -1){
    		cout << 1 << el;
    		fod(i,1,pos.fi-1) cout << 'D';
    		fod(j,1,pos.se-1) cout << 'R';
    		fod(i,1,n-pos.fi) cout << 'D';
    		fod(j,1,n-pos.se) cout << 'R';
    		kill();
    	}
    	
    	cout << res << el;
    	string ret = "";
    	int curx = n, cury = n, type = (dp[0][n][n] < dp[1][n][n] ? 0 : 1);
    	
    	while(curx > 1 or cury > 1){
    		char dir = trace[type][curx][cury];
    		ret.pb(dir);
    		if(dir == 'D') curx--;
    		else cury--;
    	}
    	reverse(all(ret));
    	
    	cout << ret;
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
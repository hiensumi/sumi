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
#define DEBUG(x) cout << #x << " = " << x << el;
struct point{int x, y;};
struct edge{int u, v, c;};
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << " [ .... EtnallirB AnuL ...].\n"; exit(0);}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
#define name ""
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e6 + 5, INF = 1e18, multitest = 1, endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
// remember to reset value for multitestcase
int n, a[501][501], f[501][501], dp[501][501];
void inp(){
	cin >> n;
	fod(i,1,n) fod(j,1,n) cin >> a[i][j], f[i][j] = f[i-1][j] + f[i][j-1] + a[i][j] - f[i-1][j-1];
}

void init(){} 
namespace sub1{
    int get(int u, int v, int x, int y){
    	return f[x][y] - f[u - 1][y] - f[x][v-1] + f[u-1][v-1];
    }
    int odd(int x){
    	return x & 1;
    }
    int even(int x){
    	return x % 2 == 0;
    }
    void solve(){
    	init();
    	fod(i,0,n) fod(j,0,n) dp[i][j] = 1;
    	
    	fod(i,1,n) fod(j,1,n){
    		int sumrow = get(i,1,i,j);
    		int sumcol = get(1,j,i,j);
    		
    		if(even(sumrow) and dp[i-1][j] == 1) dp[i][j] = 0;
    		if(even(sumcol) and dp[i][j-1] == 1) dp[i][j] = 0;
    	}
    	
    	if(dp[n][n] == 0) cout << "YES" << el;
    	else cout << "NO" << el;
    	
    	memset(a, 0, sizeof a);
    	memset(f, 0, sizeof f);
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
    while(Test-- or endless){
        inp();
        sub1 :: solve();
        sub2 :: solve();
    }
    kill();
}
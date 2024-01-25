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
const ll base = 1e6 + 5, INF = 1e18, multitest = 0, endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
// remember to reset value for multitestcase
int n, m, q, a[41][41], sum[41][41];
void inp(){
	cin >> n >> m >> q;
	fod(i,1,n) fod(j,1,m){
		char c; cin >> c;
		a[i][j] = c - '0';
		sum[i][j] =  sum[i-1][j] + a[i][j];
	}
}
int le[41][41][41]; // cạnh (i,k - j,k) có bao nhiêu cạnh bên trái(với 2 đầu i, j) có tổng bằng 0
int ri[41][41][41]; // định nghĩa giống trên 
int cnt[41][41][41];
void init(){
	fod(i,1,n) fod(j,i,n) fod(k,1,m){
		if(sum[j][k] - sum[i-1][k]){
			continue;
		}
		
		int d = 0; 
		while(k - d > 0 and sum[j][k - d] - sum[i-1][k - d] == 0) d++;
		le[i][j][k] = d;
	
		// DEBUG(d);
			
		d = 0;
		while(k + d < m + 1 and sum[j][k + d] - sum[i-1][k + d] == 0) d++;
		ri[i][j][k] = d;
		
		// DEBUG(d);
	}
	
	fod(i,1,n) fod(j,i,n) fod(k,1,m){
		cnt[i][j][k] = cnt[i][j][k-1] + (sum[j][k] - sum[i-1][k] == 0 ? le[i][j][k] : 0);
	}
} 
namespace sub1{
    int calc(int u, int v, int x, int y){
    	int res = 0;
    	fod(top,u,x) fod(bot,top,x){
    		res += cnt[top][bot][y] - cnt[top][bot][v - 1];
    		if(le[top][bot][v] > 0) res -= (le[top][bot][v] - 1) * min(y - v + 1, ri[top][bot][v]);
    	}
    	
    	return res;
    }
    void solve(){
    	init();	
    	
    	while(q--){
    		int u, v, x, y; cin >> u >> v >> x >> y;
    		
    		cout << calc(u,v,x,y) << el;
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
    
    while(Test-- or endless){
        inp();
        sub1 :: solve();
        sub2 :: solve();
    }
    kill();
}
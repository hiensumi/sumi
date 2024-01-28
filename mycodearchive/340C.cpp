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
#define DEBUG(x) cerr << #x << " = " << x << el;
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
int n, a[base];
void inp(){	
	cin >> n;
	fod(i,1,n) cin >> a[i];
}

void init(){} 
// each pairs appears (n - 1)! times
// (n - 1)! * (sum of arr) + (sum of all pairs) * (n - 1)!
// decominator =n! =>  (sum of arr + sum of all pairs) / n 

// a, b, c, d => 2(b-a) + 2(c-a) + 2(d-a) + 2(c-b) + 2(d-b) + 2(d-c)
// = 2b - 2a + 2c - 2a + 2d - 2a + 2c - 2b + 2d - 2b + 2d - 2c+ a[i]
// = -6a - 2b + 2c + 6d 

// a, b, c => 2(b - a) + 2(c - a) +  2(c - b)
// = 2b - 2a + 2c - 2a + 2c - 2b
// = -4a + 0b + 4c


namespace sub1{
    // int dd[10][10];
    void solve(){
    	init();
    	// do{
    		// fod(i,1,n) cerr << "|"<< a[i] << "-" << a[i - 1] << "|" << " + "[i < n];
    		// fod(i,1,n) dd[a[i]][a[i-1]]++;
    		// cerr << el;
    	// }while(next_permutation(a + 1, a + n + 1));
//     	
    	// fod(i,1,n) fod(j,1,n) if(i != j){
    		// cout << a[i] << " " << a[j] << " " << dd[a[i]][a[j]] << el;
    	// }
    
    	sort(a + 1, a + n + 1);
    	int res = 0;
    	int start = - 2 * (n - 1);
    	fod(i,1,n){
    		res = res + start * a[i] + a[i];
    		start += 4;
    	}
    	
    	while(1){
    		int x = gcd(res, n);
    		if(x == 1) break;
    		res /= x; n /= x;
    	}
    	
    	cout << res << " " << n << el;
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
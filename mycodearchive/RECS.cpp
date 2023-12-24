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
struct point{int x, y;};
struct edge{int u, v, c;};
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
#define name "RECS"
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e6 + 5, INF = 1e18, multitest = 1, endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
vi v[4];
void inp(){
	int x,y; 
	cin >> x >> y;
	v[1].pb(x); v[1].pb(y);
	cin >> x >> y;
	v[2].pb(x); v[2].pb(y);
	cin >> x >> y;
	v[3].pb(x); v[3].pb(y);
}

namespace sub1{
   	int calc(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3){
   		int y1 = 0, y2 = 0, y3 = 0;
   		int x1 = max({_x1,_x2,_x3});
   		if(_x1 == x1) _x1 = 0, y1 = _y1;
   		else if(_x2 == x1) _x2 = 0, y1 = _y2;
   		else if(_x3 == x1) _x3 = 0, y1 = _y3;
   		int x2 = max({_x1,_x2,_x3});
   		if(_x1 == x2) _x1 = 0, y2 = _y1;
   		else if(_x2 == x2) _x2 = 0, y2 = _y2;
   		else if(_x3 == x2) _x3 = 0, y2 = _y3;
   		int x3 = max({_x1,_x2,_x3});
		if(_x1 == x3) _x1 = 0, y3 = _y1;
   		else if(_x2 == x3) _x2 = 0, y3 = _y2;
   		else if(_x3 == x3) _x3 = 0, y3 = _y3;	
   		int ans = 0;
   		// cout << x1 << " " << y1 << el;
   		// cout << x2 << " " << y2 << el;
   		// cout << x3 << " " << y3 << el;
   		// cout << el;
   		if(x1 >= x2 + x3){
   			int y = max(y2,y3) + y1;
   			if(ans == 0) ans = x1 * y;
   		}
   		else{
   			int y = max(y2, y1 + y3);
   			int x = x1 + x2;
   			if(ans == 0) ans = x * y;
   			else mini(ans, x * y);
   			y = max(y3, y1 + y2);
   			x = x1 + x3;
   			if(ans == 0) ans = x * y;
   			else mini(ans, x * y);
   			
   			x = x2 + x3;
   			y = y1 + max(y2,y3);
   			if(ans == 0) ans = x * y;
   			else mini(ans, x * y);
   			
   		}
   		int y = max({y1,y2,y3});
		int x = x1 + x2 + x3;
		if(ans == 0) ans = x * y;
		else mini(ans, x * y);
		
		x = max({x1,x2,x3});
		y = y1 + y2 + y3;
		if(ans == 0) ans = x * y;
		else mini(ans, x * y);
   		return ans;
   	}
    void solve(){
    	sort(all(v[1]));
    	sort(all(v[2]));
    	sort(all(v[3]));
    	int res = 0;
    	do{
    		do{
    			do{
    				int ret = calc(v[1][0],v[1][1], v[2][0], v[2][1], v[3][0], v[3][1]);
    				if(res == 0) res = ret;
    				else mini(res, ret);
    				// mini(res, calc(v[1][0],v[1][1], v[2][0], v[2][1], v[3][0], v[3][1]));	
    						
    			}while(next_permutation(all(v[3])));
    		}while(next_permutation(all((v[2]))));
    	}while(next_permutation(all(v[1])));
    
    	cout << res << el;
    	v[1].clear();
    	v[2].clear();
    	v[3].clear();
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